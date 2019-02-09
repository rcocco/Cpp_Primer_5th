#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include <iostream>
#include <memory>
#include <set>
#include <string>
#include "StrBlob.h"
class QueryResult {
	friend std::ostream &print(std::ostream &os, const QueryResult &qr);
public:
	using line_no = StrBlob::size_type;
	QueryResult(std::string s,
		std::shared_ptr<std::set<line_no>> p,
		StrBlob f) :
		sought(s), lines(p), file(f) {}
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	StrBlob file;
};
std::ostream &print(std::ostream &os, const QueryResult &qr);
#endif