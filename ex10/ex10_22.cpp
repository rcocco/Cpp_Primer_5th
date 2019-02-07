#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using std::string;
using std::vector;
using std::bind;
using namespace std::placeholders;
using std::cin;
using std::cout;
using std::endl;
bool isShorterThan(const string &s, string::size_type sz) {
	return s.size() <= sz;
}
int main() {
	vector<string> words;
	string s;
	while (cin >> s) {
		words.push_back(s);
	}
	auto count = count_if(words.begin(), words.end(),
		bind(isShorterThan,_1,6));
	cout << count << endl;
	return 0;
}