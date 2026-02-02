#include <iostream>
#include <string>
using namespace std;

class Candy {
    public:
    string name;
    double price;
    int amount;
    Candy() {
        name = "";
        price = 0;
        amount = 0;
    }
    Candy(string n, double p, int a) {
        name = n;
        price = p;
        amount = a;
    }
    Candy operator+(const Candy &c) {
        Candy temp;
        temp.name = this->name + '-' + c.name;
        temp.price = (this->price + c.price)/2;
        temp.amount = this->amount + c.amount;
        return temp;
    }
};
ostream& operator<<(ostream &cout, Candy &c) {
    cout << "c3: name-" << c.name << "; price-" << c.price << "; amount-" << c.amount << endl;
    return cout;
}

int main() {
    string name1;
    double price1;
    int amount1;
    string name2;
    double price2;
    int amount2;
    cout << "Enter name:" << endl;
    cin >> name1;
    cout << "Enter price:" << endl;
    cin >> price1;
    cout << "Enter amount:" << endl;
    cin >> amount1;
    cout << endl << "Enter name:" << endl;
    cin >> name2;
    cout << "Enter price:" << endl;
    cin >> price2;
    cout << "Enter amount:" << endl;
    cin >> amount2;
    cout << endl;
    Candy c1(name1, price1, amount1), c2(name2, price2, amount2), c3;
    c3 = c1 + c2;
    cout << c3 << endl;
}