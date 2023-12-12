#include<iostream>
#include <vector>
using namespace std;

class Box {
private:
    int _boxID;
    vector<Box*> box;
    int _capacity;

public:
    Box(int boxId, int boxNum, int capacity) 
        : _boxID(boxId), _capacity(capacity) {}

    void addBox(Box *newBox) {
        if(newBox == this) {
            cout << "You cannot add a box to itself!" << endl;
            return;
        }
        
        if(box.size() >= _capacity) {
            cout << "The box " << _boxID << " has reached its maximum capacity. Cannot add box " << newBox->_boxID << "." << endl;
            return;
        }

        for(auto b : box) {
            if(b == newBox) {
                cout << "The box " << newBox->_boxID << " is already in the box " << _boxID << "." << endl;
                return;
            }
        }

        box.push_back(newBox);
        cout << "The box " << newBox->_boxID << " has been added to the box " << _boxID << "." << endl;
    }
};

int main() {
    Box box1(1, 5, 4);
    Box box2(2, 10, 4);
    Box box3(3, 15, 2);
    Box box4(4, 10, 1);

    box1.addBox(&box2);
    box1.addBox(&box3);
    box1.addBox(&box4);
    box1.addBox(&box2);
    box1.addBox(&box1);
    box3.addBox(&box1);
    box3.addBox(&box2);
    box3.addBox(&box4);

    return 0;
}
