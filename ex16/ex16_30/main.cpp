#include <iostream>
#include <string>
#include "Blob.h"
using std::string;
using std::cin;
using std::cout;
using std::endl;
void f() {
	Blob<int> q{ 1,2,3,4,5 };
	Blob<int> q1 = q;
}
int main() {
	f();
	cout << endl;
	Blob<string> s{ "aa","bb","cc" };
	cout << "End of main" << endl;
	return 0;
}