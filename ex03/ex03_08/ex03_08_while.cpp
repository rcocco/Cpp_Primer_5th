#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
int main() {
	string s = "abcdef 12345";
	decltype(s.size()) index = 0;
	while (index < s.size()) {
		s[index] = 'X';
		++index;
	}
	cout << s << endl;
	return 0;
}