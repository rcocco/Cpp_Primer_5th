#include "Sales_data.h"
using std::istream;
using std::ostream;
Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
istream &operator>>(istream &is, Sales_data &item) {
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = price * item.units_sold;
	else
		item = Sales_data();
	return is;
}
ostream &operator<<(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum += lhs;
	return sum;
}
Sales_data &Sales_data::operator=(const std::string &isbn) {
	bookNo = isbn;
	units_sold = 0;
	revenue = 0.0;
	// change bookNo, then old units_sold and revenue
	// is meaningless
	return *this;
}
bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
	return lhs.isbn() == rhs.isbn() &&
		lhs.units_sold == rhs.units_sold &&
		lhs.revenue == rhs.revenue;
}
bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
	return !(lhs == rhs);
}