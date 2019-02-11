#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
class Book {
	friend std::istream &operator>>(std::istream &is, Book &item);
	friend std::ostream &operator<<(std::ostream &os, const Book &item);
public:
	Book():Book("","",0.0,"","") { }
	Book(const std::string &n, const std::string &no, 
		double pr,const std::string &a, const std::string p):
	name(n),bookNo(no),author(a),publisher(p),price(pr) { }
private:
	std::string name, bookNo, author, publisher;
	double price = 0.0;
};
std::istream &operator>>(std::istream &is,Book &item);
std::ostream &operator<<(std::ostream &os, const Book &item);
#endif