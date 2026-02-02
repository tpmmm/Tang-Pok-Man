#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        queue<pair<int, int>> initial;
        vector<int> ans;
        int len;
        int magicPara;
        cin >> len >> magicPara;
        
        for (int j = 0; j < len; j++) {
            int mi;
            cin >> mi;
            initial.push({mi, j+1});
        }
        while (!initial.empty()) {
            vector<pair<int, int>> temp;
            magicPara = min((int)initial.size(), magicPara);
            for (int n = 0; n < magicPara; n++) {
                int k = initial.front().first;
                int i = initial.front().second;
                initial.pop();
                temp.push_back({k, i});
            }

            int Vmax = INT_MIN;
            int VmaxIndex = INT_MAX;
            int pos;
            for (int s = 0; s < magicPara; s++) {
                if (temp[s].first > Vmax) {
                    Vmax = temp[s].first;
                    VmaxIndex = temp[s].second;
                    pos = s;
                }       
            }

            ans.push_back(VmaxIndex);
            temp.erase(temp.begin() + pos);

            for (int s = 0; s < (int)temp.size(); s++) {
                temp[s].first = temp[s].first - 1;
                int c, i;
                c = temp[s].first;
                i = temp[s].second;
                initial.push({c, i});
            }

        }
        for (int i = 0; i < len; i++) {
            if (i != len-1) {
                cout << ans[i] << " ";
            } else {
                cout << ans[i] << endl;
            }
        }
    }
}