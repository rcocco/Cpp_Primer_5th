#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <string>
#include <utility>
using std::istream;
using std::istringstream;
using std::vector;
using std::string;
using std::map;
using std::set;
using std::pair;
using std::make_shared;
TextQuery::TextQuery(istream &is) :
	text(make_shared<vector<string>>()),
	m(make_shared<map<string, pair<set<size_type>,size_type>>>()) {
	readToText(is);
	buildMap();
}
void TextQuery::readToText(istream &is) {
	string line;
	while (getline(is, line)) {
		text->push_back(line);
	}
}
void TextQuery::buildMap() {
	for (size_type lineno = 0; lineno < text->size(); ++lineno) {
		istringstream iss((*text)[lineno]);
		string word;
		while (iss >> word) {
			auto &set_size_pair = (*m)[word];
			set_size_pair.first.insert(lineno);
			++set_size_pair.second;
		}
	}
}
QueryResult TextQuery::query(const string &word) {
	return QueryResult(word, *this);
}