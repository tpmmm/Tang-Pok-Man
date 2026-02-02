#include "Shop.h"
#include <iostream>
using namespace std;

void Shop::earn(Customer c, int value) {
	totalProfit += value;
	c.spend(value);
}

int Shop::getProfit() {
	return totalProfit;
}