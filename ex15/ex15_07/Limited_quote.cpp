#include "Limited_quote.h"
#include "Quote.h"
#include <string>
#include <cstddef>
using std::string;
using std::size_t;
Limited_quote::Limited_quote(const string &book, double p,
	size_t qty, double disc) :Quote(book, p), max_qty(qty), discount(disc) {}
double Limited_quote::net_price(size_t cnt) const {
	if (cnt <= max_qty) {
		return cnt * (1 - discount) * price;
	}
	else {
		return max_qty * (1 - discount) * price + 
			(cnt - max_qty) * price;
	}
}