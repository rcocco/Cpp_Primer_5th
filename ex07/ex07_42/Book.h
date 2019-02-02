#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
class Book {
	friend std::istream &read(std::istream &is, Book &item);
	friend std::ostream &print(std::ostream &os, const Book &item);
public:
	Book():Book("","",0.0,"","") { }
	Book(const std::string &n, const std::string &no, 
		double pr,const std::string &a, const std::string p):
	name(n),bookNo(no),author(a),publisher(p),price(pr) { }
	Book(std::istream &is) {}
private:
	std::string name, bookNo, author, publisher;
	double price = 0.0;
};
std::istream &read(std::istream &is,Book &item);
std::ostream &print(std::ostream &os, const Book &item);
#endif