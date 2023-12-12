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

    void moneyPrint() {
        cout<<"The currency country: "<<currencyName<<endl;
        cout<<"The unit: "<<dollarUnit<<endl;
        cout<<"The rate: "<<rate<<endl;
    }
};

class City {
private:
    string cityName;
    string country;
    double latitude;
    double longitude;
    //Money object (1)
    Money moneyObj;
public:
//Money constructor was called in City constructor (2)
    City(string _cityName, string _country, double _latitude, double _longitude, string currencyName, string country, double rate)
        : cityName(_cityName), country(_country), latitude(_latitude), longitude(_longitude), moneyObj(currencyName, country, rate) {}
    friend bool friendTest(const City& city, const Money& money);

    void totalPrint() {
        cout<<"The city name: "<<cityName<<endl;
        cout<<"The country name: "<<country<<endl;
        cout<<"The latitude: "<<latitude<<endl;
        cout<<"The longitude: "<<longitude<<endl;
        cout<<"Including:"<<endl;
        moneyObj.moneyPrint();
    }
};

bool friendTest(const City& city, const Money& money);


