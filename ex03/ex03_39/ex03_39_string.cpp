#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
int main() {
	string s1 = "test";
	string s2 = "test";
	if (s1 < s2) {
		cout << "s1 < s2";
	}
	else if (s1 > s2) {
		cout << "s1 > s2";
	}
	else {
		cout << "s1 == s2";
	}
	cout << endl;
	return 0;
}