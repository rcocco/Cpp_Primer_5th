#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
int main() {
	string word;
	cout << "Input words: " << endl;
	while (cin >> word) {
		cout << word << endl;
	}
	return 0;
}