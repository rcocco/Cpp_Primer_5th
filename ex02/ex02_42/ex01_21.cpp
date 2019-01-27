#include <iostream>
#include <string>
#include "Sales_data.h"
int main() {
	Sales_data data1, data2;
	std::cout << "Please input sales data that have same ISBN: "
		<< std::endl;
	double price1,price2;
	std::cin >> data1.bookNo >> data1.units_sold >> price1
		>> data2.bookNo >> data2.units_sold >> price2;
	data1.revenue = data1.units_sold * price1;
	data2.revenue = data2.units_sold * price2;
	if (data1.bookNo == data2.bookNo) {
		unsigned totalCnt = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;
		std::cout << "ISBN, Volume, Revenue, Average Price: "
			<< data1.bookNo << " " << totalCnt << " "
			<< totalRevenue << " ";
		if (totalCnt != 0) {
			std::cout << totalRevenue / totalCnt << std::endl;
		}
		else {
			std::cout << "(no sales)" << std::endl;
		}
		return 0;
	}
	else {
		std::cerr << "Data must refer to the same ISBN"
			<< std::endl;
		return -1;
	}
}