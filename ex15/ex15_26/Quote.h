#ifndef QUOTE_H
#define QUOTE_H
#include <string>
#include <cstddef>
#include <iostream>
class Quote {
public:
	Quote() { std::cout << "Quote()" << std::endl; }
	Quote(const std::string &book, double sales_price) :
		bookNo(book), price(sales_price) {
	}
	Quote(const Quote &rhs) :
		bookNo(rhs.bookNo), price(rhs.price) {
		std::cout << "Quote(const Quote&)" << std::endl;
	}
	Quote(Quote &&rhs) :
		bookNo(std::move(rhs.bookNo)), 
		price(std::move(rhs.price)) {
		std::cout << "Quote(Quote &&)" << std::endl;
	}
	Quote &operator=(const Quote &rhs) {
		std::cout << "Quote &operator=(const Quote &)" << std::endl;
		bookNo = rhs.bookNo;
		price = rhs.price;
		return *this;
	}
	Quote &operator=(Quote &&rhs) {
		std::cout << "Quote &operator=(Quote &&)" << std::endl;
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
		return *this;
	}
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const {
		return n * price;
	}
	virtual ~Quote() { std::cout << "~Quote()" << std::endl; }
private:
	std::string bookNo;
protected:
	double price = 0.0;
};
double print_total(std::ostream &, const Quote &, std::size_t);
#endif