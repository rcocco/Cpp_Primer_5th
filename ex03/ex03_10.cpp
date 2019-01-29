#include <iostream>
#include <string>
#include <cctype>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
	string s,result;
	cin >> s;
	for (auto c : s) {
		if (!ispunct(c)) {
			result += c;
		}
	}
	cout << result << endl;
	return 0;
}