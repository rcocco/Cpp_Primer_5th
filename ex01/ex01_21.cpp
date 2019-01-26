#include <iostream>
#include "Sales_item.h"
int main() {
	Sales_item item1,item2;
	std::cout << "Please input sales data that have same ISBN: "
		<< std::endl;
	std::cin >> item1 >> item2;
	std::cout << "ISBN, Volume, Value, Average Price: "
		<< item1 + item2 << std::endl;
	return 0;
}