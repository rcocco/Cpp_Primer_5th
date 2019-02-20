#include <iostream>
#include <string>
#include <regex>
#include <set>
using std::string;
using std::set;
using std::regex;
using std::sregex_iterator;
using std::cout;
using std::endl;
int main() {
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern, regex::icase);
	string file = "receipt neighbor freind albeit theif receive";
	set<string> exclude{ "albeit","neighbor" };
	for (sregex_iterator it(file.begin(), file.end(), r), end_it;
		it != end_it; ++it) {
		if (exclude.find(it->str()) == exclude.end()) {
			cout << it->str() << endl;
		}
	}
	return 0;
}