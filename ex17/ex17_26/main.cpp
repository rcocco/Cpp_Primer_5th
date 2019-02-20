#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using std::ifstream;
using std::string;
using std::regex;
using std::sregex_iterator;
using std::cout;
using std::endl;
int main() {
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(phone);
	string name;
	string line;
	string fmt = "$2.$5.$7 ";
	ifstream ifs("data_phones.txt");
	if (ifs) {
		while (ifs >> name && getline(ifs, line)) {
			cout << name << " ";
			sregex_iterator it(line.begin(), line.end(), r), end_it;
			if (it != end_it) {
				string first = it->format(fmt);
				++it;
				if (it != end_it) {
					for (; it != end_it; ++it) {
						cout << it->format(fmt);
					}
				}
				else {
					cout << first;
				}
			}
			cout << endl;
		}
	}
	return 0;
}