#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
	string s1,s2;
	do {
		cout << "Enter two string: ";
		cin >> s1 >> s2;
		if (s1.size() < s2.size()) {
			cout << s1 << endl;
		}
		else {
			cout << s2 << endl;
		}
		s1 = s2 = "";
	} while (cin);
	return 0;
}