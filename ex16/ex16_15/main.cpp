#include <iostream>
#include "Screen.h"
using std::cin;
using std::cout;
using std::endl;
int main() {
	Screen<5, 5> a('-');
	cout << a << endl;
	cin >> a;
	cout << a << endl;
	return 0;
}