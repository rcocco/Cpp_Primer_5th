#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 > s2) {
		cout << s1 << endl;
	}
	else if (s2 > s1) {
		cout << s2 << endl;
	}
	else {
		cout << "Equal." << endl;
	}
	return 0;
}