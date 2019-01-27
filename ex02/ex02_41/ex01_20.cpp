#include <iostream>
#include <string>
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
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