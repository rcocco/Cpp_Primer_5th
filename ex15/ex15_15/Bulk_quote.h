#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "Disc_quote.h"
#include <cstddef>
#include <string>
class Bulk_quote :public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double price,
		std::size_t qty, double disc) :
		Disc_quote(book, price, qty, disc) {}
	double net_price(std::size_t) const override;
};
#endif