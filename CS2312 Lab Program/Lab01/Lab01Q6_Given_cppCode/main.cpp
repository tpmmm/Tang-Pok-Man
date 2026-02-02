#include <iostream>
#include "Shop.h"
using namespace std;

int main()
{
	Customer c1,c2;
	Shop s1,s2;

	c1.set(200); //c1 has $200 initially
	c2.set(200); //c2 has $200 initially

	s1.earn(c1, 30); //s1 earns and get $30 from c1
	s2.earn(c1, 40); //s2 earns and get $40 from c1
	s2.earn(c2, 50); //s2 earns and get $50 from c2

	cout << c1.getAmount() << endl; //expected output: 130
	cout << c2.getAmount() << endl; //expected output: 150
	cout << s1.getProfit() << endl; //expected output: 30
	cout << s2.getProfit() << endl; //expected output: 90

	return 0;
}
