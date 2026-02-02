#include "Customer.h"
#include <iostream>
using namespace std;

void Customer::set(int money) {
	totalMoney = money;
}

void Customer::spend(int value) {
	totalMoney -= value;
}

int Customer::getAmount() {
	return totalMoney;
}