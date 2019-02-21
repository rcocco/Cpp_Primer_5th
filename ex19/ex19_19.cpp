#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "Sales_data.h"
using std::cout;
using std::endl;
using std::find_if;
using std::bind;
using std::placeholders::_1;
using std::vector;
bool price_larger(const Sales_data &item, double price) {
	return item.avg_price() > price;
}
vector<Sales_data>::const_iterator 
findFirstLargerAvgPrice(const vector<Sales_data> &vec, double price) {
	return find_if(vec.begin(), vec.end(), 
		bind(price_larger, _1, price));
}
int main() {
	vector<Sales_data> vec{ {"001X",5,20.0},{"002X",3,18.0},
	{"003X",4,25.0},{"004X",10,30.0} };
	auto it = findFirstLargerAvgPrice(vec, 20.0);
	cout << *it << endl;
	return 0;
}
