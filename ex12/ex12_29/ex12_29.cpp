#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstddef>
#include <utility>
using std::size_t;
using std::string;
using std::istream;
using std::ostream;
using std::ifstream;
using std::istringstream;
using std::vector;
using std::map;
using std::set;
using std::pair;
using std::cin;
using std::cout;
using std::endl;
void readToText(istream &is,vector<string> &text) {
	string line;
	while (getline(is, line)) {
		text.push_back(line);
	}
}
void buildMap(map<string, pair<set<size_t>, size_t>> &m,vector<string> &text) {
	for (size_t lineno = 0; lineno < text.size(); ++lineno) {
		istringstream iss(text[lineno]);
		string word;
		while (iss >> word) {
			m[word].first.insert(lineno);
			++m[word].second;
		}
	}
}
ostream& query(ostream &os,const string &word, map<string, pair<set<size_t>, size_t>> &m, vector<string> &text) {
	auto mit = m.find(word);
	if (mit != m.end()) {
		auto occur_times = mit->second.second;
		os << word << " occurs " << occur_times <<
			(occur_times > 1 ? " times" : " time") << endl;
		for (const auto &no : mit->second.first) {
			os << "\t(line " << no + 1 << ") "
				<< text[no] << endl;
		}
	}
	else {
		os << word << " occurs 0 time";
	}
	return os;
}
void runQueries(ifstream &infile) {
	vector<string> text;
	readToText(infile, text);
	map<string, pair<set<size_t>, size_t>> m;
	buildMap(m, text);
	do {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		query(cout, s, m, text) << endl;
	} while (true);
}
int main() {
	ifstream ifs("poetry.txt");
	if (ifs) {
		runQueries(ifs);
	}
	else {
		return -1;
	}
	return 0;
}