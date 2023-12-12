#include <iostream>
#include <cstdlib>
#include "Header.h"

int main(int argc, char* argv[]) {   
    if(argc != 3) {
        std::cerr << "Invalid Input!" << std::endl;
        exit(1);
    }
    if(std::atoi(argv[1]) <= 0 || std::atoi(argv[1]) > 10) {
    std::cerr << "Invalid Electorate Number!" << std::endl;
    exit(1);
}

if(std::atoi(argv[2]) <= 0 || std::atoi(argv[2]) > 30) {
    std::cerr << "Invalid Day Number!" << std::endl;
    exit(1);
}

    showInfo(atoi(argv[1]), atoi(argv[2]));
    return 0;
}
