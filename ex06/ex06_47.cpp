#include <iostream>
#include <vector>
#define NDEBUG
using std::vector;
using std::cout;
using std::endl;
void print(vector<int>::const_iterator beg, vector<int>::const_iterator end) {
#ifndef NDEBUG
	cout << "Size of vector is :"
		<< end - beg << endl;
#endif
	if (beg != end) {
		cout << *beg++ << endl;
		print(beg, end);
	}
}
void print(vector<int> ivec) {
	print(ivec.cbegin(), ivec.cend());
}
int main() {
	vector<int> ivec = { 1,2,3,4,5 };
	print(ivec);
	return 0;
}