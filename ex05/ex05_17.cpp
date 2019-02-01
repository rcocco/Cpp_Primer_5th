#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<int> ivec1 = { 0,1,1,2 };
	vector<int> ivec2 = { 0,1,1,2,3,5,8 };
	auto it1 = ivec1.cbegin(), it2 = ivec2.cbegin();
	while (it1 != ivec1.cend() && it2 != ivec2.cend() && *it1 == *it2) {
		++it1;
		++it2;
	}
	bool result = false;
	if (it1 == ivec1.cend() || it2 == ivec2.cend()) {
		result = true;
	}
	cout << (result?"true":"false") << endl;
	return 0;
}