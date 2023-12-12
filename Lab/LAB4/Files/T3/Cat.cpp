// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// // Abstract base class
// class Animal {
// protected:
//     string _type;
// public:
//     virtual void show() = 0;  // pure virtual function
//     void setType(string type) {
//         this->_type = type;
//     }
//     string getType() { return _type; }
//     void PrintType();
// };

// void Animal::PrintType() {
//    cout << "The type of animal is: " << _type << endl;
// }

// // Derived class Cat
// class Cat : public Animal {
// private:
//     string name;
//     string breed;
//     int age;
//     static constexpr double licenseFee = 10;

// public:
//     void setCatData(string, string, int);
//     void showCat();
//     void show() override {
//         showCat();
//     }
// };

// void Cat::setCatData(string catName, string catBreed, int catAge) {
//     name = catName;
//     breed = catBreed;
//     age = catAge;
// }

// void Cat::showCat() {
//     PrintType();
//     cout << "Cat: " << name << " is a " << breed << endl;
//     cout << "The cat's age is " << age << endl;
//     cout << "License fee: $" << licenseFee << endl;
// }

// // Derived class Salmon
// class Salmon : public Animal {
// private:
//     string _name;
//     string _gender;
//     int _age;
//     static constexpr double _licenseFee = 10;

// public:
//     void setFishData(string, string, int);
//     void showFish();
//     void show() override {
//         showFish();
//     }
// };

// void Salmon::setFishData(string fishName, string gender, int fishAge) {
//     _name = fishName;
//     _gender = gender;
//     _age = fishAge;
// }

// void Salmon::showFish() {
//     PrintType();
//     cout << "Salmon: " << _name << " is a " << _gender << endl;
//     cout << "The fish's age is " << _age << endl;
//     cout << "License fee: $" << _licenseFee << endl;
// }

// int main() {
//     vector<Animal*> animals;

//     Cat* myCat = new Cat();
//     myCat->setType("Pet");
//     myCat->setCatData("Tigger", "Fluffy unit", 3);

//     Salmon* mySalmon = new Salmon();
//     mySalmon->setType("Fish");
//     mySalmon->setFishData("Sammy", "Male", 1);

//     animals.push_back(myCat);
//     animals.push_back(mySalmon);

//     for (Animal* animal : animals) {
//         animal->show();
//         cout << "|-------------------------|" << endl;
//     }

//     // clean up dynamic memory
//     for (Animal* animal : animals) {
//         delete animal;
//     }

//     return 0;
// }
