#include<iostream>
#include<string>

using namespace std;

class Cat
{
private:
   string name;
   string breed;
   int age;
   static constexpr double licenseFee = 10;

public:
   //constructor (default)
   Cat() {

   }
   //constructor
   Cat(string name, string breed, int age) : name(name), breed(breed), age(age) {
      
   }
   //destructor
   ~Cat() {
      cout<<"destructor\n";
   }

   //copy constructor
   Cat(const Cat &obj) {
      name = obj.name;
      breed = obj.breed;
      age = obj.age;
   }

   void setCatData(string, string, int);
   void showCat();
   void showAddress();
};
// const double Cat::licenseFee = 10;

void Cat::setCatData(string catName, string catBreed, int catAge)
{
   name = catName;
   breed = catBreed;
   age = catAge;
}

void Cat::showCat()
{
  cout << "Cat: " << name << " is a " << breed << endl;
  cout << "The cat's age is " << age << endl;
  cout << "License fee: $" << licenseFee << endl;
}

void Cat::showAddress()  
{
   cout<<"Address of name: "<< &name<<endl;
   cout<<"Address of breed: "<< &breed<<endl;
   cout<<"Address of age: "<<&age<<endl;
}
int main()
{
   //default constructor
     cout<<"default constructor"<<endl;
     Cat myCat;
     myCat.setCatData("Tiger", "Fluffy unit", 3);
     myCat.showCat();
     myCat.showAddress();
     cout<<"\n";

   //Constructor with parameters
   cout<<"Constructor with parameters"<<endl;
   Cat myCat2("Tiger", "Fluffy", 3);
   myCat2.showCat();
   myCat2.showAddress();
   cout<<"\n";
   
   cout<<"Copy Constructor"<<endl;
   //Copy Constructor
   Cat copyVer = myCat2;
   copyVer.showCat();
   copyVer.showAddress();
   cout<<"\n";

   cout<<"Destructor test"<<endl;
   
}





