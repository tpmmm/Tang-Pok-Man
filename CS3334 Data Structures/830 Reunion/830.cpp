#include <bits/stdc++.h>
using namespace std;

struct DataPoint {
    int city;
    vector<int> linksTo;
};

int main() {
    int friends, cities, airlines;
    cin >> friends >> cities >> airlines; 
    vector<int> citesLiveIn;
    for (int i = 0; i < friends; i++) {
        int temp;
        cin >> temp;
        citesLiveIn.push_back(temp);
    }
    vector<DataPoint> citiesAndAirlines(cities + 1);
    for (int i = 1; i <= cities; i++) {
        citiesAndAirlines[i].city = i;
    }
    for (int i = 0; i < airlines; i++) {
        int from, landing;
        cin >> from >> landing;
        citiesAndAirlines.at(from).linksTo.push_back(landing);
    }
    vector<vector<int>> canReach(friends, vector<int>(cities + 1, 0));

    for (int i = 0; i < friends; i++) {
        vector<int> visited(cities + 1, 0);
        queue<int> myQueue;
        myQueue.push(citesLiveIn[i]);
        visited[citesLiveIn[i]] = 1;

        while (!myQueue.empty()) {
            int u = myQueue.front();
            myQueue.pop();
            canReach[i][u] = 1;

            for (int v : citiesAndAirlines[u].linksTo) {
                if (!visited[v]) {
                    visited[v] = 1;
                    myQueue.push(v);
                }
            }
        }
    }

    int answer = 0;
    for (int c = 1; c <= cities; c++) {
        bool ok = true;
        for (int f = 0; f < friends; f++) {
            if (!canReach[f][c]) {ok = false;}
        }
        if (ok) {answer++;}
    }

    cout << answer << endl;
    return 0;
}