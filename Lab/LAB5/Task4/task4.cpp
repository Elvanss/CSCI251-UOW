#include <iostream>
using namespace std;

template <typename T>
class Hold {
    private:
        T value;

    public:
        Hold(T& value) : value(value) {}

        //simple
        T getValue() { 
            return value; 
        }

        //double
        T doubled() {
            return value + value;
        }
};

int main() {
    int intNum = 10;
    Hold<int> holdInt(intNum);
    cout << "Simple int: " << holdInt.getValue() << endl;
    cout << "Doubled int: " << holdInt.doubled() << endl;

    float floatNum = 10.5f;
    Hold<float> holdFloat(floatNum);
    cout << "Simple float: " << holdFloat.getValue() << endl;
    cout << "Doubled float: " << holdFloat.doubled() << endl;

    double doubleNum = 2.55l;
    Hold<double> holdDouble(doubleNum);
    cout << "Simple float: " << holdDouble.getValue() << endl;
    cout << "Doubled float: " << holdDouble.doubled() << endl;

    string stringName = "task5";
    Hold<string> holdString(stringName);
    cout << "Simple string: " << holdString.getValue() << endl;
    cout << "Doubled string: " << holdString.doubled() << endl;
}