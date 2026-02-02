#include <iostream>
using namespace std;
#define N 6
int main() {
    int arr[N];
    int temp;
    cout << "Enter the element in the array:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < N; i++) {
        temp = arr[i];
        int j = i - 1; 
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;        
        }    
        arr[j + 1] = temp;
    }
    cout << "The sorted array is:" << endl;
    for (int i = 0; i < N; i++) {
        cout << arr[i];
        if (i < N - 1) {
            cout << ", ";
        }
    }
    return 0;
}
