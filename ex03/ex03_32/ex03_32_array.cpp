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
	int another[10];
	for (size_t ix = 0; ix < 10; ++ix) {
		another[ix] = arr[ix];
	}
	for (auto v : another) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}