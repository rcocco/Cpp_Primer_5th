#include <iostream>
#include <string>
#include <regex>
using std::string;
using std::regex;
using std::sregex_iterator;
using std::cout;
using std::endl;
int main() {
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern, regex::icase);
	string file = "receipt freind theif receive";
	for (sregex_iterator it(file.begin(), file.end(), r), end_it;
		it != end_it; ++it) {
		cout << it->str() << endl;
	}
	return 0;
}