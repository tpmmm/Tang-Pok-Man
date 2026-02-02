#include <iostream>
using namespace std;

int main() {
    //user input
    int rows = 0;
    while (rows < 3) {
        cout << "Enter an integer not less than 3:" << endl;
        cin >> rows;
        if (rows >= 3) {
            cout << "The input is valid!" << endl << "The pattern is" << endl;
        } else {
            cout << "Invalid value. Input again!" << endl;
        }
    }
    
    //upper part of the pattern
    for (int i = 1; i < rows; i++) {
        //the white space
        for (int j = rows; j > i; j--) {
            cout << " ";
        }
        //the hollow triangle
        for (int k = 1; k < rows; k++) {
            if (k == 1 || k == i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    //the  middle line of the pattern
    for (int i = 0; i < rows * 2 - 1; i++) {
        cout << "*";
    }
    cout << endl;
    
    //the lower part of the pattern
    for (int i = 1; i < rows; i++) {
        //the white space
        for (int j = 1; j < rows; j++) {
            cout << " ";
        }
        //the reversed hollow triangle
        for (int k = rows - 1; k > 0; k--) {
            if (k == rows - 1 || k == i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}