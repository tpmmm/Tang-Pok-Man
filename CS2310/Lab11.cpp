#include <iostream>
using namespace std;

template <class T>
class MyArray {
public:
	T* myArr;
	int len;
	MyArray() {
		myArr = NULL;
		len = 0;
	}
	void set() {
		if (myArr != NULL) {
			delete[] myArr;
		}
		cout << "Enter the number of elements:" << endl;
		cin >> len;
		if (len > 0) {
			myArr = new T [len];
		}
		cout << "Enter each element:" << endl;
		for (int i = 0; i < len; i++) {
			cin >> myArr[i];
		}
	}
	~MyArray() {
		if (myArr != NULL) {
			delete[] myArr;
		}
	}
	template <class U>
	friend bool operator==(const MyArray<T>& t, const MyArray<U>& u) {
		if (typeid(t) != typeid(u)) {
			return false;
		}
		if (t.len != u.len) {
			return false;
		}
		for (int i = 0; i < t.len; i++) {
			if (t.myArr[i] != u.myArr[i]) {
				return false;
			}
		}
		return true;
	}
};

template <class T>
ostream& operator<<(ostream& cout, const MyArray<T>& arr) {
	for (int i = 0; i < arr.len; i++) {
		cout << arr.myArr[i] << " ";
	}
	return cout;
}

template <class T, class U>
void f(MyArray<T>& arr1, MyArray<U>& arr2) {
	arr1.set();
	arr2.set();
	cout << "arr1: " << arr1 << endl;
	cout << "arr2: " << arr2 << endl;
	if (arr1 == arr2) {
		cout << "arr1 equals to arr2" << endl;
	}
	else {
		cout << "arr1 does not equal to arr2" << endl;
	}
 
}

int main() {
	int c;
	cout << "1) T: int, U: int" << endl;
	cout << "2) T: int, U: char" << endl;
	cout << "3) T: int, U: double" << endl;
	cout << "Input 1, 2 or 3:" << endl;
	cin >> c;
	switch (c) {
		case 1: {
				MyArray<int> arr1;
				MyArray<int> arr2;
				f(arr1, arr2);
				break;
		}
		case 2: {
				MyArray<int> arr1;
				MyArray<char> arr2;
				f(arr1, arr2);
				break;
		}
		case 3: {
			MyArray<int> arr1;
			MyArray<double> arr2;
			f(arr1, arr2);
			break;
		}
	}
	return 0;
}


