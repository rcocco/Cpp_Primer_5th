#include <iostream>
#include <string>
#include <cctype>
using std::string;
using std::cout;
using std::endl;
bool hasUpper(const string &s) {
	for (auto ch : s) {
		if (isupper(ch)) {
			return true;
		}
	}
	return false;
}
void toupper(string &s) {
	for (auto &ch : s) {
		ch = toupper(ch);
	}
}
int main() {
	string s = "asjdDsdiji";
	cout << hasUpper(s) << endl;
	toupper(s);
	cout << s << endl;
	return 0;
}