#include <iostream>
#include <vector>
#include <list>
#include <string>
using std::vector;
using std::list;
using std::string;
using std::cout;
using std::endl;
template <typename ITER,typename T>
ITER mFind(ITER beg, ITER end, const T &value) {
	while (beg != end) {
		if (value == *beg) {
			return beg;
		}
		++beg;
	}
	return end;
}
int main() {
	vector<int> ivec{ 1,3,4,5,7,8 };
	cout << mFind(ivec.begin(), ivec.end(), 4) - ivec.begin() << endl;
	list<string> slist{ "aaa","bbb","ccc" };
	auto it = mFind(slist.begin(), slist.end(), "aaa");
	if (it != slist.end()) {
		cout << *it << endl;
	}
	return 0;
}