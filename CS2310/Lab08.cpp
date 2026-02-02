#include <iostream>
#include <cstring>
using namespace std;

class Candy {
    public:
    int price;
    int amount;
    int len;
    char* name;
    Candy() {
        price = 10;
        amount = 20;
        name = new char[strlen("strawberry") + 1];
        strcpy(name, "strawberry");
    }
    Candy(int p, int a, char* n) {
        price = p;
        amount = a;
        len = strlen(n);
        name = new char[len + 1];
        strcpy(name, n);
    }
    Candy(const Candy &c) {
        price = c.price;
        amount = c.amount;
        len = c.len;
        name = new char[len + 1];
        strcpy(name, c.name);
    }
    ~Candy() {
        delete[] name;
        name = NULL;
    }
};

int main() {
    int opt;
    char n[100];
    int p, a;
    Candy c;
    cout << "Which constructor to use (1: default, 2: parameterized, 3: copy)?" << endl;
    cin >> opt;
    cin.ignore();
    switch(opt) {
        case 1: {
            cout << "c1: name-" << c.name << "; price-" << c.price << "; amount-" << c.amount << endl;
            break;
        }
        case 2: {
            cout << "Enter name:" << endl;
            cin.getline(n, 100);
            cout << "Enter price:" << endl;
            cin >> p;
            cout << "Enter amount:" << endl;
            cin >> a;
            Candy c1(p, a, n);
            cout << "c1: name-" << c1.name << "; price-" << c1.price << "; amount-" << c1.amount << endl;
            break;
        }
        case 3: {
            cout << "Enter name:" << endl;
            cin.getline(n, 100);
            cout << "Enter price:" << endl;
            cin >> p;
            cout << "Enter amount:" << endl;
            cin >> a;
            Candy c1(p, a, n);
            Candy c2(c1);
            cout << "c1: name-" << c1.name << "; price-" << c1.price << "; amount-" << c1.amount << endl;
            cout << "c2: name-" << c2.name << "; price-" << c2.price << "; amount-" << c2.amount << endl;
            break;
        }
    }
    return 0;
}