#include <bits/stdc++.h>
using namespace std;

struct DataPoint {
    int name;
    long long numOfAudiences;
    vector<int> connectTo;
};

int main() {
    int numOfCites;
    cin >> numOfCites;
    vector<DataPoint> cities(numOfCites + 1);
    for (int i = 1; i <= numOfCites; i++) {
        cities[i].name = i;
        cities[i].numOfAudiences = 0;
    }

    for (int i = 1; i <= numOfCites; i++) {
        int audiences, temp1, temp2;
        cin >> audiences >> temp1 >> temp2;
        cities[i].numOfAudiences = audiences;
        if (temp1 !=  0) {
            cities[i].connectTo.push_back(temp1);
            cities[temp1].connectTo.push_back(i);
        }
        if (temp2 !=  0) {
            cities[i].connectTo.push_back(temp2);
            cities[temp2].connectTo.push_back(i);
        }      
    }

    long long ans = LLONG_MAX;
    for (int concert = 1; concert <= numOfCites; concert++) {
        vector<int> dist(numOfCites + 1, -1);
        queue<int> myQueue;

        myQueue.push(concert);
        dist[concert] = 0;

        while (!myQueue.empty()) {
            int u = myQueue.front();
            myQueue.pop();
            for (int v : cities[u].connectTo) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    myQueue.push(v);
                }
            }
        }

        long long totalTime = 0;
        for (int i = 1; i <= numOfCites; i++) {
            totalTime += cities[i].numOfAudiences * dist[i];
        }

        if (totalTime < ans) {
            ans = totalTime;
        }
    }
    
    cout << ans << endl;
    

    return 0;
}