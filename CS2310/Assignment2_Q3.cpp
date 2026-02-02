#include <iostream>
using namespace std;
class Combination {
private:
    int dNum;
    int cNum;
    int** pPtr;
public:
    Combination() {
        dNum = 0;
        pPtr = NULL;
        cNum = 0;
    }
    Combination(int d) {
        dNum = d;
        if (dNum == 1) {
            cNum = 6;
            pPtr = new int* [2];
            pPtr[0] = new int[cNum]; //sum
            pPtr[1] = new int[cNum]; //occurrance
            findSum1();
        }
        else if (dNum == 2) {
            cNum = 11;
            pPtr = new int* [2];
            pPtr[0] = new int[cNum]; //sum
            pPtr[1] = new int[cNum]; //occurrance
            findSum2();
        }
        else if (dNum == 3) {
            cNum = 16;
            pPtr = new int* [2];
            pPtr[0] = new int[cNum]; //sum
            pPtr[1] = new int[cNum]; //occurrance
            findSum3();
        }
        else {
            cNum = dNum * 6 - dNum + 1;
            pPtr = new int* [2];
            pPtr[0] = new int[cNum]; //sum
            pPtr[1] = new int[cNum]; //occurrance
            findSum4to12(dNum, 0, 0);
        }
    }
    ~Combination() {
        if (pPtr != NULL) {
            delete[] pPtr[0];
            delete[] pPtr[1];
            delete[] pPtr;
            pPtr = NULL;
            cout << "Memory is released" << endl;
        }
    }

    void findSum1();
    void findSum2();
    void findSum3();
    void findSum4to12(int dNum, int currentSum, int dTimes);
    /************** to be finished **************/
    void sortBySum();
    void sortByOcc();
};
void Combination::findSum1() {
    for (int i = 0; i < cNum; i++) {
        pPtr[0][i] = 6 - i;
        pPtr[1][i] = 1;
    }
}
void Combination::findSum2() {
    for (int i = 0; i < cNum; i++) {
        pPtr[0][i] = 12 - i;
        pPtr[1][i] = 0;
    }
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            int sum = i + j;
            (pPtr[1][sum - 2])++;
        }
    }
}
void Combination::findSum3() {
    for (int i = 0; i < cNum; i++) {
        pPtr[0][i] = i + 3;
        pPtr[1][i] = 0;
    }
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                int sum = i + j + k;
                (pPtr[1][sum - 3])++;
            }
        }
    }

}
void Combination::findSum4to12(int dNum, int currentSum, int dTimes) {
    if (dTimes == 0) {
        for (int i = 0; i < cNum; i++) {
            pPtr[0][i] = i + dNum;
            pPtr[1][i] = 0;
        }
    }
    if (dTimes == dNum) {
        (pPtr[1][currentSum - dNum])++;
        return;
    }

    for (int i = 1; i <= 6; i++) {
        findSum4to12(dNum, currentSum + i, dTimes + 1);
    }
}

void mySwap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Combination::sortBySum() {
    for (int i = 0; i < cNum; i++) {
        for (int j = cNum - 1; j > i; j--) {
            if (pPtr[0][j] > pPtr[0][j - 1]) {
                mySwap(&pPtr[0][j], &pPtr[0][j - 1]);
                mySwap(&pPtr[1][j], &pPtr[1][j - 1]);
            }
            else if (pPtr[0][j] == pPtr[0][j - 1] && pPtr[1][j] > pPtr[1][j - 1]) {
                mySwap(&pPtr[0][j], &pPtr[0][j - 1]);
                mySwap(&pPtr[1][j], &pPtr[1][j - 1]);
            }
        }
    }
    for (int i = 0; i < cNum; i++) {
        cout << pPtr[1][i] << " occurrence(s): " << pPtr[0][i] << endl;
    }
}
void Combination::sortByOcc() {
    for (int i = 0; i < cNum; i++) {
        for (int j = cNum - 1; j > i; j--) {
            if (pPtr[1][j] > pPtr[1][j - 1]) {
                mySwap(&pPtr[1][j], &pPtr[1][j - 1]);
                mySwap(&pPtr[0][j], &pPtr[0][j - 1]);
            }
            else if (pPtr[1][j] == pPtr[1][j - 1] && pPtr[0][j] > pPtr[0][j - 1]) {
                mySwap(&pPtr[1][j], &pPtr[1][j - 1]);
                mySwap(&pPtr[0][j], &pPtr[0][j - 1]);
            }
        }
    }
    for (int i = 0; i < cNum; i++) {
        cout << pPtr[1][i] << " occurrence(s): " << pPtr[0][i] << endl;
    }
}
void display(Combination& com) {
    int n;
    do {
        cout << "~~~~~~~~~~~~~~~~~" << endl;
        cout << "0 exit" << endl;
        cout << "1 sort by sum" << endl;
        cout << "2 sort by occurrence" << endl;
        cout << "~~~~~~~~~~~~~~~~~" << endl;
        cin >> n;
        switch (n) {
        case 0: cout << "Bye!" << endl; break;
        case 1: com.sortBySum(); break;
        case 2: com.sortByOcc(); break;
        }
        cout << endl;
    } while (n != 0);
}

int main() {
    int drawNum;
    cout << "Enter the number of draw:" << endl;
    cin >> drawNum;
    Combination com(drawNum);
    display(com);
    return 0;
}