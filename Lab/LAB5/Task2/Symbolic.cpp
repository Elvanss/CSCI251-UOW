#include <iostream>

using namespace std;

template<typename T>
void displayValue(const T& value, int n, char x) {
    string symbol(n, x);
    cout << symbol << " " << value << " " << symbol << endl;
}

int main() {
    displayValue(47, 3, '*');
    displayValue(39.25, 3, '0');
    displayValue("Bob", 4, 'a');

    displayValue(20, 5, '*');
    displayValue(40.75, 4, '0');
    displayValue("Hello", 3, 'b');

}
