#include <bits/stdc++.h>
using namespace std;

struct DataPoint {
    int vertice;
    vector<int> edges;
};

void dfs(int u, int parent, vector<DataPoint> &tree, vector<bool> &visited, int &nodeCount, int &edgeCount, bool &cycle) {
    visited[u] = true;
    nodeCount++;

    for (int v : tree[u].edges) {
        edgeCount++;
        if (!visited[v]) {
            dfs(v, u, tree, visited, nodeCount, edgeCount, cycle);
        } else if (v != parent) {
            cycle = true;
        }
    }
}


int main() {
    int n;
    int m;
    int caseNum = 1;
    while(cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        vector<DataPoint> tree;
        for (int i = 0; i <= n; i++) {
            DataPoint dp;
            dp.vertice = i;
            tree.push_back(dp);
        }
        int target, connectTo;
        for (int j = 0; j < m; j++) {
            cin >> target >> connectTo;
            tree.at(target).edges.push_back(connectTo);
            tree.at(connectTo).edges.push_back(target);
        }
        vector<bool> visited(n + 1, false);
        int treeCount = 0;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                int nodeCount = 0, edgeCount = 0;
                bool cycle = false;

                dfs(i, -1, tree, visited, nodeCount, edgeCount, cycle);

                edgeCount /= 2;

                if (!cycle && edgeCount == nodeCount - 1) {
                    treeCount++;
                }
            }
        }
        cout << "Case " << caseNum << ": ";
        if (treeCount == 0) {
            cout << "No trees." << endl;
        }
        else if (treeCount == 1) {
            cout << "There is one tree." << endl;
        }
        else {
            cout << "A forest of " << treeCount << " trees." << endl;
        }
        caseNum++;
    }

    return 0;
}