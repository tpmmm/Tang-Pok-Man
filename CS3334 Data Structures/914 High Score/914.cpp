#include <iostream>
#include <string>
using namespace std;

int moves(const string &s) {
    int len = s.length();
    int vertical = 0;
    for (char c : s) {
        int d = c - 'A';
        vertical += min(d, 26 - d);
    }
    if (vertical == 0) {
        return 0;
    }
    int hori = len - 1;
    for (int i = 0; i < len; ++i) {
        int next = i + 1;
        while (next < len && s[next] == 'A') {
            next++;
        }
        hori = min(hori, i + len - next + min(i, len - next));
    }

    return vertical + hori;
}

int main() {
    int cases;
    string s;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        cin >> s;
        cout << moves(s) << endl;
    }
    return 0;
}