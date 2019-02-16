#ifndef LIMITED_QUOTE_H
#define LIMITED_QUOTE_H
#include "Quote.h"
#include <cstddef>
#include <string>
class Limited_quote :public Quote {
public:
	Limited_quote() = default;
	Limited_quote(const std::string& book, double p, std::size_t qty, double disc);
	double net_price(std::size_t) const override;
private:
	std::size_t max_qty = 0;
	double discount = 0.0;
};
#endif