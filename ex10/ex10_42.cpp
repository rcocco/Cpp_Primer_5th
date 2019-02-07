#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using std::string;
using std::list;
using std::cin;
using std::cout;
using std::endl;
void print(const list<string> &words) {
	for (auto s : words) {
		cout << "[" << s << "]";
	}
	cout << endl;
}
void elimDups(list<string> &words) {
	words.sort();
	cout << "After sort[size = " << words.size()
		<< "] : " << endl;
	print(words);
	words.unique();
	cout << "After unique[size = " << words.size()
		<< "] : " << endl;
	print(words);
}
int main() {
	// the quick red fox jumps over the slow red turtle
	list<string> slist;
	string s;
	while (cin >> s) {
		slist.push_back(s);
	}
	cout << "After input[size = " << slist.size()
		<< "] : " << endl;
	print(slist);
	elimDups(slist);
	return 0;
}