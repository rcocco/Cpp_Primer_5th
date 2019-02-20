#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using std::ifstream;
using std::string;
using std::regex;
using std::smatch;
using std::regex_replace;
using std::cin;
using std::cout;
using std::endl;
int main() {
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(phone);
	smatch m;
	string s;
	string fmt = "$2.$5.$7";
	ifstream ifs("data_phones.txt");
	if (ifs) {
		while (getline(ifs, s))
			cout << regex_replace(s, r, fmt) << endl;
	}
	return 0;
}