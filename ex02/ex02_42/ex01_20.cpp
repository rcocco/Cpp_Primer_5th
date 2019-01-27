#include <iostream>
#include <string>
#include "Sales_data.h"
int main() {
	Sales_data book;
	std::cout << "Please input sales data: " << std::endl;
	double price;
	while (std::cin >> book.bookNo >> book.units_sold >> price) {
		book.revenue = book.units_sold * price;
		std::cout << "ISBN, Volume, Revenue, Average Price: "
			<< book.bookNo << " " << book.units_sold << " "
			<< book.revenue << " " << price << std::endl;
	}
 	return 0;
}