#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
int main() {
	string total, str;
	cin >> total;
	while (cin >> str) {
		total = total + " " + str;
	}
	cout << total << endl;
	return 0;
}