#include "Bulk_quote.h"
#include "Quote.h"
#include <string>
#include <cstddef>
using std::string;
using std::size_t;
Bulk_quote::Bulk_quote(const string &book, double p,
	size_t qty, double disc) :Quote(book, p), min_qty(qty), discount(disc) {}
double Bulk_quote::net_price(size_t cnt) const {
	if (cnt >= min_qty) {
		return cnt * (1 - discount) * price;
	}
	else {
		return cnt * price;
	}
}