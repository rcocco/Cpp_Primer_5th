#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include <iostream>
#include <memory>
#include <set>
#include <string>
#include "StrVec.h"
class QueryResult {
	friend std::ostream &print(std::ostream &os, const QueryResult &qr);
public:
	using line_no = StrVec::size_t;
	QueryResult(std::string s,
		std::shared_ptr<std::set<line_no>> p,
		std::shared_ptr<StrVec> f) :
		sought(s), lines(p), file(f) {}
	std::set<line_no>::const_iterator begin() const;
	std::set<line_no>::const_iterator end() const;
	std::shared_ptr<StrVec> get_file();
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<StrVec> file;
};
std::ostream &print(std::ostream &os, const QueryResult &qr);
#endif