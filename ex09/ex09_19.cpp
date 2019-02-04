#include <iostream>
#include <list>
#include <string>
using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
	list<string> slist;
	string s;
	while (cin >> s) {
		slist.push_back(s);
	}
	for (auto beg = slist.cbegin(); beg != slist.cend(); ++beg) {
		cout << *beg << endl;
	}
	return 0;
}