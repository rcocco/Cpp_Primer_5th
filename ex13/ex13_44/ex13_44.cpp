#include <iostream>
#include "String.h"
using std::cout;
using std::endl;
int main() {
	String s;
	cout << s << endl;
	String s1 = "abcde";
	cout << s1 << endl;
	String s2 = s1;
	cout << s2 << endl;
	return 0;
}