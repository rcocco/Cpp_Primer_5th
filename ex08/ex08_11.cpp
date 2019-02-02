#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using std::istringstream;
using std::string;
using std::vector;
using std::cin;
struct PersonInfo {
	string name;
	vector<string> phones;
};
int main() {
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while (getline(cin, line)) {
		PersonInfo info;
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		record.clear();
		people.push_back(info);
	}
	return 0;
}