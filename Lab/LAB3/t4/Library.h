#include <iostream>
#include <string>

using namespace std;
//Define the classes
class Money;
class City;

class Money {
private:
    string currencyName;
    string dollarUnit;
    double rate;
public:
    Money(string currency_Name, string dollar_Unit, double _rate)
        : currencyName(currency_Name), dollarUnit(dollar_Unit), rate(_rate) {}
    friend bool friendTest(const City& city, const Money& money);
};

class City {
private:
    string cityName;
    string country;
    double latitude;
    double longitude;
public:
    City(string _cityName, string _country, double _latitude, double _longitude)
        : cityName(_cityName), country(_country), latitude(_latitude), longitude(_longitude) {}
    friend bool friendTest(const City& city, const Money& money);
};

bool friendTest(const City& city, const Money& money);


