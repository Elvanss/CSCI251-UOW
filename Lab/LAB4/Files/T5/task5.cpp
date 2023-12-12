#include <iostream>
#include <string>
using namespace std;

class House {
private:
    string _material;
public:
    House(string material) : _material(material) {}

    string getMaterial() {
        return _material;
    }
};

class Pig {
private:
//create name of pig respectively
    string name;
//create house
    House* house;
public:
    Pig(string n, House* h) : name(n), house(h) {}

    string getHouseMaterial() {
        return house->getMaterial();
    }

    void pigSaid(string words) {
        cout << name << " says: " << words << "\n";
    }
};

class Wolf {
private:
//show the appearance of wolfs
    string name;
public:
    Wolf(string n) : name(n) {}

    void wolfSaid(string words) {
        cout << name << " says: " << words << "\n";
    }

    bool destroy(Pig& pig) {
        string material = pig.getHouseMaterial();
        if (material == "bricks-material") {
            return false;
        }
        return true;
    }
};

int main() {
//CREATE 3 HOUSES WITH GIVEN Characteristic
    House* strawHouse = new House("straw-material");
    House* sticksHouse = new House("sticks-material");
    House* bricksHouse = new House("bricks-material");

    Pig pig1("First Pig", strawHouse);
    Pig pig2("Second Pig", sticksHouse);
    Pig pig3("Third Pig", bricksHouse);

    cout<<"The story about the wolf with 3 litte pig, which built 3 house in 3 different materials(straw, stick, brick) respectively"<<endl;
    Wolf wolf("Wolf");
    cout<<"-------------The first pig:--------------"<<endl;
    wolf.wolfSaid("Let me in, Let me in little pig, or I'll huff and I'll puff and I'll blow your house in!");
    pig1.pigSaid("Not by the hair of my chinny chin chin!");
    if (wolf.destroy(pig1)) {
        wolf.wolfSaid("I've blown down your house and I'll eat you up!");
    } else {
        pig1.pigSaid("You can't blow down my house!");
    }
    cout<<"-------------End--------------"<<endl;
    cout<<"-------------The second pig:--------------"<<endl;
    wolf.wolfSaid("Let me in, Let me in little pig, or I'll huff and I'll puff and I'll blow your house in!");
    pig2.pigSaid("Not by the hair of my chinny chin chin!");
    if (wolf.destroy(pig2)) {
        wolf.wolfSaid("I've blown down your house and I'll eat you up!");
    } else {
        pig2.pigSaid("You can't blow down my house!");
    }
    cout<<"-------------End--------------"<<endl;
    cout<<"-------------The third pig:--------------"<<endl;
    wolf.wolfSaid("Let me in, Let me in little pig, or I'll huff and I'll puff and I'll blow your house in!");
    pig3.pigSaid("Not by the hair of my chinny chin chin!");
    if (wolf.destroy(pig3)) {
        wolf.wolfSaid("I've blown down your house and I'll eat you up!");
    } else {
        pig3.pigSaid("You can't blow down my brick house!");
        wolf.wolfSaid("I'll climb up the chimney and get you!");
        pig3.pigSaid("I've placed a kettle of boiling water below the chimney!");
        wolf.wolfSaid("Aaaargh! I'm getting out of here!");
    }
    cout<<"-------------End--------------"<<endl;
    Pig motherPig("Mother of 3 Little Pigs", nullptr); 
    motherPig.pigSaid("You see, it is just as I told you. The way to get along in the world is to do things as well as you can.");
    pig3.pigSaid("I've learned that lesson, mother.");
    cout << "And the third pig lived happily ever after!\n";
    cout<<"-------------Done--------------"<<endl;

    //delete the cache:
    delete strawHouse;
    delete sticksHouse;
    delete bricksHouse;

    return 0;
}
