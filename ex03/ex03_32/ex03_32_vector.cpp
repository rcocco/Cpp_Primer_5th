#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<int> ivec;
	for (int ix = 0; ix < 10; ++ix) {
		ivec.push_back(ix);
	}
	for (auto v : ivec) {
		cout << v << " ";
	}
	cout << endl;
	vector<int> another = ivec;
	for (auto v : another) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}