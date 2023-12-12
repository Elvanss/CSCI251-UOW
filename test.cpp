// #include <iostream>
// using namespace std;

// //Pointers
// int main() {
//     int var = 10;
//     int* ptr = &var;  // ptr holds the address of var
    
//     cout << "Value of var: " << var << endl;
//     cout << "Address of var: " << &var << endl;
//     cout << "Value of ptr: " << ptr << endl;
//     cout << "Dereferenced ptr: " << *ptr << endl;  // dereferencing gives the value of var
    
//     *ptr = 20;  // changing the value at the memory address pointed by ptr
//     cout << "Value of var after changing *ptr: " << var << endl;
    
//     return 0;
// }

// //References
// #include <iostream>
// using namespace std;

// int main() {
//     int var = 30;
//     int& ref = var;  // ref is a reference (alias) to var
    
//     cout << "Value of var: " << var << endl;
//     cout << "Value of ref: " << ref << endl;
    
//     ref = 40;  // changing ref also changes var
//     cout << "Value of var after changing ref: " << var << endl;
    
//     return 0;
// }

// //Pointer to Pointer
// #include <iostream>
// using namespace std;

// int main() {
//     int var = 50;
//     int* ptr = &var;
//     int** ptrToPtr = &ptr;
    
//     **ptrToPtr = 60;
//     cout << "Value of var: " << var << endl;
//     cout << "Dereferenced ptr: " << *ptr << endl;
//     cout << "Dereferenced ptrToPtr: " << **ptrToPtr << endl;
//     return 0;
// }

//Pointer and Reference together
// #include <iostream>
// using namespace std;

// int main() {
//     int var = 60;
//     int* ptr = &var;
//     int& ref = *ptr;  // ref is a reference to the int pointed by ptr
    
//     cout << "Value of var: " << var << endl;
//     cout << "Dereferenced ptr: " << *ptr << endl;
//     cout << "Value of ref: " << ref << endl;
    
//     var = 70;
//     cout << "Value of var after changing ref: " << var << endl;
//     cout << "Dereferenced ptr after changing ref: " << *ptr << endl;
//     cout << "Value of ref after changing: " << ref << endl;
    
//     return 0;
// }

//----------------------------------------------------------------------

// //Pointer and array
// #include <iostream>
// using namespace std;

// int main() {
//     int arr[] = {10, 20, 30, 40, 50};
//     int* ptr = arr;  // pointer to the first element of arr

//     cout << "First element of arr: " << *ptr << endl;
//     ptr++;  // move pointer to the next integer
//     cout << "Second element of arr: " << *ptr << endl;

//     // Accessing array elements using pointer arithmetic
//     cout << "Third element of arr: " << *(ptr + 1) << endl;
    
//     return 0;
// }

// //Reference and Array
// #include <iostream>
// using namespace std;

// int main() {
//     int arr[] = {10, 20, 30, 40, 50};

//     // Creating a reference to an array element
//     int& ref = arr[2];  // ref is a reference to the third element of arr
//     cout << "Third element of arr: " << ref << endl;

//     // Changing the reference also changes the array element
//     ref = 60;
//     cout << "arr[2] after changing ref: " << arr[2] << endl;
    
//     return 0;
// }

// //Pointers to Arrays
// #include <iostream>
// using namespace std;

// void printArray(int (*arrPtr)[5]) {
//     for (int i = 0; i < 5; i++) {
//         cout << (*arrPtr)[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     int arr[5] = {10, 20, 30, 40, 50};
//     printArray(&arr);  // passing a pointer to the array to a function
    
//     return 0;
// }

// #include <iostream>

// // Functor that adds two floats and a double, then converts the result to an int
// class Adder {
// public:
//     int operator()(float a, float b, double c) {
//         return int(a + b + c); // Functional cast
//     }
// };

// int main() {
//     Adder adder; // Create an instance of the Adder function object
//     float x = 1.2f;
//     float y = 3.4f;
//     double z = 5.6;

//     // Use the Adder function object to add the numbers and convert to int
//     int result = adder(x, y, z);

//     std::cout << "The result is: " << result << std::endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// template<typename T>
// T findMinArr(T* arr, int size) {
//     T minVal = arr[0]; // Start with the first element as the minimum
//     for (int i = 1; i < size; ++i) {
//         if (arr[i] < minVal) {
//             minVal = arr[i]; // Update minVal if a smaller element is found
//         }
//     }
//     return minVal; // Return the smallest element
// }

// int main() {
//     int a[]{7, 8, 1, 2, 4, 12, 4};
//     char b[]{'h', 'i', 'a', 'o', 'w'};
//     double c[]{1.77, 1.11, 2.22, 3.33, 8.88};

//     cout << "Min value of INT array: " << findMinArr(a, sizeof(a)/sizeof(a[0])) << endl;
//     cout << "Min value of CHAR array: " << findMinArr(b, sizeof(b)/sizeof(b[0])) << endl;
//     cout << "Min value of DOUBLE array: " << findMinArr(c, sizeof(c)/sizeof(c[0])) << endl;
//     cout << sizeof(a) << endl;
//     cout << sizeof(a[0]) << endl;
//     return 0;
// }

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
// Define the Bike class
class Bike {
public:
    std::string brand;
    std::string model;
    int durability;

    Bike(std::string b, std::string m, int d) : brand(b), model(m), durability(d) {}

    // Overload the < operator to compare Bike's durability
    bool operator < (const Bike& other) const {
        return durability < other.durability;
    }
};

// Function template to find the 'worst' of three bikes
template <typename T>
const T& Worst(const T& a, const T& b, const T& c) {
    // Compare a and b, and then the result with c
    const T& worst_ab = std::min(a, b);
    return std::min(worst_ab, c);
}

// Test the Worst function with Bike objects
int main() {
    Bike bike1("Trek", "Emonda", 90);
    Bike bike2("Giant", "Defy", 80);
    Bike bike3("Specialized", "Tarmac", 85);

    Bike worstBike = Worst(bike1, bike2, bike3);
    std::cout << "The worst bike is " << worstBike.brand << " " << worstBike.model << " with durability " << worstBike.durability << std::endl;

    return 0;
}





