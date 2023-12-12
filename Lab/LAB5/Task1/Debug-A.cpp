// Get the average of an array
//Error 1: missing #
#include<iostream>
//Error 2: typo mistake ->"std"
using namespace std;

//Error: className should changed to class
template<class T>
int getMedNum(T *arr, size_t n){
    T sum = 0;
    //should be an plus calculation
    for (size_t i = 0; i<n; i++){
        sum += arr[i];
    }
    if (n>0) {
        return 1*sum/n;
    }
    else return 100;
}

int main(){
    //{} typo in array
    int arrInt[]={1,2,4,6,3,-2};
    double arrDou[]={1.11,2.22,3.11,4.22};

//It should call the arrays instead of variables in declaration
    double aInt=getMedNum<int>(arrInt, sizeof(arrInt)/sizeof(int));
    double aDou=getMedNum<double>(arrDou, sizeof(arrDou)/sizeof(double));

//missing keyword "a"
    cout<<"The average of integer array: "<<aInt<<endl;
    cout<<"The average of double array: "<<aDou<<endl;
    return 0;
}