#include "Book.h"
#include <iostream>
using std::istream;
using std::ostream;
using std::endl;
istream &read(istream &is, Book &item) {
	is >> item.name >> item.bookNo >> item.price
		>> item.author >> item.publisher;
	return is;
}
ostream &print(ostream &os, const Book &item) {
	os << "Name: " << item.name << endl;
	os << "BookNo: " << item.bookNo << endl;
	os << "Price: " << item.price << endl;
	os << "Author: " << item.author << endl;
	os << "Publisher: " << item.publisher;
	return os;
}