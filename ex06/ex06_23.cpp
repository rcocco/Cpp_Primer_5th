#include <iostream>
#include <cstddef>
#include <iterator>
using std::size_t;
using std::cout;
using std::endl;
void print(int v) {
	cout << v << endl;
}
void print(const int *beg, const int *end) {
	while (beg != end) {
		cout << *beg++ << endl;
	}
}
void print(const int ia[], size_t size) {
	for (size_t i = 0; i != size; ++i) {
		cout << ia[i] << endl;
	}
}
void print(const int(&arr)[2]) {
	for (auto elem : arr) {
		cout << elem << endl;
	}
}
int main() {
	int i = 0, j[2] = { 0, 1 };
	print(i);
	cout << endl;
	print(std::cbegin(j),std::cend(j));
	cout << endl;
	print(j, 2);
	cout << endl;
	print(j);
	return 0;
}