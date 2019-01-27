#include <iostream>
#include <string>
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
int main() {
	Sales_data total, data;
	std::cout << "Please input sales data that have same ISBN: "
		<< std::endl;
	double price;
	if (std::cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		while (std::cin >> data.bookNo >> data.units_sold >> price) {
			data.revenue = data.units_sold * price;
			if (total.bookNo == data.bookNo) {
				total.units_sold += data.units_sold;
				total.revenue += data.revenue;
			}
			else {
				std::cerr << "Invalid data! Data must refer to the same ISBN: "
					<< total.bookNo << std::endl;
			}
		}
		std::cout << "ISBN, Volume, Revenue, Average Price: "
			<< total.bookNo << " " << total.units_sold << " "
			<< total.revenue << " ";
		if (total.units_sold != 0) {
			std::cout << total.revenue / total.units_sold << std::endl;
		}
		else {
			std::cout << "(no sales)" << std::endl;
		}
		return 0;
	}
	else {
		std::cerr << "No Data!" << std::endl;
		return -1;
	}
}