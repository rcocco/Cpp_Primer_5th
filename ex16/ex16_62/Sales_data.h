#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
#include <string>
#include <cstddef>
template <class T> class std::hash;
class Sales_data {
	friend class std::hash<Sales_data>;
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
	friend std::ostream &operator<<(std::ostream&, const Sales_data&);
	friend std::istream &operator>>(std::istream&, Sales_data&);
	friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
	friend bool operator!=(const Sales_data &lhs, const Sales_data &rhs);
public:
	Sales_data() :Sales_data("", 0, 0) { }
	Sales_data(const std::string &s) :Sales_data(s,0,0) { }
	Sales_data(const std::string &s,unsigned n,double p):
		bookNo(s),units_sold(n),revenue(p*n) { }
	Sales_data(std::istream &is) { is >> *this; }
	std::string isbn() const { return bookNo; }
	Sales_data &operator+=(const Sales_data&);
	Sales_data &operator=(const std::string &);
private:
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
inline double Sales_data::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
Sales_data operator+(const Sales_data&, const Sales_data&);
std::ostream &operator<<(std::ostream&, const Sales_data&);
std::istream &operator>>(std::istream&, Sales_data&);
bool operator==(const Sales_data &lhs, const Sales_data &rhs);
bool operator!=(const Sales_data &lhs, const Sales_data &rhs);
namespace std {
	template <> struct hash<Sales_data> {
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data &s) const;
	};
	// must inline or define in class
	// otherwise Sales_data.cpp will define second times
	inline size_t hash<Sales_data>::operator()(const Sales_data &s) const {
		return hash<string>()(s.bookNo) ^
			hash<unsigned>()(s.units_sold) ^
			hash<double>()(s.revenue);
	}
}
#endif