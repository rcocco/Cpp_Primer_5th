#include <iostream>
#include "Sales_data.h"
using std::cin;
using std::cout;
using std::endl;
int main() {
	Sales_data s1;
	print(cout, s1) << endl;
	Sales_data s2("0-201-70353-X");
	print(cout, s2) << endl;
	Sales_data s3("0-201-82470-1", 4, 45.39);
	print(cout, s3) << endl;
	Sales_data s4(cin);
	print(cout, s4) << endl;
	return 0;
}