#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
vector<int>::iterator findElem(vector<int>::iterator beg, vector<int>::iterator end, int v) {
	while (beg != end) {
		if (*beg == v) {
			return beg;
		}
		++beg;
	}
	return end;
}
vector<int>::const_iterator findElem(vector<int>::const_iterator beg, vector<int>::const_iterator end, int v) {
	while (beg != end) {
		if (*beg == v) {
			return beg;
		}
		++beg;
	}
	return end;
}
int main() {
	vector<int> ivec = { 2,4,6,8,10 };
	auto ret1 = findElem(ivec.begin(), ivec.end(), 3);
	cout << (ret1 != ivec.end() ? *ret1 : -1) << endl;
	auto ret2 = findElem(ivec.cbegin(), ivec.cend(), 6);
	cout << (ret2 != ivec.cend() ? *ret2 : -1) << endl;
	return 0;
}