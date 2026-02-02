#include <iostream>
using namespace std;

template <class T>
class DynamicArray {
private:
	T* arrPtr;
	int currentCount;
	int maxCapacity;
public:
	DynamicArray(int capacity) {
		maxCapacity = capacity;
		arrPtr = new T[maxCapacity];
		currentCount = 0;
	}
	DynamicArray(const DynamicArray& m) {
		maxCapacity = m.maxCapacity;
		arrPtr = new T[maxCapacity];
		currentCount = m.currentCount;
		for (int i = 0; i < currentCount; i++) {
			arrPtr[i] = m.arrPtr[i];
		}
	}
	~DynamicArray() {
		delete[] arrPtr;
	}
	void pushBack(const T& data) {
		if (currentCount < maxCapacity) {
			arrPtr[currentCount] = data;
			currentCount++;
		}
		else if (currentCount >= maxCapacity) {
			cout << "Inserting new value failed: the array is full." << endl;
		}
	}
	void getMax() {
		T temp = arrPtr[0];
		for (int i = 1; i < currentCount; i++) {
			if (arrPtr[i] > temp) {
				temp = arrPtr[i];
			}
		}
		cout << "The max value of the array is: " << temp << endl;
	}
	DynamicArray operator=(const DynamicArray& other) {
		if (this != other) {
			delete[] arrPtr;
			maxCapacity = other.maxCapacity;
			currentCount = other.currentCount;
			arrPtr = new T[maxCapacity];
			for (int i = 0; i < currentCount; i++) {
				arrPtr[i] = other.arrPtr[i];
			}
		}
		return this;
	}
	T& operator[](int index) {
		return arrPtr[index];
	}
};

class IntegerClass {
private:
	int data;
public:
	IntegerClass() {
		data = 0;
	}
	IntegerClass(int v) {
		data = v;
	}
	IntegerClass operator=(const IntegerClass& other) {
		if (this != &other) {
			data = other.data;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& cout, IntegerClass& i) {
		cout << i.data << endl;
		return cout;
	}
	bool operator>(const IntegerClass& other) {
		return data > other.data;
	}
};

class ArrayHolder {
private:
	DynamicArray<int>* dynArrPtr;
	int length;
public:
	ArrayHolder() {
		dynArrPtr = NULL;
		length = 0;
	}
	ArrayHolder(int arr[], int s) {
		length = s;
		dynArrPtr = new DynamicArray<int>(length);
		for (int i = 0; i < length; i++) {
			dynArrPtr->pushBack(arr[i]);
		}
	}
	ArrayHolder(const ArrayHolder& m) {
		length = m.length;
		dynArrPtr = new DynamicArray<int>(length);
		for (int i = 0; i < length; i++) {
			dynArrPtr->pushBack((*m.dynArrPtr)[i]);
		}
	}
	~ArrayHolder() {
		delete dynArrPtr;
	}
    ArrayHolder operator=(const ArrayHolder &other) {  
       if (this != &other) {  
           delete dynArrPtr;
           length = other.length;  
           dynArrPtr = new DynamicArray<int>(length);  
           for (int i = 0; i < length; i++) {  
               dynArrPtr->pushBack((*other.dynArrPtr)[i]);
           }  
       }  
       return *this;  
    }
	friend ostream& operator<<(ostream& cout, ArrayHolder &m) {
		for (int i = 0; i < m.length; i++) {
			cout << (*m.dynArrPtr)[i] << " ";
		}
		cout << endl;
		return cout;
	}
	bool operator>(const ArrayHolder& other) {
		int minLength = min(length, other.length);
		for (int i = 0; i < minLength; i++) {
			if ((*dynArrPtr)[i] != (*other.dynArrPtr)[i]) {
				return (*dynArrPtr)[i] > (*other.dynArrPtr)[i];
			}
		}
		return length > other.length;
	}
};

int main() {
    int amount;
	DynamicArray<ArrayHolder> arr4(5);
	cout << "Input the amount of variables to store in the ArrayHolder array:" << endl;
	cin >> amount;
	int size;
	for (int i = 0; i < amount; i++) {
		cout << "Input the size of DynamicArray " << i + 1 << ":" << endl;
		cin >> size;
        int* arr = new int[size];
        cout << "Input array " << i + 1 << ":" << endl;
        for (int j = 0; j < size; j++) {
            cin >> arr[j];
        }
        ArrayHolder holder(arr, size);
        arr4.pushBack(holder);
        delete[] arr; 
	}
	arr4.getMax();

	return 0;
}