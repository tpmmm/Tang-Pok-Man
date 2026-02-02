#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        stack<pair<char, int>> myStack;
        bool error = false;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            if (c == '[' || c == '{' || c == '(') {
                myStack.push({c, i + 1});
            }
            else if (c == ']' || c == '}' || c == ')') {
                if (myStack.empty()) {
                    cout << i + 1 << endl;
                    error = true;
                    break;
                }
  
                char top = myStack.top().first;
                bool match = false;
                
                if (c == ']' && top == '[') match = true;
                else if (c == '}' && top == '{') match = true;
                else if (c == ')' && top == '(') match = true;
                
                if (match) {
                    myStack.pop();
                } else {
                    cout << i + 1 << endl;
                    error = true;
                    break;
                }
            }
        }
        
        if (!error) {
            if (myStack.empty()) {
                cout << "Success" << endl;
            } else {
                stack<pair<char, int>> temp = myStack;
                pair<char, int> firstUnmatch;
                
                while (!temp.empty()) {
                    firstUnmatch = temp.top();
                    temp.pop();
                }
                cout << firstUnmatch.second << endl;
            }
        }
    }
    return 0;
}

