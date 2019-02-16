#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "Quote.h"
#include <cstddef>
#include <string>
#include <iostream>
class Bulk_quote :public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double p , std::size_t qty, double disc);
	double net_price(std::size_t) const override;
	void debug() const override {
		Quote::debug();
		std::cout << "min_qty = " << min_qty
			<< " discount = " << discount << std::endl;
	}
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};
#endif