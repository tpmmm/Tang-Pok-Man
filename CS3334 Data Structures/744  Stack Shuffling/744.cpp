#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        stack<int> A;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            A.push(x);
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            stack<int> tempA = A;
            stack<int> S;
            stack<int> B;
            vector<int> target(n);
            bool possible = true;

            for (int i = 0; i < n; i++) {
                cin >> target[i];
            }

            int p = 0;
            while (!tempA.empty() || !S.empty()) {
                if (!S.empty() && (S.top() == target[p])) {
                    B.push(S.top());
                    S.pop();
                    p++;
                } else if (!tempA.empty()) {
                    S.push(tempA.top());
                    tempA.pop();
                } else {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                cout << "Aye" << endl;
            }
            else {
                cout << "Impossible" << endl;
            }
        }
    }
    return 0;
}