#include "header.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    //calling the method from header.cpp 
    if (argc !=4) {
        cerr <<("Please provide valid argument s: -\n ./run Tasks.txt Workers.txt Output.txt");
        return 1;
    }
    fileInput(argv[1], argv[2], argv[3]);
    return 0;
}
