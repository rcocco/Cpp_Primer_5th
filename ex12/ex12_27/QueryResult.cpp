#include "QueryResult.h"
#include "TextQuery.h"
#include <iostream>
#include <memory>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <utility>
using std::string;
using std::ostream;
using std::endl;
QueryResult::QueryResult(const string &w, const TextQuery &tq) :
	word(w), text(tq.text),m(tq.m) {}
ostream &print(std::ostream &os, const QueryResult &qr) {
	auto mit = (*qr.m).find(qr.word);
	if (mit != (*qr.m).end()) {
		auto occur_times = mit->second.second;
		os << qr.word << " occurs " << occur_times <<
			(occur_times > 1 ? " times" : " time") << endl;
		for (const auto &no : mit->second.first) {
			os << "\t(line " << no+1 << ") "
				<< (*qr.text)[no] << endl;
		}
	}
	else {
		os << qr.word << " occurs 0 time";
	}
	return os;
}