/*
 * Main.cpp
 *
 *  Created on: Jun 9, 2020
 *      Author: trodenberg
 */

 #include <SFML/Graphics.hpp>
 #include <iostream>
 #include <string>
 #include <vector>
 #include <random>

const std::string TEXTURES_PATH = "../textures";
const std::vector<std::string> TEXTURE_NAMES = {"Mine.jpg",
    "rocky_field.jpeg"};

enum txtrs { MINE, ROCKFIELD  };
std::vector<sf::Texture*> textures;

//create window
const int windowX = 800;
const int windowY = 600;
sf::RenderWindow window(sf::VideoMode(windowX, windowY), "My window");

auto rng = std::default_random_engine();

const int gridRows = 10;
const int gridCols = 10;
int gridX = 0;
int gridY = 0;
int gridSizeX = windowX;
int gridSizeY = windowY;
sf::Sprite grid[gridCols][gridRows];

int gridTemplate[gridCols][gridRows];

//-------------------------------------------------------------------------
void rescaleSprite(sf::Sprite* sprite, sf::Vector2f size);


class Field {
public:
    //sf::Vector2u gridPos;
    bool swapped;
    sf::Sprite backside;

    Field(){ swapped = false; }

    virtual bool isClicked(sf::Vector2f pos);
        //return backside.getGlobalBounds().contains(pos);

    virtual void drawField(sf::RenderWindow* window);

};

class EmptyField: public Field{
public:
    sf::RectangleShape *front;

    EmptyField(sf::Vector2f pos, sf::Vector2f size){
        front = new sf::RectangleShape(pos);
        front->setSize(size);
    }

    ~EmptyField(){
        delete front;
    }

    bool isClicked(sf::Vector2f pos){
        return backside.getGlobalBounds().contains(pos);
    }

    void drawField(sf::RenderWindow* window){
        (swapped) ? window->draw(*front) : window->draw(backside);
    }
};

class MineField: public Field{
public:
    sf::Sprite *front;

    MineField(sf::Vector2f pos, sf::Vector2f size){
        front = new sf::Sprite();
        front->setTexture(*textures[0]);
        front->setPosition(pos);
        rescaleSprite(front, size);
    }

    ~MineField(){
        delete front;
    }

    bool isClicked(sf::Vector2f pos){
        return backside.getGlobalBounds().contains(pos);
    }

    void drawField(sf::RenderWindow* window){
        (swapped) ? window->draw(*front) : window->draw(backside);
    }

};

class NumberField: public Field{
public:
    sf::RectangleShape *front;
    sf::Text fieldText;

    NumberField(sf::Vector2f pos, sf::Vector2f size){
        front = new sf::RectangleShape(pos);
        front->setSize(size);

        fieldText.setString("8");
        fieldText.setCharacterSize(size.y);
        fieldText.setFillColor(sf::Color::Blue);
    }

    ~NumberField(){
        delete front;
    }

    bool isClicked(sf::Vector2f pos){
        return backside.getGlobalBounds().contains(pos);
    }

    void drawField(sf::RenderWindow* window){
        if(swapped) window->draw(*front);
        else {
           window->draw(backside);
           window->draw(fieldText);
        }
    }

};

//-------------------------------------------------------------------------

void loadTextures(){

    textures.resize(TEXTURE_NAMES.size());

    for(int i = 0; i < TEXTURE_NAMES.size(); i++){

        textures[i] = new sf::Texture;
        //load texture from file
        if(! textures[i]->loadFromFile(TEXTURES_PATH + '/' + TEXTURE_NAMES[i])){
            //exception...
            std::cerr << "Error: Texture \"" + TEXTURE_NAMES[i] +
                "\" could not be loaded." << std::endl;
            continue;
        }
        textures[i]->setSmooth(true);
    }

    return;
}

