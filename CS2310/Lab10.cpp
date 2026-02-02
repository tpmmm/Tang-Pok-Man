#include <iostream>
#include <iomanip>
using namespace std;

class Calculator {
	protected:
		double num1;
		double num2;
	public:
		void set(double n1, double n2) {
			num1 = n1;
			num2 = n2;
		}
		virtual void getResult() {
		}
};
class AdditionCal : public Calculator {
	public:
		void getResult() {
			if (num2 < 0) {
				cout << "The result of " << num1 << "+(" << num2 << ") is " << num1 + num2 << endl;
			}
			else {
				cout << "The result of " << num1 << "+" << num2 << " is " << num1 + num2 << endl;
			}
		}
};
class SubtractionCal : public Calculator {
	public:
		void getResult() {
			if (num2 < 0) {
				cout << "The result of " << num1 << "-(" << num2 << ") is " << num1 - num2 << endl;
			}
			else {
				cout << "The result of " << num1 << "-" << num2 << " is " << num1 - num2 << endl;
			}
		}
};
class MultiplyCal : public Calculator {
	public:
		void getResult() {
			if (num2 < 0) {
				cout << "The result of " << num1 << "*(" << num2 << ") is " << num1 * num2 << endl;
			}
			else {
				cout << "The result of " << num1 << "*" << num2 << " is " << num1 * num2 << endl;
			}
		}
};
class DivisionCal : public Calculator {
	public:
		void getResult() {
			if (num2 < 0) {
				cout << "The result of " << num1 << "/(" << num2 << ") is " << fixed << setprecision(2) << num1 / num2 << endl;
			}
			else if (num2 == 0) {
				cout << "The divisor can't be 0" << endl;
			}
			else {
				cout << "The result of " << num1 << "/" << num2 << " is " << fixed << setprecision(2) << num1 / num2 << endl;
			}
		}
};

int main() {
	Calculator c;
	double num1, num2;
	cout << "Input the first operand:" << endl;
	cin >> num1;
	cout << "Input the second operand:" << endl;
	cin >> num2;
	Calculator* cal;
	AdditionCal a;
	cal = &a;
	a.set(num1, num2);
	cal->getResult();
	SubtractionCal s;
	s.set(num1, num2);
	cal = &s;
	cal->getResult();
	MultiplyCal m;
	m.set(num1, num2);
	cal = &m;
	cal->getResult();
	DivisionCal d;
	d.set(num1, num2);
	cal = &d;
	cal->getResult();
}