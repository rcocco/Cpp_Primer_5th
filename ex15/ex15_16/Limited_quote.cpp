#include "Limited_quote.h"
#include <string>
#include <cstddef>
using std::string;
using std::size_t;
double Limited_quote::net_price(size_t cnt) const {
	if (cnt <= quantity) {
		return cnt * (1 - discount) * price;
	}
	else {
		return quantity * (1 - discount) * price +
			(cnt - quantity) * price;
	}
}