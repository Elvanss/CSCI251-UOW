#include <iostream>
using namespace std;

int main() {
    double r;
    double s;
    double v;
    cout << "input the radius "; 
    cin >> r;

    s = 3.14 * r * r;
    v = 2 * 3.14 * r;

    cout << "The area of this circle is: " << s << endl;
    cout << "The circumference of this circle is: " << v << endl;

    return 0;
}
