#include <cstring>
#include <iostream>
using namespace std;


int stringCompare(char *str1, char *str2) {
	int length = strlen(str1);
	for (int i = 0; i < length; i++) {
		if (str1[i] > str2[i]) {
			return 1;
		}
		else if (str1[i] < str2[i]) {
			return -1;
		}
	}
	if (strlen(str1) < strlen(str2)) {
		return -1;
	}
	else if (strlen(str1) > strlen(str2)){
		return 1;
	}
	return 0;
}


int main() {
	char str1[100], str2[100];
	cout << "Enter the first string:" << endl;
	cin >> str1;
	cout << "Enter the second string:" << endl;
	cin >> str2;
	int c = stringCompare(str1, str2);
	switch (c) {
	case 1:
		cout << "The first string is larger." << endl;
		break;
	case 0:
		cout << "The two strings are equal." << endl;
		break;
	case -1:
		cout << "The second string is larger." << endl;
		break;
	}
	return 0;
}