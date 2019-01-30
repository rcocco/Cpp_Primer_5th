#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<int> ivec(5, 0);
	vector<int>::size_type cnt = ivec.size();
	for (vector<int>::size_type ix = 0;
		ix != ivec.size(); ix++, cnt--) {
		ivec[ix] = cnt;
	}
	for (auto v : ivec) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}