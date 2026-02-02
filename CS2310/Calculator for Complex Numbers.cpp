#include <iostream>
using namespace std;

class MyComplex {
public:
	int real;
	int imag;
	MyComplex() {
		real = 0;
		imag = 0;
	}
	MyComplex(int n1, int n2) {
		real = n1;
		imag = n2;
	}
};

class Calculator {
protected:
	MyComplex num1;
	MyComplex num2;
public:
	void set(MyComplex n1, MyComplex n2) {
		num1 = n1;
		num2 = n2;
	}
	virtual void getResult() {
	}
};
void show(MyComplex n) {
	if (n.real == 0 && n.imag == 0) {
		cout << "0)";
	}
	else if (n.real == 0 && n.imag != 0) {
		cout << n.imag << "i)";
	}
	else if (n.real != 0 && n.imag == 0) {
		cout << n.real << ")";
	}
	else {
		bool ntive = false;
		if (n.imag < 0) {
			ntive = true;
		}
		if (ntive) {
			cout << n.real << n.imag << "i)";
		}
		else {
			cout << n.real << "+" << n.imag << "i)";
		}
	}
}
class AdditionCal : public Calculator {
public:
	void getResult() {
		cout << "The result of (";
		show(num1);
		cout << "+(";
		show(num2);
		cout << " is ";
		if (num1.real + num2.real == 0 && num1.imag + num2.imag == 0) {
			cout << "0" << endl;
		}
		else if (num1.real + num2.real != 0 && num1.imag + num2.imag == 0) {
			cout << num1.real + num2.real << endl;
		}
		else if (num1.real + num2.real == 0 && num1.imag + num2.imag != 0) {
			cout << num1.imag + num2.imag << "i" << endl;
		}
		else {
			bool ntive = false;
			if (num1.imag + num2.imag < 0) {
				ntive = true;
			}
			if (ntive) {
				cout << num1.real + num2.real << num1.imag + num2.imag << "i" << endl;
			}
			else {
				cout << num1.real + num2.real << "+" << num1.imag + num2.imag << "i" << endl;
			}
		}
	}
};

class SubtractionCal : public Calculator {
public:
	void getResult() {
		cout << "The result of (";
		show(num1);
		cout << "-(";
		show(num2);
		cout << " is ";
		if (num1.real - num2.real == 0 && num1.imag - num2.imag == 0) {
			cout << "0" << endl;
		}
		else if (num1.real - num2.real != 0 && num1.imag - num2.imag == 0) {
			cout << num1.real - num2.real << endl;
		}
		else if (num1.real - num2.real == 0 && num1.imag - num2.imag != 0) {
			cout << num1.imag - num2.imag << "i" << endl;
		}
		else {
			bool ntive = false;
			if (num1.imag - num2.imag < 0) {
				ntive = true;
			}
			if (ntive) {
				cout << num1.real - num2.real << num1.imag - num2.imag << "i" << endl;
			}
			else {
				cout << num1.real - num2.real << "+" << num1.imag - num2.imag << "i" << endl;
			}
		}
	}
};

class MultiplyCal : public Calculator {
public:
	void getResult() {
		cout << "The result of (";
		show(num1);
		cout << "*(";
		show(num2);
		cout << " is ";
		if ((num1.real * num2.real - num1.imag * num2.imag == 0) && (num1.real * num2.imag + num1.imag * num2.real == 0)) {
			cout << "0" << endl;
		}
		else if ((num1.real * num2.real - num1.imag * num2.imag != 0) && (num1.real * num2.imag + num1.imag * num2.real == 0)) {
			cout << num1.real * num2.real - num1.imag * num2.imag << endl;
		}
		else if ((num1.real * num2.real - num1.imag * num2.imag == 0) && (num1.real * num2.imag + num1.imag * num2.real != 0)) {
			cout << num1.real * num2.imag + num1.imag * num2.real << "i" << endl;
		}
		else {
			bool ntive = false;
			if (num1.real * num2.imag + num1.imag * num2.real < 0) {
				ntive = true;
			}
			if (ntive) {
				cout << num1.real * num2.real - num1.imag * num2.imag << num1.real * num2.imag + num1.imag * num2.real << "i" << endl;
			}
			else {
				cout << num1.real * num2.real - num1.imag * num2.imag << "+" << num1.real * num2.imag + num1.imag * num2.real << "i" << endl;
			}
		}
	}
};

int main() {
	Calculator* cal;
	int r, i;
	cout << "Input the first operand:" << endl;
	cin >> r >> i;
	MyComplex op1(r, i);
	cout << "Input the second operand:" << endl;
	cin >> r >> i;
	MyComplex op2(r, i);
	AdditionCal a;
	cal = &a;
	a.set(op1, op2);
	cal->getResult();
	SubtractionCal s;
	cal = &s;
	s.set(op1, op2);
	cal->getResult();
	MultiplyCal m;
	cal = &m;
	m.set(op1, op2);
	cal->getResult();
	return 0;
}