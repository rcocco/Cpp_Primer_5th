#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };
	auto begin = v.begin();
	while (begin != v.end()) {
		++begin;
		// begin = v.insert(begin, 42);
		v.insert(begin, 42);
		++begin;
	}
	for (auto e : v) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}