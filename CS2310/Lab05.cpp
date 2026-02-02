#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int temp;
    if (a < b) {
        temp = a; 
        a = b;
        b = temp;
    }
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b, int c) {
    return a * b / c;
}

int main() {
    int a, b;
    cout << "Enter the two integers:" << endl;
    cin >> a >> b;
    int c = gcd(a, b);
    int d = lcm(a, b, c);
    cout << "The GCD of "<< a << " and " << b << " is: " << c << endl;
    cout << "The LCM of "<< a << " and " << b << " is: " << d << endl;
    return 0;
}