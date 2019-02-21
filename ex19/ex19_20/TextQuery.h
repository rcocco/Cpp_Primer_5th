#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
class TextQuery {
public:
	class QueryResult {
		friend std::ostream &print(std::ostream &os, const QueryResult &qr);
	public:
		using line_no = std::vector<std::string>::size_type;
		QueryResult(std::string s,
			std::shared_ptr<std::set<line_no>> p,
			std::shared_ptr<std::vector<std::string>> f) :
			sought(s), lines(p), file(f) {}
	private:
		std::string sought;
		std::shared_ptr<std::set<line_no>> lines;
		std::shared_ptr<std::vector<std::string>> file;
	};
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string &sought) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};
std::ostream &print(std::ostream &os, const TextQuery::QueryResult &qr);
#endif