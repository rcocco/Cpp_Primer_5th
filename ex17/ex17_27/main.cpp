#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using std::ifstream;
using std::string;
using std::regex;
using std::smatch;
using std::sregex_iterator;
using std::cout;
using std::endl;
int main() {
	string pattern("(\\d{5})((-)?(\\d{4}))?");
	regex r(pattern);
	string s;
	string fmt = "$1-$2";
	ifstream ifs("post_codes.txt");
	if (ifs) {
		while (getline(ifs, s)) {
			for (sregex_iterator it(s.begin(), s.end(), r), end_it;
				it != end_it; ++it) {
				auto q = *it;
				if ((*it)[2].matched && !(*it)[3].matched) {
					cout << it->format(fmt) << " ";
				}
				else {
					cout << it->str() << " ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}