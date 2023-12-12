#include <iostream>
using namespace std;

struct Cat {
    string name;
    string breed;
    int age;
    static const double price;

    void setCat(string a_Name, string a_Breed, int a_Age) {
        name = a_Name;
        breed = a_Breed;
        age = a_Age;
    }

    double calculatePrice() {
        double total =0;
        total = age*1.5 + price;
        return total;
    }

    void showCat() {
        cout<<"Cat: "<<name<<" is a "<<breed<<endl;
        cout<<"Its age is "<<age<<endl;
        cout<<"Insurance fee: $"<<price<<endl;
        double totalPr = calculatePrice();
        cout<<"Owning cost is: $"<<totalPr<<endl;
    }
};

const double Cat::price = 99.9;

int main() {
    Cat cat;
    cat.setCat("Tiger", "British Shorthair", 1);
    cat.calculatePrice();
    cat.showCat();

    return 0;
}




