#include <iostream>
#include <string>
#include "StrVec.h"
#include "Vec.h"
using std::string;
using std::cout;
using std::endl;
int main() {
	StrVec vec{ "aa","bb","cc" };
	vec.emplace_back(10, 'c');
	for (const auto &s : vec) {
		cout << s << " ";
	}
	cout << endl;
	Vec<string> svec{ "qq","ww","ee" };
	svec.emplace_back(5, 't');
	for (const auto &s : svec) {
		cout << s << " ";
	}
	return 0;
}