#include <iostream>

int main() {
    int ptr1[5];
    int * const ptr2 = new int[5];

    std::cout << "Size of ptr1 (array): " << sizeof(ptr1) << " bytes" << std::endl;
    std::cout << "Size of ptr2 (pointer): " << sizeof(ptr2) << " bytes" << std::endl;

    delete[] ptr2; // Don't forget to deallocate memory
    return 0;
}
