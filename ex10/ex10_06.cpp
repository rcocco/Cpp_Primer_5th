#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<int> ivec = { 1,2,3,4,5 };
	std::fill_n(ivec.begin(), ivec.size(), 0);
	for (auto v : ivec) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}