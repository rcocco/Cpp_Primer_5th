#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<int> ivec(10, 16);
	for (auto it = ivec.begin(); it != ivec.end(); ++it) {
		*it *= 2;
	}
	for (auto it = ivec.cbegin(); it != ivec.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}