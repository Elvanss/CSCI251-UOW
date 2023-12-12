#include <iostream>
#include <string>
#include "Library.h"

using namespace std;

int main() {
    //equal
    Money aus("Australia", "AUD", 17.5);
    City syd("Sydney", "Australia", 524, 4.5);
    if (friendTest(syd, aus)) {
        cout<<"Sydney and Australia have the same currency!"<<endl;
    } else {
        cout<<"Sydney and Australia don't have the same currency!"<<endl;
    }

    //unfamiliarity
    Money ger("Germany", "EUR", 25.5);
    City london("England", "GBP", 829, 5.6);
    if (friendTest(london, ger)) {
        cout<<"Germany and London have the same currency!"<<endl;
    } else {
        cout<<"Germany and London don't have the same currency!"<<endl;
    }

    return 0;
}