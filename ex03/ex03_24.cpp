#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main() {
	vector<int> ivec;
	int value;
	while (cin >> value) {
		ivec.push_back(value);
	}
	if (!ivec.empty()) {
		for (auto it1 = ivec.cbegin(),it2 = ivec.cbegin() + 1;
			it2 !=ivec.end(); ++it1,++it2) {
			cout << *it1 + *it2 << " ";
		}
	}
	cout << endl;

	if (!ivec.empty()) {
		auto left = ivec.cbegin(), right = ivec.cend() - 1;
		while (left < right) {
			cout << *left + *right << " ";
			++left;
			--right;
		}
		if (left == right) {
			cout << *left;
		}
	}
	cout << endl;
	return 0;
}