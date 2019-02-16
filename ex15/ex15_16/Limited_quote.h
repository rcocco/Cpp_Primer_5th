#ifndef LIMITED_QUOTE_H
#define LIMITED_QUOTE_H
#include "Disc_quote.h"
#include <cstddef>
#include <string>
class Limited_quote :public Disc_quote {
public:
	Limited_quote() = default;
	Limited_quote(const std::string& book, double price, 
		std::size_t qty, double disc):
		Disc_quote(book, price, qty, disc) {}
	double net_price(std::size_t) const override;
};
#endif