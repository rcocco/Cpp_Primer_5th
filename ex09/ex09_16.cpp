#include <iostream>
#include <vector>
#include <list>
using std::vector;
using std::list;
using std::cout;
using std::endl;
bool isEqual(const vector<int> &ivec,const list<int> &ilist) {
	if (ivec.size() != ilist.size()) {
		return false;
	}
	auto vbeg = ivec.begin();
	auto lbeg = ilist.begin();
	while (vbeg != ivec.end() && lbeg != ilist.end()) {
		if (*vbeg != *lbeg) {
			return false;
		}
		++vbeg;
		++lbeg;
	}
	return true;
}
int main() {
	vector<int> ivec{ 1,2,3,4 };
	list<int> ilist{ 1,2,3,4 };
	cout << (isEqual(ivec,ilist) ? "true" : "false") << endl;
	return 0;
}