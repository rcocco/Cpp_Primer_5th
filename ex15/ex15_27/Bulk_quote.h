#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "Disc_quote.h"
#include <cstddef>
#include <string>
class Bulk_quote :public Disc_quote {
public:
	using Disc_quote::Disc_quote;
	double net_price(std::size_t) const override;
};
#endif