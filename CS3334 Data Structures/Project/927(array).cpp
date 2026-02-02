#include <iostream>
#include <string>
using namespace std;

void creatArray(string& line, int& i, int& n, int arr[10000]) {
    while (i < line.length()) {
        int sign = 1;
        if (line[i] == '-') {
            sign = -1;
            i++;
        }
        int num = 0;
        while (i < line.length() && line[i] >= '0' && line[i] <= '9') {
            num = num * 10 + (line[i] - '0');
            i++;
        }
        arr[n++] = sign * num;
        i++;
    }
}

void printAns(int temp[], int count) {
    if (count > 0) {
        cout << temp[0];
        for (int i = 1; i < count; i++) {
            cout << " " << temp[i];
        }
        cout << endl;
    }
}

void findUnique(string line) {
    int i = 0;
    int n = 0;
    int arr[10000];
    int temp[10000];
    int count = 0;
    creatArray(line, i, n, arr);

    bool visited[10000] = {false};
    for (int j = 0; j < n; j++) {
        bool repeated = false;
        if (visited[j]) {
            continue;
        }
        for (int k = j+1; k < n; k++) {
            if (arr[j] == arr[k]) {
                visited[k] = true;
                repeated = true;
            }
        }
        if (!repeated) {
            temp[count++] = arr[j];
        }
    }
    printAns(temp, count);
}

int main() {
    string line;
    getline(cin, line);
    while (line != "") {
        findUnique(line);
        getline(cin, line);
    }
        
    return 0;
}