#include <iostream>
#include <vector>
using namespace std;

void sink(vector<int>& h, int l) {
    int largest = l;
    int left = 2 * largest + 1; 
    int right = 2 * largest + 2; 
    int n = (int)h.size();
    if (left < n && h[left] > h[largest]) {
        largest = left;
    }

    if (right < n && h[right] > h[largest]) {
        largest = right;
    }

    if (largest != l) {
        int temp = h[largest];
        h[largest] = h[l];
        h[l] = temp;
        sink(h, largest);
    }
}

void insert(int k, vector<int>& h) {
    h.push_back(k);
    int i = (int)h.size() - 1;
    while (i != 0 && h[i] > h[(i-1)/2]) {
        int temp = h[i];
        h[i] = h[(i-1)/2];
        h[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

void pop(vector<int>& h) {
    if (h.empty()) return;
    h[0] = h.back();
    h.pop_back();
    sink(h, 0);
}

void print(vector<int>& h) {
    int sum = 0;
    for (int i = 0; i < (int)h.size(); i++) {
        sum = sum + h[i];
    }
    cout << sum << endl;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> heap;
        for (int i = 0; i < n; i++) {
            char operation;
            cin >> operation;
            int k;
            switch (operation)
            {
            case 'a':
                cin >> k;
                insert(k, heap);
                break;
            case 'p':
                pop(heap);
                break;
            case 'r':
                print(heap);
                break;  
            default:
                break;
            }
        }
    }
    return 0;
}