#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Sales_data.h"
using std::string;
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<Sales_data> vec{ string("0-201-70353-X"),
	string("0-201-82470-1"),string("0-201-88954-4"),
	string("0-399-82477-1"),string("0-201-78345-X") };
	sort(vec.begin(), vec.end(), 
		[](const Sales_data &s1, const Sales_data &s2) 
			{return s1.isbn() < s2.isbn(); });
	for (const auto &s : vec) {
		cout << s.isbn() << endl;
	}
	return 0;
}