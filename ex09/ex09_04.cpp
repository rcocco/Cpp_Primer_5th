#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
bool findElem(vector<int>::const_iterator beg, vector<int>::const_iterator end, int v) {
	while (beg != end) {
		if (*beg == v) {
			return true;
		}
		++beg;
	}
	return false;
}
int main() {
	vector<int> ivec = { 2,4,6,8,10 };
	cout << findElem(ivec.begin(), ivec.end(), 3) << endl;
	cout << findElem(ivec.cbegin(), ivec.cend(), 6) << endl;
	return 0;
}