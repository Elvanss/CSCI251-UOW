#include <iostream>
#include <string>
#include "LibraryC.h"

using namespace std;

bool friendTest(const City& city, const Money& money) {
    if (city.country != money.currencyName) {
        return false;
    }
    return true;
}
