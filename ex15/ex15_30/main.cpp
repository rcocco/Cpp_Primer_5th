#include <iostream>
#include "Bulk_quote.h"
#include "Quote.h"
#include "Basket.h"
using std::cout;
using std::endl;
int main() {
	Basket basket;
	int quantity = 10;
	for (int i = 0; i < quantity; ++i) {
		basket.add_item(Bulk_quote("001X", 10, 4, 0.2));
		basket.add_item(Bulk_quote("002X", 5, 10, 0.1));
		basket.add_item(Bulk_quote("003X", 20, 5, 0.4));
	}
	basket.total_receipt(cout);
	return 0;
}