#include <iostream>
#include <initializer_list>
using std::initializer_list;
using std::cout;
using std::endl;
int sum(initializer_list<int> il) {
	int result = 0;
	for (auto v : il) {
		result += v;
	}
	return result;
}
int main() {
	cout << sum({1,2,3,4,5}) << endl;
	return 0;
}