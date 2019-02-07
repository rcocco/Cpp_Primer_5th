#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main() {
	vector<string> words;
	string s;
	while (cin >> s) {
		words.push_back(s);
	}
	auto count = count_if(words.begin(), words.end(), 
		[](const string &s) 
			{return s.size() > 6; });
	cout << count << endl;
	return 0;
}