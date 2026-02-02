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

int main() {
	DynamicArray<int> arr1(5);
	int amount;
	cout << "Input the amount of variables to store in the int array:" << endl;
	cin >> amount;
	int intData[amount];
	cout << "Input the integers:" << endl;
	for (int i = 0; i < amount; i++) {
		cin >> intData[i];
		arr1.pushBack(intData[i]);
	}
	arr1.getMax();
	DynamicArray<char> arr2(5);
	cout << "Input the amount of variables to store in the char array:" << endl;
	cin >> amount;
	char charData;
	cout << "Input the chars:" << endl;
	for (int i = 0; i < amount; i++) {
		cin >> charData;
		arr2.pushBack(charData);
	}
	arr2.getMax();
	return 0;
}