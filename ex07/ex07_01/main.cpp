#include <iostream>
#include <string>
#include "Sales_data.h"
int main() {
	Sales_data total;
	double price;
	if (std::cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		Sales_data trans;
		while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			if (total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else {
				std::cout << total.bookNo << " " << total.units_sold
					<< " " << total.revenue << " ";
				if (total.units_sold != 0) {
					std::cout << total.revenue / total.units_sold << std::endl;
				}
				else {
					std::cout << "(no sales)" << std::endl;
				}
				total = trans;
			}
		}
		std::cout << total.bookNo << " " << total.units_sold
			<< " " << total.revenue << " ";
		if (total.units_sold != 0) {
			std::cout << total.revenue / total.units_sold << std::endl;
		}
		else {
			std::cout << "(no sales)" << std::endl;
		}
	}
	else {
		std::cerr << "No Data?!" << std::endl;
		return -1;
	}
	return 0;
}