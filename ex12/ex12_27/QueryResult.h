#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include <iostream>
#include <memory>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <utility>
class TextQuery;
class QueryResult {
	friend std::ostream &print(std::ostream &os, const QueryResult &qr);
public:
	typedef std::vector<std::string>::size_type size_type;
	QueryResult(const std::string &w,const TextQuery &tq);
private:
	std::string word;
	std::shared_ptr<std::vector<std::string>> text;
	std::shared_ptr<std::map<std::string, std::pair<std::set<size_type>, size_type>>> m;
};
std::ostream &print(std::ostream &os, const QueryResult &qr);
#endif