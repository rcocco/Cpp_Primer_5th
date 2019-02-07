#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <cstddef>
using std::map;
using std::string;
using std::size_t;
using std::cin;
using std::cout;
using std::endl;
string formatStr(const string &s) {
	string newStr;
	for (auto ch : s) {
		if (ispunct(ch)) continue;
		newStr += tolower(ch);
	}
	return newStr;
}
int main() {
	map<string, size_t> word_count;
	string word;
	while (cin >> word) {
		word = formatStr(word);
		++word_count[word];
	}
	for (const auto &w : word_count) {
		cout << w.first << " occurs " << w.second
			<< ((w.second > 1) ? " times" : " time")
			<< endl;
	}
	return 0;
}