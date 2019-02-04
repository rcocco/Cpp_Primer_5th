#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<int> vec;
	for (int i = 0; i < 30; ++i) {
		cout << "capacity: " << vec.capacity()
			<< " size: " << vec.size() << endl;
		for (auto s = vec.size(), c = vec.capacity(); s <= c; ++s) {
			vec.push_back(42);
		}
	}
	return 0;
}