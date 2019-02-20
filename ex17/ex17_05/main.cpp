#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Sales_data.h"
using std::istream;
using std::ifstream;
using std::istringstream;
using std::ostream;
using std::vector;
using std::string;
using std::pair;
using std::make_pair;
using std::equal_range;
using std::accumulate;
using std::cin;
using std::cout;
using std::endl;
typedef pair<vector<Sales_data>::size_type,
	pair<vector<Sales_data>::const_iterator,
	     vector<Sales_data>::const_iterator>> matches;
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
	return lhs.isbn() < rhs.isbn();
}
vector<matches> findBook(const vector<vector<Sales_data>> &files,
	const string &book) {
	vector<matches> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto found = equal_range(it->cbegin(), it->cend(),
			book, compareIsbn);
		if (found.first != found.second) {
			ret.push_back(make_pair(it - files.cbegin(),
				make_pair(found.first, found.second)));
		}
	}
	return ret;
}
void reportResults(istream &in, ostream &os, 
	const vector<vector<Sales_data>> &files) {
	string s;
	while (in >> s) {
		auto trans = findBook(files, s);
		if (trans.empty()) {
			cout << s << " not found in any stores" << endl;
			continue;
		}
		for (const auto &store : trans) {
			os << "store " << store.first << " sales: "
				<< accumulate(store.second.first,
					store.second.second, Sales_data(s))
				<< endl;
		}
	}
}
vector<vector<Sales_data>> readFromFile(ifstream &ifs) {
	vector<vector<Sales_data>> vec;
	if (ifs) {
		string line;
		vector<Sales_data> store;
		while (getline(ifs, line)) {
			if (line.empty()) {
				vec.push_back(store);
				store.clear();
			}
			else {
				istringstream data(line);
				store.emplace_back(data);
			}
		}
		vec.push_back(store);
	}
	return vec;
}
int main() {
	ifstream ifs("data_sales.txt");
	auto vec = readFromFile(ifs);
	// 0-201-88954-4
	reportResults(cin, cout, vec);
	return 0;
}