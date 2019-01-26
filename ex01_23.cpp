#include <iostream>
#include "Sales_item.h"
int main() {
	// �ٶ�ISBN����ͬ�������Ǿ���һ���
	Sales_item total;
	std::cout << "Please input sales data: "
		<< std::endl;
	if (std::cin >> total) {
		Sales_item trans;
		while (std::cin >> trans) {
			if (total.isbn() == trans.isbn()) {
				total += trans;
			}
			else {
				std::cout << "ISBN, Volume, Value, Average Price: "
					<< total << std::endl;
				total = trans;
			}
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