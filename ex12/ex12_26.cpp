#include <iostream>
#include <memory>
#include <string>
#include <cstddef>
using std::allocator;
using std::size_t;
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
	size_t n = 5;
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	string s;
	string *q = p;
	while (q != p + n && cin >> s) {
		alloc.construct(q++, s);
	}
	const size_t size = q - p;
	for (size_t i = 0; i < size; ++i) {
		cout << p[i] << endl;
	}
	while (q != p) {
		alloc.destroy(--q);
	}
	alloc.deallocate(p, n);
	return 0;
}