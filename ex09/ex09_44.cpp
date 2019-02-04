#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cout;
using std::endl;
void replaceAll(string &s, const string &oldVal, const string &newVal) {
	auto oldValSize = oldVal.size();
	if (s.size() < oldValSize) {
		return;
	}
	auto newValSize = newVal.size();
	for (string::size_type i = 0; i <= s.size() - oldValSize;) {
		if (oldVal == s.substr(i, oldValSize)) {
			s.replace(i, oldValSize, newVal);
			i += newValSize;
		}
		else {
			++i;
		}
	}
}
int main() {
	vector<string> svec1 = { "thothvovtho","tho","th" };
	for (auto &s : svec1) {
		replaceAll(s, "tho", "though");
	}
	for (const auto &s : svec1) {
		cout << s << endl;
	}
	vector<string> svec2 = { "thruvthru","thru","thr" };
	for (auto &s : svec2) {
		replaceAll(s, "thru", "through");
	}
	for (const auto &s : svec2) {
		cout << s << endl;
	}
	return 0;
}