#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "Quote.h"
#include <cstddef>
#include <string>
#include <iostream>
class Bulk_quote :public Quote {
public:
	Bulk_quote() { std::cout << "Bulk_quote()" << std::endl; };
	Bulk_quote(const std::string& book, double price,
		std::size_t qty, double disc) :
		Quote(book, price), quantity(qty), discount(disc) {}
	Bulk_quote(const Bulk_quote &rhs):
		Quote(rhs),quantity(rhs.quantity),discount(rhs.discount) {
		std::cout << "Bulk_quote(const Bulk_quote &)" << std::endl;
	}
	Bulk_quote &operator=(const Bulk_quote &rhs) {
		Quote::operator=(rhs);
		std::cout << "Bulk_quote &operator=(const Bulk_quote &)" << std::endl;
		quantity = rhs.quantity;
		discount = rhs.discount;
		return *this;
	}
	Bulk_quote(Bulk_quote &&rhs):
		Quote(std::move(rhs)),
		quantity(std::move(rhs.quantity)),
		discount(std::move(rhs.discount)){
		std::cout << "Bulk_quote(Bulk_quote &&)" << std::endl;
	}
	Bulk_quote &operator=(Bulk_quote &&rhs) {
		Quote::operator=(std::move(rhs));
		std::cout << "Bulk_quote &operator=(Bulk_quote &&)" << std::endl;
		quantity = std::move(rhs.quantity);
		discount = std::move(rhs.discount);
		return *this;
	}
	~Bulk_quote() {
		std::cout << "~Bulk_quote()" << std::endl;
	}
	double net_price(std::size_t) const override;
private:
	std::size_t quantity = 0;
	double discount = 0.0;
};
#endif