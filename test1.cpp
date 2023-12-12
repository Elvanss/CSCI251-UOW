// // #include <iostream>

// // using namespace std;

// // class Square {
// // private:
// //     int length; // Length of a square

// // public:
// //     // Constructor non-default
// //     Square(int l) {
// //         cout << "Constructor created." << endl;
// //         length = l;
// //     }

// //     int area() {
// //         return length * length;
// //     }
// // };

// // int main() {
// //     Square square1(3); 
// //     Square square2(4); 

// //     // Square *ptr;
// //     // ptr = &square1;
// //     cout << "The area of square 1 is: " << square1.area() << endl;

// //     // ptr = &square2;
// //     cout << "The area of square 2 is: " << square2.area() << endl;

// //     return 0;
// // }

// #include <iostream>

// struct Circle {
//     static constexpr double PI = 3.14; // Declaration of a static const member
//     double radius;

//     double area() const {
//         return PI * radius * radius;
//     }
// };

// // You need to define the static const member outside the struct.
// // const double Circle::PI = 3.14159265358979323846;

// int main() {
//     Circle circle1;
//     circle1.radius = 5;
//     std::cout << "Area of circle1: " << circle1.area() << std::endl;

//     Circle circle2;
//     circle2.radius = 10;
//     std::cout << "Area of circle2: " << circle2.area() << std::endl;

//     return 0;
// };    
// #include <iostream>
// using namespace std;

// int main() {
//     int var = 10;
//     int *ptr1 = &var;
//     int **ptr2 = &ptr1;
    
//     **ptr2 = 14;
//     cout << "value of var: " << var << endl;
//     cout << "value of var (via ptr1): " << *ptr1 << endl;
//     cout << "ptr1 == " << &var << endl;
//     cout << "value of var (via ptr2): " << **ptr2 << endl;
//     cout << "ptr2 == " << &ptr1 << endl;
//     cout << "ptr2 == " << &var << " == " << ptr1 << endl;

//     return 0;
// }

#include <iostream>
using namespace std;

void function1(int x) {
    x = x + 10;
}

void function2(int &x) {
    x = x + 10;
}

int main() {
    int y = 5;
    function1(y);
    cout << "y value is: " << y << endl;
    function2(y);
    cout << "y value is: " << y << endl;
    return 0;
}


