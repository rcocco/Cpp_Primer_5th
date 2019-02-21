#include <iostream>
#include <string>
#include "Token.h"
using std::string;
using std::cout;
using std::endl;
int main() {
	Token t1, t2;
	t1 = "ss";
	t1 = t1;
	cout << t1 << endl;
	t2 = Sales_data("001X", 2, 20.0);
	t2 = t2;
	cout << t2 << endl;
	t1 = 1;
	cout << t1 << endl;
	t1 = 2.0;
	cout << t1 << endl;
	t1 = 'a';
	cout << t1 << endl;
	return 0;
}