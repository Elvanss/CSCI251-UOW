#include <iostream>
#include <string>

using namespace std;

class Staff {
//Data field (1)
private:
    int staffNum;
    string lastName;
    string firstName;
    double baseSalary;
    int salesMade;
    string staffClass;
    int bonus;   
public:
    //constant static fields in the array (2)
    const static double array[9];
    //static function that display the bonus table (3)
    static void printTable() {
        cout << "-------------------------------------------" << endl;
        cout << "Sales     Class A  Class B   Class C" << endl;
        cout << "-------------------------------------------" << endl;
        cout << " 0-20     "<<array[0]<<"     "<<array[1]<<"       "<<array[2] << endl;
        cout << " 21-50    "<<array[3]<<"     "<<array[4]<<"      "<<array[5] << endl;
        cout << " 51+      "<<array[6]<<"    "<<array[7]<<"      "<<array[8] << endl;
    }

    void setField(int _staffNum, string _lastName, string _firstName, double _baseSalary, int _salesMade, string _staffClass, int _bonus) {
        staffNum = _staffNum;
        lastName = _lastName;
        firstName = _firstName;
        baseSalary = _baseSalary;
        salesMade = _salesMade;
        staffClass = _staffClass;
        bonus =_bonus;
    }

    //optional method for identifying the salesMade level
    int saleCheck() {
        int sale;
        if (salesMade >= 0 && salesMade <= 20) {
            sale = 0;
        } else if (salesMade >= 21 && salesMade <= 50) {
            sale = 1;
        } else {
            sale = -1; 
        }
        return sale;
    }

    double computeBonus() {
        Staff sale;

        if (sale.staffClass == "A") {
            if (sale.saleCheck() == 0) {
                baseSalary = baseSalary + baseSalary*array[0];
            } else if (sale.saleCheck() == 1) {
                baseSalary = baseSalary + baseSalary*array[1];
            } else if (sale.saleCheck() == -1) {
                baseSalary = baseSalary + baseSalary*array[2];
            } else {
                cout<<"Please get the correct sales made in given range!";
            }
        } else if (sale.staffClass == "B") {
            if (sale.saleCheck() == 0) {
                baseSalary = baseSalary + baseSalary*array[3];
            } else if (sale.saleCheck() == 1) {
                baseSalary = baseSalary + baseSalary*array[4];
            } else if (sale.saleCheck() == -1) {
                baseSalary = baseSalary + baseSalary*array[5];
            } else {
                cout<<"Please get the correct sales made in given range!";
            }
        } else {
            if (sale.saleCheck() == 0) {
                baseSalary = baseSalary + baseSalary*array[6];
            } else if (sale.saleCheck() == 1) {
                baseSalary = baseSalary + baseSalary*array[7];
            } else if (sale.saleCheck() == -1) {
                baseSalary = baseSalary + baseSalary*array[8];
            } else {
                cout<<"Please get the correct sales made in given range!";
            }
        }
        return baseSalary;
    }

    void displayStaff() {
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Grade: " << staffClass << "     Staff Number # " << staffNum << endl;
        cout << "Salary: $" << baseSalary << "     Sales Made: " << salesMade << endl;
        cout << "Bonus: $" << computeBonus() << endl << endl;
    }
};

 const double Staff::array[9] = {0.03, 0.02, 0.005, 0.05, 0.035, 0.015, 0.075, 0.055, 0.04};

int main () {
    //Print the table
    Staff staffTable;
    staffTable.printTable();
    //Create 2 objects
    Staff staff1;
    Staff staff2;
    //Set data field
    staff1.setField(1001, "Thomas the Tank", "Engine", 10000, 21, "A", 0);
    staff2.setField(1002, "the Builder", "Bob", 5000, 56, "C", 0);
    //Print the staff
    cout<<"-------------------------------------------"<<endl;
    staff1.displayStaff();
    staff2.displayStaff();
    return 0;
}




