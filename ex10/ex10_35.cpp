#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<int> vec = { 1,2,3,4,5,6,7 };
	for (auto it = vec.cend(); it != vec.cbegin();) {
		cout << *--it << endl;
	}
	return 0;
}