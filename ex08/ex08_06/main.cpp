#include <iostream>
#include <fstream>
#include <string>
#include "Sales_data.h"
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::string;
int main(int argc,char *argv[]) {
	if (argc != 2) {
		cerr << "No File Name." << endl;
		return -1;
	}
	ifstream input(argv[1]);
	if (!input) {
		cerr << string("Cannot open file: ") + argv[1] << endl;
		return -1;
	}
	Sales_data total;
	if (read(input, total)) {
		Sales_data trans;
		while (read(input, trans)) {
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
		cerr << "No Data?!" << endl;
		return -1;
	}
	return 0;
}