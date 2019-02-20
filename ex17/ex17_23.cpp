#include <iostream>
#include <string>
#include <regex>
using std::string;
using std::regex;
using std::regex_match;
using std::cin;
using std::cout;
using std::endl;
int main() {
	string pattern("\\d{5}((-?)(\\d{4}))?");
	string code;
	regex r(pattern);
	while (true) {
		cout << "Enter post code to check or q to quit: ";
		if (!(cin >> code) || code == "q") break;
		if (regex_match(code, r)) {
			cout << "Valid: " << code << endl;
		}
		else {
			cout << "Invalid: " << code << endl;
		}
	}
	return 0;
}