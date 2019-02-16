#include <iostream>
#include "Screen.h"
using std::cout;
using std::endl;
int main() {
	Screen<5, 5> a('-');
	a.set(2, 4, 'q').move(1, 2).set('n').display(cout);
	return 0;
}