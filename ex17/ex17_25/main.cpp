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
using namespace std::regex_constants;
int main() {
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(phone);
	string name;
	string line;
	string fmt = "$2.$5.$7";
	ifstream ifs("data_phones.txt");
	if (ifs) {
		while (ifs >> name && getline(ifs, line)) {
			cout << name << " " 
				<< regex_replace(line, r, fmt,format_first_only | format_no_copy) << endl;
		}
	}
	return 0;
}