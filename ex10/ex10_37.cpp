#include <iostream>
#include <vector>
#include <list>
using std::vector;
using std::list;
using std::cout;
using std::endl;
int main() {
	vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
	// [3,8) -> [2,7)
	int begPos = 3, endPos = 8;
	int rbegPos = vec.size() - endPos;
	int rendPos = vec.size() - begPos;
	list<int> ilist(vec.crbegin() + rbegPos, vec.crbegin() + rendPos);
	for (auto v : ilist) {
		cout << v << endl;
	}
	return 0;
}