#include "Customer.h"
class Shop {
private:
	int totalProfit = 0;
public:
	void earn(Customer c, int value);
	int getProfit();
};
