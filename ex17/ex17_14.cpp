#include <iostream>
#include <string>
#include <regex>
using std::string;
using std::regex;
using std::regex_error;
using std::cout;
using std::endl;
void f(const string &str) {
	try {
		regex r(str, regex::icase);
	}
	catch (regex_error e) {
		cout << e.what() << "\ncode: " << e.code() << endl;
	}
}
int main() {
	f("[[:alnum]]");
	f("[[:alnum:]");
	f("(a");
	f("+");
	return 0;
}