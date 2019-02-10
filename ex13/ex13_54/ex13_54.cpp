#include <iostream>
#include "HasPtr.h"
using std::cout;
using std::endl;
int main() {
	HasPtr hp1("ddd");
	HasPtr hp2("qqq");
	hp1 = hp2;
	hp1 = std::move(hp2);
	return 0;
}