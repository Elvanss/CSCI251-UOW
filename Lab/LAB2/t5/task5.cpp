#include <iostream>

using namespace std;

class MyException : public exception {
public:
    const char* what() const throw() {
        return "Attempted to divide by zero!\n";
    }
};

int main() {
    double x, y;
    cout << "Enter the numbers of x and y: ";
    cin >> x;
    cin >> y;

    try {
        if (y == 0) {
            throw MyException();
        }

        double z = x / y;
        cout << "x / y = " << z;
    } catch (const MyException& e) {
        cerr << e.what();
    }

    return 0;
}
