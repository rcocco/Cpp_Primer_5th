#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
using std::istringstream;
using std::ostringstream;
using std::ifstream;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
struct PersonInfo {
	string name;
	vector<string> phones;
};
bool valid(const string &phone) {
	if (phone.size() == 10) {
		for (char ch : phone) {
			if (!isdigit(ch)) {
				return false;
			}
		}
		return true;
	}
	return false;
}
string format(const string &phone) {
	// 1234567890 -> (123)456-7890
	string s;
	for (int i = 0; i < 10; ++i) {
		if (i == 0) s += "(";
		if (i == 3) s += ")";
		if (i == 6) s += "-";
		s += phone[i];
	}
	return s;
}
int main() {
	string line, word;
	vector<PersonInfo> people;
	ifstream input("data_phones.txt");
	if (input) {
		while (getline(input, line)) {
			PersonInfo info;
			istringstream record(line);
			record >> info.name;
			while (record >> word)
				info.phones.push_back(word);
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