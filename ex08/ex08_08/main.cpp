#include <iostream>
#include <fstream>
#include <string>
#include "Sales_data.h"
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
int main(int argc, char *argv[]) {
	if (argc != 3) {
		cerr << "Need Input and Output Files' Name." << endl;
		return -1;
	}
	ifstream input(argv[1]);
	if (!input) {
		cerr << string("Cannot open input file: ") + argv[1] << endl;
		return -1;
	}
	ofstream output(argv[2],ofstream::app);
	if (!output) {
		cerr << string("Cannot open output file: ") + argv[2] << endl;
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
				print(output, total) << endl;
				total = trans;
			}
		}
		print(output, total) << endl;
	}
	else {
		cerr << "No Data?!" << endl;
		return -1;
	}
	return 0;
}