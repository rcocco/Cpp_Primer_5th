#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<int> ivec1{ 1,2,3,4 };
	vector<int> ivec2{ 1,2,3,4 };
	cout << (ivec1 == ivec2 ? "true" : "false") << endl;
	return 0;
}