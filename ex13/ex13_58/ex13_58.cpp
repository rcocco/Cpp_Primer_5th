#include <iostream>
#include "Foo.h"
using std::cout;
using std::endl;

int main() {
	Foo f{ 6,3,4,1,2,7 };
	f.sorted();
	return 0;
}