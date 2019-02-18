#include <iostream>
#include <vector>
#include <list>
#include <string>
using std::string;
using std::list;
using std::vector;
using std::ostream;
using std::cout;
using std::endl;
template <typename C>
ostream &print(ostream &os,const C &c) {
	for (auto beg = c.begin(); beg!=c.end(); ++beg) {
		os << *beg << " ";
	}
	return os;
}
int main() {
	vector<int> ivec{ 1,2,3,4,5 };
	print(cout, ivec) << endl;
	list<string> slist{ "aa","bb","cc" };
	print(cout, slist) << endl;
	string s = "abcdef";
	print(cout, s) << endl;
	return 0;
}