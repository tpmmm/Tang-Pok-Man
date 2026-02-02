#include <iostream>
using namespace std;

void arr(int size, int* top, int* left, int* right, int* bottom) {
	int** spiral = new int* [size];
	for (int i = 0; i < size; i++) {
		spiral[i] = new int[size];
	}
	cout << "Please input the matrix row by row:" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> spiral[i][j];
		}
	}
	int cnt = 1;
	cout << "The spiral form of the matrix is:" << endl;
	for (int i = 0; i <= (size - 1) * 2 + 1; i++) {
		if (cnt % 4 == 1) {
			for (int j = *top; j <= *bottom; j++) {
				cout << spiral[j][*left] << " ";
			}
			(*left)++;
			cnt++;
		}
		if (cnt % 4 == 2) {
			for (int j = *left; j <= *right; j++) {
				cout << spiral[*bottom][j] << " ";
			}
			(*bottom)--;
			cnt++;
		}
		if (cnt % 4 == 3) {
			for (int j = *bottom; j >= *top; j--) {
				cout << spiral[j][*right] << " ";
			}
			(*right)--;
			cnt++;
		}
		if (cnt % 4 == 0) {
			for (int j = *right; j >= *left; j--) {
				cout << spiral[*top][j] << " ";
			}
			(*top)++;
			cnt++;
		}

	}
	for (int i = 0; i < size; ++i) {
		delete[] spiral[i];
	}
	delete[] spiral;
	spiral = NULL;
}

int main() {
	int size;
	int temp1 = 0;
	int temp2 = 0;
	cout << "Please input the size of the matrix:" << endl;
	cin >> size;
	int temp3 = size - 1;
	int temp4 = size - 1;
	int& t = temp1;
	int& l = temp2;
	int& r = temp3;
	int& b = temp4;
	arr(size, &t, &l, &r, &b);
	return 0;
}