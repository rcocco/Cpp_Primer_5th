#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
class Book {
	friend std::istream &read(std::istream &is, Book &item);
	friend std::ostream &print(std::ostream &os, const Book &item);
public:
	Book() = default;
	Book(const std::string &n, const std::string &b, 
		double pr,const std::string &a, const std::string p):
	name(n),bookNo(b),author(a),publisher(p),price(pr) { }
	Book(std::istream &is) {}
private:
	std::string name, bookNo, author, publisher;
	double price = 0.0;
};
std::istream &read(std::istream &is,Book &item);
std::ostream &print(std::ostream &os, const Book &item);
#endif