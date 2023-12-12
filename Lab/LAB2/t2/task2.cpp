#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file;
    string line, filename;
    int counter = 1;

    filename = "//Users//macbookmyduy//Desktop//CSCI251//Lab//LAB2//Words";
    file.open(filename.c_str());

    //Handling Exception with opening the file unsuccessfully
    if (!file.is_open()) {
        cerr << "Error opening the file '" << filename << "'" << endl;
        return 1;
    }

    while (getline(file, line)) {
        cout << line << ": " << counter << endl;
        counter++;
    }

    file.close();
    return 0;
}


