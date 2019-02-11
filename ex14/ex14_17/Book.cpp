#include "Book.h"
#include <iostream>
using std::istream;
using std::ostream;
using std::endl;
istream &operator>>(istream &is, Book &item) {
	is >> item.name >> item.bookNo >> item.price
		>> item.author >> item.publisher;
	if (!is) {
		item = Book();
	}
	return is;
}
ostream &operator<<(ostream &os, const Book &item) {
	os << "Name: " << item.name << endl;
	os << "BookNo: " << item.bookNo << endl;
	os << "Price: " << item.price << endl;
	os << "Author: " << item.author << endl;
	os << "Publisher: " << item.publisher;
	return os;
}
bool operator==(const Book &lhs, const Book &rhs) {
	return lhs.name == rhs.name && lhs.bookNo == rhs.bookNo &&
		lhs.price == rhs.price && lhs.author == rhs.author &&
		lhs.publisher == rhs.publisher;
}
bool operator!=(const Book &lhs, const Book &rhs) {
	return !(lhs == rhs);
}