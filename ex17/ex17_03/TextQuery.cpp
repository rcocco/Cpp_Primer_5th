#include "TextQuery.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <tuple>
using std::ostream;
using std::ifstream;
using std::istringstream;
using std::vector;
using std::string;
using std::map;
using std::set;
using std::shared_ptr;
using std::get;
using std::endl;
TextQuery::TextQuery(ifstream &is) :file(new vector<string>) {
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}
TextQuery::QueryResult TextQuery::query(const std::string &sought) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}
string make_plural(size_t ctr, const string &word, const string &ending) {
	return (ctr > 1) ? word + ending : word;
}
ostream &print(ostream &os, const TextQuery::QueryResult &qr) {
	os << get<0>(qr) << " occurs " << get<1>(qr)->size() << " "
		<< make_plural(get<1>(qr)->size(), "time", "s") << endl;
	for (auto num : *get<1>(qr))
		os << "\t(line " << num + 1 << ") "
		<< *(get<2>(qr)->begin() + num) << endl;
	return os;
}