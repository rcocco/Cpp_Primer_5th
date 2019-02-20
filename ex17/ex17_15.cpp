#include <iostream>
#include <string>
#include <regex>
using std::string;
using std::regex;
using std::smatch;
using std::regex_search;
using std::cin;
using std::cout;
using std::endl;
bool hasWrongSpell(const string &s,smatch &match) {
	static string pattern = "[[:alpha:]]*[^c]ei[[:alpha:]]*";
	static regex r(pattern);
	return regex_search(s,match, r);
}
int main() {
	string s;
	while (true) {
		cout << "Enter a word to check or q to quit : ";
		if (!(cin >> s) || s == "q") break;
		smatch match;
		if (hasWrongSpell(s, match)) {
			cout << "Wrong: " + match.str() << endl;
		}
		else {
			cout << "Right: " + s << endl;
		}
	}
	return 0;
}