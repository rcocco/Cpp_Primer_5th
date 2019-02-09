#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <memory>
#include "StrBlob.h"
class QueryResult;
class TextQuery {
public:
	using line_no = StrBlob::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string &sought) const;
private:
	StrBlob file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};
#endif