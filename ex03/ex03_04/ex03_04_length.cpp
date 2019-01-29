#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() > s2.size()) {
		cout << s1 << endl;
	}
	else if (s2.size() > s1.size()) {
		cout << s2 << endl;
	}
	else {
		cout << "Equal length." << endl;
	}
	return 0;
}