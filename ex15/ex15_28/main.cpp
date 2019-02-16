#include <iostream>
#include <vector>
#include "Bulk_quote.h"
#include "Quote.h"
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<Quote> vec;
	vec.push_back(Bulk_quote("001X", 10, 4, 0.2));
	vec.push_back(Bulk_quote("002X", 5, 10, 0.1));
	vec.push_back(Bulk_quote("003X", 20, 5, 0.4));
	int quantity = 10; // 100 + 50 + 200
	double sum = 0.0;
	for (const auto &p : vec) {
		sum += p.net_price(quantity);
	}
	cout << sum << endl;
	return 0;
}