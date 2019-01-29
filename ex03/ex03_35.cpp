#include <iostream>
#include <iterator>
using std::begin;
using std::end;
using std::cout;
using std::endl;
int main() {
	int arr[5] = { 1,2,3,4,5 };
	for (auto b = begin(arr), e = end(arr); b != e; ++b) {
		*b = 0;
	}
	for (auto v : arr) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}