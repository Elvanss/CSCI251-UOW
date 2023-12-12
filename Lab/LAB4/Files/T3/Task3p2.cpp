#include <iostream>
using namespace std;

class Transportation {
protected:
    string _type;

public:
    Transportation() : _type() {}
    Transportation(string type) : _type(type) {}

    string getType() {
        return _type;
    }

    void setType(string type) {
        this->_type = type;
    }

    void printType() {
        cout << "The type of transportation is: " << _type << endl;
    }
};

class LandTransport : public Transportation {
protected:
    int _id;
    string _property;

public:
    LandTransport() : Transportation(), _id(0), _property("Unknown") {}
    LandTransport(string type, int id, string property)
        : Transportation(type), _id(id), _property(property) {}

    void printLand() {
        printType();
        cout << "ID: " << _id << " is the property of " << _property << endl;
    }
};

class Car : public LandTransport {
protected:
    string _carType;
    string _seatNum;

public:
    Car(string type, int id, string property, string carType, string num)
        : LandTransport(type, id, property), _carType(carType), _seatNum(num) {}

    void printCarObj() {
        printLand();
        cout << "The type of car: " << _carType << endl;
        cout << "The number of seats: " << _seatNum << endl;
    }
};

class Canoe : public Transportation {
protected:
    int _id;
    string _property;
    int _capacity;

public:
    Canoe() : Transportation(), _id(0), _property("Unknown"), _capacity(0) {}
    Canoe(string type, int id, string property, int capacity)
        : Transportation(type), _id(id), _property(property), _capacity(capacity) {}

    void printCanoe() {
        printType();
        cout << "ID: " << _id << " is the property of " << _property << endl;
        cout << "The capacity is " << _capacity << endl;
    }
};

class AirTransport : public Transportation {
protected:
    int _power;

public:
    AirTransport() : Transportation(), _power(0) {}
    AirTransport(string type, int power)
        : Transportation(type), _power(power) {}

    void printAir() {
        printType();
        cout << "Horsepower: " << _power << endl;
    }
};

class SeaTransport : public Transportation {
protected:
    int _id;
    string _property;

public:
    SeaTransport() : Transportation(), _id(0), _property("Unknown") {}
    SeaTransport(string type, int id, string property)
        : Transportation(type), _id(id), _property(property) {}

    void printSea() {
        printType();
        cout << "ID: " << _id << " is the property of " << _property << endl;
    }
};

class HoverCraft : public SeaTransport, public AirTransport {
protected:
    int _yearMake;

public:
    HoverCraft() : SeaTransport(), AirTransport(), _yearMake(0) {}
    HoverCraft(string type, int id, string property, int power, int yearMake)
        : SeaTransport(type, id, property), AirTransport(type, power), _yearMake(yearMake) {}

    void printCraft() {
        SeaTransport::printType();
        cout << "ID: " << _id << " is the property of " << _property << endl;
        cout << "Horsepower: " << _power << endl;
        cout << "The manufacturing year: " << _yearMake << endl;
    }
};

int main() {
    Canoe myCanoe("Sea Transport", 101, "Recreational", 2);
    cout << "Details of myCanoe:" << endl;
    myCanoe.printCanoe();
    cout << "\n\n";

    Car myCar("Land Transport", 202, "Personal", "Sedan", "4");
    cout << "Details of myCar:" << endl;
    myCar.printCarObj();
    cout << "\n\n";

    HoverCraft myHoverCraft("Amphibious Transport", 303, "Military", 5000, 2020);
    cout << "Details of myHoverCraft:" << endl;
    myHoverCraft.printCraft();
    cout << "\n\n";

    return 0;
}
