#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
// This is a comment
/*
multi-line
*/

int addNumbers(int firstNum, int secondNum = 0){
    return firstNum + secondNum;
}

int addNumbers(int firstNum, int secondNum, int thirdNum){
    return firstNum + secondNum + thirdNum;
}

int getFactorial(int number){

    int sum;
    if(number == 1) sum = 1;
    else sum = getFactorial(number-1) * number;
    return sum;

}

void makeMeYoung(int* age){

    cout << "I used to be " << *age << endl;
    *age = 21;

}

void actYourAge(int& age){

    age = 39;

}

class Animal{
    private:
        int height;
        int weight;
        string name;

        static int numOfAnimals;

    public:
        int getHeight(){ return height; }
        int getWeight(){ return weight; }
        string getName(){ return name; }
        void setHeight(int cm){ height = cm; }
        void setWeight(int kg){ weight = kg; }
        void setName(string animalName){ name = animalName; }

        void setAll(int, int, string);

        Animal(int, int, string);

        //Destructor
        ~Animal();

        Animal();

        static int getNumOfAnimals() { return numOfAnimals; }

        void toString();

};

int Animal::numOfAnimals = 0;

void Animal::setAll(int height, int weight, string name){

    this -> height = height;
    this -> weight = weight;
    this -> name = name;
    Animal::numOfAnimals++;

}

Animal::Animal(int height, int weight, string name){

    this -> height = height;
    this -> weight = weight;
    this -> name = name;
    Animal::numOfAnimals++;

}

Animal::~Animal(){

    cout << "Animal " << this -> name << " destroyed" << endl;

}

Animal::Animal(){

    Animal::numOfAnimals++;

}

void Animal::toString(){

    cout << this -> name << " is " << this -> height <<
        " cms tall and " << this -> weight << " kgs in weight" << endl;

}

class Dog : public Animal {

private:
    string sound = "Woof";

public:
    void getSound(){ cout << sound << endl; }

    Dog(int, int, string, string);

    Dog() : Animal(){};

    void toString();

};

Dog::Dog(int height, int weight, string name, string bark) :
    Animal(height, weight, name){

    this -> sound = bark;

}

void Dog::toString(){

    cout << this -> getName() << " is " << this -> getHeight() <<
        " cms tall and " << this -> getWeight() <<
        " kgs in weight and says " << this -> sound << endl;
}

class Animal_{
    public:
        void getFamily() { cout << "We are Animals" << endl;}

        virtual void getClass() { cout << "I'm an Animal" << endl;}

};

class Dog_ : public Animal_{
    public:
        void getClass() { cout << "I'm a Dog " << endl;}
};

void whatClassAreYou(Animal_ *animal){

    animal -> getClass();
}

class GermanShepard : public Dog_{
    public:
        void getClass() { cout << "I'm a German Shepard" << endl; }
        void getDerived() { cout << "I'm an Animal and Dog" << endl; }
};

