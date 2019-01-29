#include <iostream>
#include <cstddef>
using std::size_t;
using std::cout;
using std::endl;
int main() {
	int arr[10];
	for (size_t ix = 0; ix < 10; ++ix) {
		arr[ix] = ix;
	}
	for (auto v : arr) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}