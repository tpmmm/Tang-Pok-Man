#include <iostream>

using namespace std;

int main() {
    char input[1000] = {'\0'};
    char key[] = "cityu";
    int len = 0;
    cout << "Input ciphertext:" << endl;
    cin >> input;
    for (int i = 0; input[i] != '\0'; i++) {
        char currentKey = key[i % 5];
        input[i] = input[i] - currentKey + 'a' - 1;
        if (input[i] < 'a') {
            input[i] = input[i] + 26;
        }
        len++;
    }
    cout << "Output plaintext:" << endl;
    for (int i = 0; i < len; i++) {
        cout << input[i];
    }
        
    return 0;
}