#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
    //a, b, c, are three sides of the triangle
    double a, b, c, p, area;
    cout << "Enter the first side: " << endl;
    cin >> a;
    cout << "Enter the second side: " << endl;
    cin >> b;
    cout << "Enter the third side: " << endl;
    cin >> c;
    //compute the area by Heron's formula
    p = (a + b + c) / 2;
    area = sqrt((p * (p - a) * (p - b) * (p - c)));
    //set the answer alway be in 2 decimal place
    cout << fixed;
    cout << setprecision(2);
    cout << "The area is: " << area << endl;
    return 0;
}


