#include <iostream>
#include <string>
#include "Sales_data.h"
using std::cin;
using std::cout;
using std::endl;
int main() {
	Sales_data total(cin);
	if (cin) {
		while (true) {
			Sales_data trans(cin);
			if (!cin) break;
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else {
		std::cerr << "No Data?!" << std::endl;
		return -1;
	}
	return 0;
}