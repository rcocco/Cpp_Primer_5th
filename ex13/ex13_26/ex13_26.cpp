#include <iostream>
#include "StrBlob.h"
#include "StrBlobPtr.h"
using std::cout;
using std::endl;
int main() {
	StrBlob a{ "aa","bb","cc" };
	StrBlob b = a;
	a.begin().deref() = "dd";
	for (auto beg = a.begin(); beg.notEqual(a.end()); beg.incr()) {
		cout << beg.deref() << endl;
	}
	cout << endl;
	for (auto beg = b.begin(); beg.notEqual(b.end()); beg.incr()) {
		cout << beg.deref() << endl;
	}
	return 0;
}