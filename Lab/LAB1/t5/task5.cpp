#include <iostream>
using namespace std;

//void swap(int *ptr1, int *ptr2);
void swap(int *ptr1, int *ptr2) {
    int element = *ptr1;
    //assign the temporary value for 2nd value pointer
    *ptr1 = *ptr2;
    //swap the element
    *ptr2 = element;
}

int main() {
    int array[5];
    cout << "Enter the value of the array: ";
    for (int i = 0; i < 5; i++) {
        cin >> array[i];
    }

    cout << "All elements before swapping: ";
    for (int i = 0; i < 5; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    swap(&array[4], &array[3]);

    cout << "Array after swapping: ";
    for (int i = 0; i < 5; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
