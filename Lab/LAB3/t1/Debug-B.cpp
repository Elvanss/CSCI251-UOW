//error(not include the import)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//error (from Hot to Hat)
class Hat {
  private:
    string type;
    char size; // S, M, L
  public:
    Hat(string, char);
    void display();
};

Hat::Hat(string _type, char _size) : type(_type), size(_size) {};

void Hat::display()
{
  //">>"
    cout << "Hat type   : " << type << endl;
    cout << "Hat size   : " << size << endl;
}

class Person {
private:
    string name;
    int idNum;
    Hat myHat;
public:
    Person(string, int, string, char);
    void display();
};

//Error(miss one ":")
Person::Person(string _name, int _idNum, string hattype, char hat_size)
    : name(_name), idNum(_idNum), myHat(hattype, hat_size) {}

void Person::display() {
    cout << "Given name : " << name << endl;
    cout << "Id. number : " << idNum << endl;
    myHat.display();
}

int main() {
    Person personA("Alice",12321,"Beret",'M');
    Person personB("Bob",2324,"Trilby",'S');
    personA.display();
    personB.display();

    return 0;
}


