#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct DataPoint {
    int name;
    vector<int> friends;
};

int main() {
    int testCases;
    cin >> testCases;
    for (int c = 0; c < testCases; c++) {
        vector<DataPoint> citizens;
        int numOfCitizens, numOfPairs;
        cin >> numOfCitizens >> numOfPairs;
        for (int i = 0; i <= numOfCitizens; i++) {
            DataPoint dp;
            dp.name = i;
            citizens.push_back(dp);
        }
        
        for (int p = 0; p < numOfPairs; p++) {
            int n, f;
            cin >> n >> f;
            citizens.at(n).friends.push_back(f);
            citizens.at(f).friends.push_back(n);
        }

        int largestGroup = -1;
        vector<char> visited(numOfCitizens + 1, 0);
        for (int i = 1; i <= numOfCitizens; i++) {
            if (visited[i]) {
                continue;
            }
            int temp = 0;
            queue<int> myQueue;
            myQueue.push(i);
            visited[i] = 1;
            while (!myQueue.empty()) {
                int u = myQueue.front(); 
                myQueue.pop();
                temp++;
                for (int v : citizens[u].friends) {
                    if (!visited[v]) {
                        visited[v] = 1;
                        myQueue.push(v);
                    }
                }
            }
            largestGroup = max(largestGroup, temp);
        }
        cout << largestGroup << endl;
    }

    return 0;
}

// 2 3 2 1 2 2 3 10 12 1 2 3 1 3 4 5 4 3 5 4 6 5 2 2 1 7 10 1 2 9 10 8 9
