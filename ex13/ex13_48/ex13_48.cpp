#include <iostream>
#include <vector>
#include "String.h"
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<String> vec;
	cout << vec.capacity() << endl;
	vec.push_back("a");
	cout << endl;
	cout << vec.capacity() << endl;
	vec.push_back("b");
	cout << endl;
	cout << vec.capacity() << endl;
	vec.push_back("c");
	cout << endl;
	cout << vec.capacity() << endl;
	vec.push_back("d");
	return 0;
}