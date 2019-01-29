#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
int main() {
	string s = "abcdef 12345";
	for (char c : s) {
		c = 'X';
	}
	cout << s << endl;
	return 0;
}