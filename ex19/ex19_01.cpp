#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <new>
using std::size_t;
using std::bad_alloc;
using std::malloc;
using std::free;
using std::cout;
using std::endl;
void *operator new(size_t size) {
	if (void *mem = malloc(size)) {
		cout << "void *operator new(size_t)" << endl;
		return mem;
	}else {
		throw bad_alloc();
	}
}
void operator delete(void *mem) noexcept {
	cout << "void operator delete(void *)" << endl;
	free(mem);
}
int main() {
	int *p = new int(2);
	delete p;
	return 0;
}