#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<int> ivec = { 1,2,3,4,5 };
	for (auto &v : ivec) {
		v = v % 2 ? 2 * v : v;
	}
	for (auto v : ivec) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}