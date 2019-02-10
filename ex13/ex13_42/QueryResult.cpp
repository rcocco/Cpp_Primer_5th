#include "QueryResult.h"
#include "StrVec.h"
#include <iostream>
#include <memory>
#include <map>
#include <set>
#include <string>
using std::string;
using std::set;
using std::ostream;
using std::shared_ptr;
using std::endl;
set<QueryResult::line_no>::const_iterator QueryResult::begin() const {
	return lines->cbegin();
}
set<QueryResult::line_no>::const_iterator QueryResult::end() const {
	return lines->cend();
}
shared_ptr<StrVec> QueryResult::get_file() {
	return file;
}
string make_plural(size_t ctr, const string &word, const string &ending) {
	return (ctr > 1) ? word + ending : word;
}
ostream &print(ostream &os, const QueryResult &qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "time", "s") << endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") "
		<< *(qr.file->begin() + num) << endl;
	return os;
}
