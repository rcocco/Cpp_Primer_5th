#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
	string last,word;
	bool duplicate = false;
	while (cin >> word) {
		if (word == last) {
			duplicate = true;
			cout << word << endl;
			break;
		}
		last = word;
	}
	if (!duplicate) {
		cout << "No duplicate." << endl;
	}
	return 0;
}