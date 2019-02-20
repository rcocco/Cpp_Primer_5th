#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>
using std::istringstream;
using std::ostringstream;
using std::istream;
using std::ifstream;
using std::string;
using std::vector;
using std::regex;
using std::smatch;
using std::regex_match;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
struct PersonInfo {
	string name;
	vector<string> phones;
};
bool valid(const smatch &m) {
	if (m[1].matched) {
		return m[3].matched
			&& (!m[4].matched || m[4].str() == " ");
	}
	else {
		return !m[3].matched
			&& m[4].str() == m[6].str();
	}
}
bool valid(const string &s) {
	static string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	static regex r(phone);
	smatch m;
	if (regex_match(s, m, r)) {
		return valid(m);
	}
	else {
		return false;
	}
}
string format(const string &phone) {
	return phone;
}
int main() {
	string line, word;
	vector<PersonInfo> people;
	ifstream input("data_phones.txt");
	if (input) {
		while (getline(input, line)) {
			PersonInfo info;
			istringstream record(line);
			getline(record, info.name, ',');
			while (getline(record, word, ',')) {
				info.phones.push_back(word);
			}
			people.push_back(info);
		}
	}
	for (const auto &entry : people) {
		ostringstream formatted, badNums;
		for (const auto &nums : entry.phones) {
			if (!valid(nums)) {
				badNums << " " << nums;
			}
			else {
				formatted << " " << format(nums);
			}
		}
		if (badNums.str().empty()) {
			cout << entry.name << " "
				<< formatted.str() << endl;
		}
		else {
			cerr << "input error: " << entry.name
				<< " invalid number(s) " << badNums.str()
				<< endl;
		}
	}
	return 0;
}