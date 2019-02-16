#include "Quote.h"
#include <iostream>
#include <cstddef>
using std::ostream;
using std::size_t;
using std::endl;
double print_total(ostream &os, const Quote &item, size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
		<< " # sold: " << n << " total due: " << ret << endl;
	return ret;
}