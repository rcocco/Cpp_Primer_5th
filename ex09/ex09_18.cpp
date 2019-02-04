#include <iostream>
#include <deque>
#include <string>
using std::deque;
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
	deque<string> sdeq;
	string s;
	while (cin >> s) {
		sdeq.push_back(s);
	}
	for (auto beg = sdeq.cbegin(); beg != sdeq.cend(); ++beg) {
		cout << *beg << endl;
	}
	return 0;
}