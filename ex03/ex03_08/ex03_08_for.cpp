#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
int main() {
	string s = "abcdef 12345";
	for (decltype(s.size()) index = 0; index < s.size();++index) {
		s[index] = 'X';
	}
	cout << s << endl;
	return 0;
}