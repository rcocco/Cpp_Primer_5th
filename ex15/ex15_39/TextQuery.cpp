#include "TextQuery.h"
#include "QueryResult.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
using std::ifstream;
using std::istringstream;
using std::vector;
using std::string;
using std::map;
using std::set;
using std::shared_ptr;
void TextQuery::ltrim(std::string &s, const std::string &charsToRemove) {
	auto pos = s.find_first_not_of(charsToRemove);
	if (pos != string::npos) {
		s.erase(s.begin(), s.begin() + pos);
	}
}
void TextQuery::rtrim(std::string &s, const std::string &charsToRemove) {
	auto pos = s.find_last_not_of(charsToRemove);
	if (pos != string::npos) {
		s.erase(s.begin() + pos + 1, s.end());
	}
}
void TextQuery::trim(std::string &s, const std::string &charsToRemove) {
	ltrim(s, charsToRemove);
	rtrim(s, charsToRemove);
}
TextQuery::TextQuery(ifstream &is) :file(new vector<string>) {
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			trim(word, " \n\t\",.?!");
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}
QueryResult TextQuery::query(const std::string &sought) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}