#include <iostream>
using namespace std;

class Record {
    private:
    int month, day;
    double balance;
    
    public:
    void set(int m, int d, double b) {
        month = m;
        day = d;
        balance = b;
    }
    int getMonth() {
        return month;
    }
    int getDay() {
        return day;
    }
    double getBalance() {
        return balance;
    }
};

bool isSmaller(Record r1, Record r2) {
    if (r1.getMonth() < r2.getMonth()) {
        return true;
    } else if (r1.getMonth() == r2.getMonth() && r1.getDay() < r2.getDay()) {
            return true;
    } else {
        return false;
    }
}

void printRecord(Record arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i].getMonth() << " " << arr[i].getDay() << " " << arr[i].getBalance() << endl;
    }
}

void sortBalance(Record arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j].getBalance() < arr[j - 1].getBalance()) {
                Record temp;
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
    cout << "Sort according to the balance:" << endl;
    printRecord(arr, n);
}

void sortDate(Record arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (isSmaller(arr[j], arr[j - 1])) {
                Record temp;
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
    cout << "Sort according to the time:" << endl;
    printRecord(arr, n);
}

int main() {
    Record arr[30];
    int n;
    cout << "Enter the number of the records:" << endl;
    cin >> n;
    int m, d;
    double b;
    cout << "Enter the contents of each records: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> m >> d >> b;
        arr[i].set(m, d, b);
    }
    sortBalance(arr, n);
    sortDate(arr, n);
}