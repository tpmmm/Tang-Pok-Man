#include <iostream>
#include <cstring>
using namespace std;

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char arr[50];
    char temp[50] = {'\0'};
    char check[50] = {'\0'};
    int key = 0;
    cout << "The word and chars are: " << endl;
    cin.getline(arr, 50);
    int len = strlen(arr);
    int pattern;
    for (int i = len; arr[i] != ' '; i--) {
        pattern = i;
    }
    for (int i = pattern; i < len; i++) {
        check[key] = arr[i];
        key++;
    }
    for (int i = len - key - 2; i >= key - 1; i--) {
        int count = key;
        for (int j = 0; j < key; j++) {
            temp[j] = arr[i - count + 1];
            count--;
        }
        if (strcmp(temp, check) == 0) {
            cout << "The last position of " << check << " is: " << i - key + 1 << endl; 
            return 0;
        }
    }
    cout << "The last position of " << check << " is: -1" << endl; 
    return 0;
}