#include <bits/stdc++.h>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    int numOfWeapons, maxWeight;
    for (int i = 0; i < testCases; i++) {
        vector<int> weapons;
        cin >> numOfWeapons >> maxWeight;
        for (int j = 0; j < numOfWeapons; j++) {
            int temp;
            cin >> temp;
            weapons.push_back(temp);
        }
        sort(weapons.begin(), weapons.end());
        int carry = 0;
        int pos = 0;
        while (carry < maxWeight) {
            if (carry + weapons[pos] <= maxWeight) {
                carry = carry + weapons[pos];
                pos++;
            } else {
                break;
            }
        }
        cout << pos << endl;
    }
    return 0;
}