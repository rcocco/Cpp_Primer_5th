#include <iostream>
#include <vector>
#include <memory>
#include "Bulk_quote.h"
#include "Quote.h"
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;
int main() {
	vector<shared_ptr<Quote>> vec;
	vec.push_back(make_shared<Bulk_quote>("001X", 10, 4, 0.2));
	vec.push_back(make_shared<Bulk_quote>("002X", 5, 10, 0.1));
	vec.push_back(make_shared<Bulk_quote>("003X", 20, 5, 0.4));
	int quantity = 10; // 80 + 45 + 120
	double sum = 0.0;
	for (const auto &p : vec) {
		sum += p->net_price(quantity);
	}
	cout << sum << endl;
	return 0;
}