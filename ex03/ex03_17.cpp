#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main() {
	string str;
	vector<string> svec;
	while (cin >> str) {
		svec.push_back(str);
	}
	for (auto &s : svec) {
		for (auto &c : s) {
			c = toupper(c);
		}
		cout << s << endl;
	}
	return 0;
}