#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <tuple>
class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	using QueryResult = std::tuple<std::string, std::shared_ptr<std::set<line_no>>, std::shared_ptr<std::vector<std::string>>>;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string &sought) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};
std::ostream &print(std::ostream &os, const TextQuery::QueryResult &qr);
#endif