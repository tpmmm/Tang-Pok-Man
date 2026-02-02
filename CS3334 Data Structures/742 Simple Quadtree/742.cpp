#include <bits/stdc++.h>
using namespace std;

int countNodes(vector<string>& image, int row, int col, int size) {
    if (size == 1) {
        return 1;
    }
    char first = image[row][col];
    bool same = true;
    for (int i = row; i < row + size && same; i++) {
        for (int j = col; j < col + size; j++) {
            if (image[i][j] != first) {
                same = false;
                break;
            }
        }
    }

    if (same) {
        return 1;
    }

    int half = size / 2;
    int nodes = 1;

    nodes += countNodes(image, row, col, half);
    nodes += countNodes(image, row, col + half, half);
    nodes += countNodes(image, row + half, col, half);
    nodes += countNodes(image, row + half, col + half, half);

    return nodes;
}

int main() {
    int k;
    while (cin >> k) {
        int n = 1 << k;
        vector<string> image(n);
        for (int i = 0; i < n; i++) {
            cin >> image[i];
        }
        int result = countNodes(image, 0, 0, n);
        cout << result << endl;
    }
    return 0;
}