#include <iostream>
#include <list>
#include <algorithm>
using std::list;
using std::cout;
using std::endl;
int main() {
	list<int> ilist = { 1,2,0,4,0,0,7 };
	auto fz = find(ilist.crbegin(), ilist.crend(), 0);
	while (fz != ilist.crend()) {
		// show the position of fz
		// 0,0,4,0,2,1
		cout << *fz++ << endl;
	}
	return 0;
}