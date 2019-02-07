#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Sales_data.h"
using std::string;
using std::vector;
using std::cout;
using std::endl;
bool hasFiveMoreChar(const string &s) {
	return s.size() >= 5;
}
int main() {
	vector<string> vec{ "And","see","the",
		"brave","day","sunk","in","hideous","night" };
	auto end = partition(vec.begin(), vec.end(), hasFiveMoreChar);
	for (auto beg = vec.begin(); beg != end; ++beg) {
		cout << *beg << endl;
	}
	return 0;
}