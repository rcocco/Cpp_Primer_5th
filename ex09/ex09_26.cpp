#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::begin;
using std::end;
int main() {
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	vector<int> ivec(begin(ia), end(ia));
	list<int> ilist(begin(ia), end(ia));
	for (auto beg = ivec.begin(); beg != ivec.end();) {
		if (*beg % 2 == 0) {
			beg = ivec.erase(beg);
		}
		else {
			++beg;
		}
	}
	for (auto beg = ilist.begin(); beg != ilist.end();) {
		if (*beg % 2) {
			beg = ilist.erase(beg);
		}
		else {
			++beg;
		}
	}
	for (auto v : ivec) {
		cout << v << " ";
	}
	cout << endl;
	for (auto v : ilist) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}