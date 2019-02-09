#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <utility>
class QueryResult;
class TextQuery {
	friend class QueryResult;
public:
	typedef std::vector<std::string>::size_type size_type;
	TextQuery(std::istream&);
	QueryResult query(const std::string &word);
private:
	void readToText(std::istream&);
	void buildMap();
	std::shared_ptr<std::vector<std::string>> text;
	std::shared_ptr<std::map<std::string, std::pair<std::set<size_type>,size_type>>> m;
};
#endif