void initGrid(){

    float padding = 10; //distance from other elements in the scene
    float spacing = 5; //distance between cards

    // size of one card
    // padding gets subtracted from whole window getSize
    // spacing gets subtracted from each card but the first one
    float fieldX = (windowX - 2 * padding) / gridRows - spacing * ((float)(gridRows-1) / gridRows);
    float fieldY = (windowY - 2 * padding) / gridCols - spacing * ((float)(gridCols-1) / gridCols);

    //set Texture, size and position for each card
    for(int i = 0; i < gridCols; i++){
        for(int j = 0; j < gridRows; j++){

            grid[i][j].setTexture(*textures[1]);
            rescaleSprite(&grid[i][j], sf::Vector2f(fieldX, fieldY));
            grid[i][j].setPosition(sf::Vector2f(padding + ((fieldX + spacing) * j ),
                 padding + (fieldY + spacing) * i ));
        }
    }

    return;
}

//set size in pixels
void rescaleSprite(sf::Sprite* sprite, sf::Vector2f size){
    if (sprite->getTexture() != NULL) {
        sprite->setScale(sf::Vector2f(size.x / (float)sprite->getTexture()->getSize().x,
         size.y / (float)sprite->getTexture()->getSize().y));
    }

    return;
}

void drawGrid(){

    for(int i = 0; i < gridCols; i++){
        for(int j = 0; j < gridRows; j++){
            window.draw(grid[i][j]);
        }
    }
    return;
}

bool fieldIsClicked(int x, int y){
    for(int i = 0; i < gridCols; i++){
        for(int j = 0; j < gridRows; j++){

            if (grid[i][j].getGlobalBounds().contains(x, y)){

                /*
                sf::FloatRect rect = grid[i][j].getGlobalBounds();
                std::cout << "clicked on field " << i << " " << j << std::endl;
                std::cout << "left: " << rect.left << ", top: " << rect.top
                << ", width: " << rect.width << ", height: " << rect.height << std::endl;
                */

                return true;
            }
        }
    }

    return false;
}

bool gridIsClicked(int x, int y){
    if(x >= gridX && x <= gridX + gridSizeX){
        if(y >= gridY && y <= gridY + gridSizeY){
            fieldIsClicked(x, y);
            return true;
        }
    }
    return false;
}

void playErrorSound(){
    return;
}

void prepareGrid(int numMines){
    int numFields = gridCols * gridRows;
    std::vector<int> nums(numFields);
    for(int i = 0; i < nums.size(); i++)
        nums.push_back(i);


    std::shuffle(std::begin(nums), std::end(nums), rng);
    //todo
}

/*  TODO:
*   function: objClicked() that finds out which clickables were clicked.
*   trigger gameEvent fieldSwapped
*   shuffle mines in command
*   NumberFields
*   playErrorSound
*/

//-------------------------------------------------------------------------

int main()
{

    loadTextures();

    //prepareGrid(10);

    initGrid();

    /*
    sf::Sprite* mySprite = new sf::Sprite;
    addTexture("Mine.jpg", mySprite);
    mySprite->setScale(sf::Vector2f(0.1f, 0.1f));
    */
    sf::Sprite minesprt;
    minesprt.setTexture(*textures[0]);
    minesprt.setScale(sf::Vector2f(0.1f, 0.1f));

    sf::Sprite fieldsprt;
    fieldsprt.setTexture(*textures[1]);
    fieldsprt.setScale(sf::Vector2f(1.f, 1.f));
    fieldsprt.setPosition(sf::Vector2f(100.f, 100.f));

    //run program while window is open
    while(window.isOpen()){

    	//check all events of the window sinc last iteration
    	sf::Event event;
    	while(window.pollEvent(event)){

            switch(event.type){

                //close window when requested
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::Resized:
                    //TODO
                    break;

                case sf::Event::MouseButtonPressed:
                    if(event.mouseButton.button == sf::Mouse::Left){
                        //TODO: implement functions
                        //whatIsClicked(event.MouseButton.x, event.MouseButton.y);
                        std::cout << "Click at x: " << event.mouseButton.x <<
                            " y: " << event.mouseButton.y << std::endl;
                        gridIsClicked(event.mouseButton.x, event.mouseButton.y);

                    }
                    break;

                //other events remain unprocessed
                default:
                    break;
            }

    	}
        //clear window with black color
        window.clear(sf::Color::Black);

        //draw everything here

        drawGrid();

        //end the current frame
        window.display();
    }

    return 0;
}
