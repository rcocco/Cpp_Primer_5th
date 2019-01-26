#include <iostream>
#include "Sales_item.h"
int main() {
	Sales_item book;
	std::cout << "Please input sales data: " << std::endl;
	while (std::cin >> book) {
		std::cout << "ISBN, Volume, Value, Average Price: "
			<< book << std::endl;
	}
	return 0;
}