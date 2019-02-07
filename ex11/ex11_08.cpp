#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
	vector<string> words;
	string word;
	while (cin >> word) {
		if (find(words.cbegin(), words.cend(), word) == words.cend()) {
			words.push_back(word);
		}
	}
	for (const auto &w : words) {
		cout << w << endl;
	}
	return 0;
}