int main(){

    cout << "Hello World" << endl;

    const double PI = 3.1415926535;

    char myGrade = 'A'; //1 byte
    bool isHappy = true;
    int myAge = 38;
    float favNum = 3.141592;
    double otherfavNum = 1.6180339887;

    cout << "Size of int " << sizeof(myAge) << endl;
    cout << "Size of bool " << sizeof(isHappy) << endl;
    cout << "Size of float " << sizeof(favNum) << endl;
    cout << "Size of double " << sizeof(otherfavNum) << endl;

    int largestInt = 2147483647;

    cout << "largest Int " << largestInt << endl;

    int five = 5;
    cout << "5++ = " << five++ << endl;
    cout << "++5 = " << ++five << endl;
    cout << "5-- = " << five-- << endl;
    cout << "--5 = " << --five << endl;
    five += 6;

    cout << "4 / 5 = " << 4 / 5 << endl;
    cout << "4 / 5 = " << (float) 4 / 5 << endl;

    int age = 70;
    int ageAtLastExam = 16;
    bool isNotIntoxicated = true;

    if((age >= 1) && (age < 16)){

        cout << "You can't drive" << endl;

    } else if(! isNotIntoxicated){

        cout << "You can't drive" << endl;

    } else if(age >= 80 && ((age > 100) || (age - ageAtLastExam) > 5)){

        cout << "You can't drive" << endl;
    } else {
        cout << "You can drive" << endl;
    }

    int greetingOption = 2;
    greetingOption = (5>2) ? 5 : 2;

    switch(greetingOption){

        case 1:
            cout << "bonjour" << endl;
            break;
        case 2:
            cout << "Hola" << endl;
            break;
        case 3:
            cout << "Hallo" << endl;
            break;
        default :
            cout << "Hello" << endl;
    }

    int myFavNums[5];
    int badNums[5] = {3, 13, 14, 24, 34};
    cout << "Bad Number 1: " << badNums[0] << endl;

    char myName[5][5] = {{'D', 'e', 'r', 'e', 'k'},
    {'B', 'a', 'n', 'a', 's'}};
    cout << "2nd letter in 2nd array " << myName[1][1] << endl;

    myName[0][2] = 'e';
    cout << "New Value " << myName[0][2] << endl;

    for(int i = 1; i <= 10; i++){

        cout << i << endl;

    }

    for(int j = 0; j < 5; j++){

        for(int k = 0; k < 5; k++){

            cout << myName[j][k];

        }

        cout << endl;

    }

    int randNum = (rand() % 100) + 1;

    while(randNum != 100){

        cout << randNum << ", ";

        randNum = (rand() % 100) + 1;

    }

    int index = 1;

    while(index <= 10){

        cout << index << endl;

        index++;

    }

    string numberGuessed;
    int intNumberGuessed = 0;
/*
    do {

        cout << "Guess between 1 and 10: ";

        getline(cin, numberGuessed);

        intNumberGuessed = stoi(numberGuessed);

        cout << intNumberGuessed << endl;

    } while(intNumberGuessed != 4);

    cout << "You win!" << endl;
*/
    char happyArray[6] = {'H', 'a', 'p', 'p', 'y', '\0'};

    string birthdayString = " Birthday";

    cout << happyArray + birthdayString << endl;

    /*
    string yourName;
    cout << "What is yourName";
    getline(cin, yourName);

    cout << "hello " << yourName << endl;

    double eulersConstant = .57721;
    string eulerGuess;
    double eulerGuessDouble;

    cout << "What is Euler's Constant? ";
    getline(cin, eulerGuess);

    eulerGuessDouble = stod(eulerGuess);

    if(eulerGuessDouble == eulersConstant){

        cout << "You are right" << endl;

    } else {

        cout << " You are wrong" << endl;

    }
    */
    string happyArray2 = happyArray;

    cout << "Size of String " << happyArray2.size() << endl;
    cout << "Is string empty " << happyArray2.empty() << endl;
    cout << happyArray2.append(" was happy?") << endl;

    string dogString = "dog";
    string catString = "cat";

    cout << dogString.compare(catString) << endl;
    cout << dogString.compare(dogString) << endl;
    cout << catString.compare(dogString) << endl;
    /*
    string yourName;
    cout << "What is yourName ";
    getline(cin, yourName);

    string wholeName = yourName.assign(yourName);
    cout << wholeName << endl;

    string firstName = wholeName.assign(wholeName, 0, 5);
    cout << firstName << endl;

    int lastNameIndex = yourName.find("Banas", 0);
    cout << "Index for last name " << lastNameIndex << endl;

    yourName.insert(5, " Justin");
    cout << yourName << endl;

    yourName.erase(6, 7);
    cout << yourName << endl;

    yourName.replace(6, 5, "Maximus");
    cout << yourName << endl;
    */

    vector <int> lotteryNumVect(10);

    int lotteryNumArray[5] = {4, 13, 24, 34};

    lotteryNumVect.insert(lotteryNumVect.begin(),
        lotteryNumArray, lotteryNumArray+3);

    cout << lotteryNumVect.at(2) << endl;

    lotteryNumVect.insert(lotteryNumVect.begin()+5, 44);

    cout << lotteryNumVect.at(5) << endl;

    lotteryNumVect.push_back(64);

    cout << "Final Value " << lotteryNumVect.back() << endl;
    cout << "First Value " << lotteryNumVect.front() << endl;
    cout << "empty?" << lotteryNumVect.empty() << endl;
    cout << "Size " << lotteryNumVect.size() << endl;

    lotteryNumVect.pop_back();

    for(int i=0; i < lotteryNumVect.size(); i++){
        cout << lotteryNumVect.at(i) << ' ';
    }
    cout << endl;

    cout << addNumbers(1) << endl;
    cout << addNumbers(1, 5, 6) << endl;
    cout << getFactorial(3) << endl;

    string steveQuote = "A day without sunshine is like, you know, night";
    ofstream writer("stevequote.txt");

    if(! writer){

        cout << "Error opening file" << endl;
        return -1;

    } else {

        writer << steveQuote << endl;

        writer.close();

    }

    ofstream writer2("stevequote.txt", ios::app);

    // Open a stream to append to whats there with ios::app
    // ios::binary : Treat the file as a binary
    // ios::in : Open a file to read input
    // ios::trunc : default
    // ios::out : Open a file to write output

    if(! writer2){

        cout << "Error opening file" << endl;
        return -1;

    } else {

        writer2 << "\n -Steve Martin" << endl;

        writer.close();

    }

    char letter;

    ifstream reader("stevequote.txt");

    if(! reader){

        cout << "Error opening file" << endl;
        return -1;

    } else {

        for(int i = 0; ! reader.eof(); i++){

            reader.get(letter);
            cout << letter;

        }

        cout << endl;
        reader.close();

    }

    int number = 0;

    try{

        if(number != 0){

            cout << 2/number << endl;

        } else throw(number);

    } catch(int number){

        cout << number << " is not valid" << endl;

    }

    cout << "myAge is located at " << &myAge << endl;
    /*
    // after end of function sum will still be five
    // because only a value is passed.
    int sum = 5;

    addThese(sum);
    */

    int* agePtr = &myAge;

    cout << "Address of pointer " << agePtr << endl;

    cout << "Data at memory address " << *agePtr << endl;

    int* numArrayPtr = badNums;

    cout << "Address " << numArrayPtr << " Value " << *numArrayPtr << endl;

    numArrayPtr++;

    cout << "Address " << numArrayPtr << " Value " << *numArrayPtr << endl;

    cout << "Address " << badNums << " Value " << *badNums << endl;

    // int myAge = 39;

    makeMeYoung(&myAge);

    cout << "I'm " << myAge << " years old now" << endl;

    int& ageRef = myAge;

    cout << "myAge : " << myAge << endl;
    ageRef++;

    cout << "myAge : " << myAge << endl;

    actYourAge(ageRef);

    cout << "myAge : " << myAge << endl;

    Animal fred;

    fred.setHeight(33);
    fred.setWeight(10);
    fred.setName("Fred");

    cout << fred.getName() << " is " << fred.getHeight()
        << " cms tall and " << fred.getWeight() << "kgs in weight" << endl;

    Animal tom(36, 15, "Tom");

    cout << tom.getName() << " is " << tom.getHeight()
        << " cms tall and " << tom.getWeight() << "kgs in weight" << endl;

    Dog spot(38, 16, "Spot", "Woof");

    cout << "Number of Animals " << Animal::getNumOfAnimals() << endl;

    spot.getSound();

    tom.toString();
    spot.toString();

    spot.Animal::toString();
    // :: : scope operator

    Animal_ *animal = new Animal_;
    Dog_ *dog = new Dog_;

    animal->getClass();
    dog->getClass();

    whatClassAreYou(animal);
    whatClassAreYou(dog);

    Dog_ spot2;
    GermanShepard max;

    Animal_* ptrDog = &spot2;
    Animal_* ptrGShepard = &max;

    ptrDog -> getFamily();

    ptrDog -> getClass();

    return 0;
}
