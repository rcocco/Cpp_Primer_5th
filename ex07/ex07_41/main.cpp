#include <iostream>
#include "Sales_data.h"
using std::cin;
using std::cout;
using std::endl;
int main() {
	Sales_data s1;
	cout << endl;
	Sales_data s2("0-201-70353-X");
	cout << endl;
	Sales_data s3("0-201-82470-1", 4, 45.39);
	cout << endl;
	Sales_data s4(cin);
	cout << endl;
	return 0;
}