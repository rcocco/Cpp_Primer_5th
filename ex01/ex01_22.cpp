#include <iostream>
#include "Sales_item.h"
int main() {
	Sales_item total, item;
	std::cout << "Please input sales data that have same ISBN: "
		<< std::endl;
	if (std::cin >> total) {
		while (std::cin >> item) {
			total += item;
		}
		std::cout << "ISBN, Volume, Value, Average Price: "
			<< total << std::endl;
	}
	else {
		std::cerr << "No Data!" << std::endl;
		return -1;
	}
	return 0;
}