#include <iostream>
#include "DebugDelete.h"
using std::cout;
using std::endl;
int main() {
	double *p = new double;
	DebugDelete d;
	d(p);
	return 0;
}