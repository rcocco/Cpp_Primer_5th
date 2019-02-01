#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
void print(vector<int>::const_iterator beg,vector<int>::const_iterator end) {
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