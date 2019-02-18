#include <iostream>
#include <string>
#include <unordered_set>
#include "Sales_data.h"
using std::unordered_multiset;
using std::string;
using std::cout;
using std::endl;
int main() {
	unordered_multiset<Sales_data> SDset;
	SDset.insert(Sales_data("001X", 2, 2.0));
	SDset.insert(Sales_data("001X", 2, 2.0));
	SDset.insert(Sales_data("002X", 4, 5.0));
	for (const auto &s : SDset) {
		cout << s << endl;
	}
	return 0;
}