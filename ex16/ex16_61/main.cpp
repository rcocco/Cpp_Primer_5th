#include <iostream>
#include <string>
#include "Shared_ptr.h"
using std::string;
using std::cout;
using std::endl;
int main() {
	auto p = make_Shared<string>(10, 'd');
	cout << *p << endl;
	return 0;
}