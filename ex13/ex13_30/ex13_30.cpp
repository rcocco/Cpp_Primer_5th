#include <iostream>
#include "HasPtr.h"
using std::cout;
using std::endl;
int main() {
	HasPtr s1("abc");
	HasPtr s2("def");
	swap(s1, s2);
	return 0;
}