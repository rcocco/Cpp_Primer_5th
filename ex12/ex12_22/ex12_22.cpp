#include <iostream>
#include <string>
#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"
using std::string;
using std::cout;
using std::endl;
int main() {
	const StrBlob strblob{"aaa","bbb","ccc","ddd"};
	for (auto beg = strblob.cbegin(); beg.notEqual(strblob.cend()); beg.incr()) {
		cout << beg.deref() << endl;
	}
	cout << endl;
	StrBlob strblob1{ "eee","fff","ggg","hhh" };
	for (auto beg = strblob1.begin(); beg.notEqual(strblob1.end()); beg.incr()) {
		cout << beg.deref() << endl;
	}
	return 0;
}