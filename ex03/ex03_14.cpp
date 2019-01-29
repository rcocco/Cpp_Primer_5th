#include <iostream>
#include <vector>
using std::vector;
using std::cin;
int main() {
	vector<int> ivec;
	int value;
	while (cin >> value) {
		ivec.push_back(value);
	}
	return 0;
}