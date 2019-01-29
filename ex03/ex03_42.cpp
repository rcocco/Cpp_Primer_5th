#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int main() {
	constexpr int sz = 5;
	vector<int> ivec(sz,42);
	int arr[sz];
	for (int i = 0; i < sz; ++i) {
		arr[i] = ivec[i];
	}
	for (auto v : arr) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}