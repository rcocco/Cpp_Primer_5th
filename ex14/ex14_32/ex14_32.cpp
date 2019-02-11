#include <iostream>
#include "StrBlob.h"
using std::cin;
using std::cout;
using std::endl;
class A {
public:
	A(StrBlobPtr *pointer):p(pointer){}
	StrBlobPtr &operator->() const {
		// return StrBlobPtr, it has operator->,so 
		// A->func()  =====>
		// (*(A.operator->().operator->())).func()
		// recursive call operator->()
		// until result is a pointer

		// if return StrBlobPtr*
		// A->func()  =====> 
		// (*(A.operator->())).func()
		return *p;
	}
private:
	StrBlobPtr *p;
};
int main() {
	StrBlob vec{ "aa","bb","cc" };
	auto beg = vec.begin();
	A a(&beg);
	a->append("dd");
	cout << *beg << endl;
	return 0;
}