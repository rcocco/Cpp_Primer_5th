#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
void print(const vector<string> &words) {
	for (auto s : words) {
		cout << "[" << s <<"]";
	}
	cout << endl;
}
void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	cout << "After sort[size = "<<words.size() 
		<< "] : " << endl;
	print(words);
	auto end_unique = unique(words.begin(), words.end());
	cout << "After unique[size = " << words.size()
		<< "] : " << endl;
	print(words);
	words.erase(end_unique, words.end());
	cout << "After erase[size = " << words.size()
		<< "] : " << endl;
	print(words);
}
int main() {
	// the quick red fox jumps over the slow red turtle
	vector<string> svec;
	string s;
	while (cin >> s) {
		svec.push_back(s);
	}
	cout << "After input[size = " << svec.size()
		<< "] : " << endl;
	print(svec);
	elimDups(svec);
	return 0;
}