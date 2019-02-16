#include <iostream>
#include <string>
#include "Vec.h"
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
	Vec<int> ivec1{ 1,2,3,4 };
	Vec<int> ivec2 = ivec1;
	ivec1.push_back(2);
	for (auto b = ivec1.begin(); b != ivec1.end(); ++b) {
		cout << *b << endl;
	}
	cout << endl;
	cout << ivec2[2] << endl;
	Vec<string> svec1{ "aa","bb","cc" };
	Vec<string> svec2{ "aa","bb" };
	cout << endl;
	cout << (svec1 > svec2) << endl;
	svec2.resize(10, "qq");
	for (const auto &s : svec2) {
		cout << s << endl;
	}
	return 0;
}