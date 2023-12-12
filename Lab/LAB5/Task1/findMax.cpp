// finMax.cpp
#include<iostream>
using namespace std;

template<typename T>
T findMax(T& a, T& b){
    return (a>b) ? a : b;
}

int main(){
    int a = 20;
    int b = 50;
    char a1= a;
    char a2 = b;
    float aX= 3.12f;
    float bX = 3.13f;
    double aY = 1.11;
    double bY = 2.22;
    cout << findMax<int>(a, b)<<endl;
    cout << findMax<char>(a1, a2)<<endl;
    cout << findMax<float>(aX, bX)<<endl;
    cout << findMax(aY, bY)<<endl;
    return 0;
}