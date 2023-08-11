 #include <iostream>

using namespace std;

int main() {
    int m, target;

    cout << "Enter the value m: ";
    cin >> m;
    cout << "Enter the value n: ";
    cin >> target;

    while (target <= 1) {
        cout << "Enter the value n (greater than 1): ";
        cin >> target;
    }

    for (int i = 1; i <= target; ++i) {
        cout << m * i;
        if (i != target) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}

