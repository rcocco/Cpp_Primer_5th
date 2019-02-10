#include "Foo.h"
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
using std::sort;
Foo Foo::sorted() && {
	cout << "sorted() &&" << endl;
	sort(data.begin(), data.end());
	return *this;
}
Foo Foo::sorted() const & {
	cout << "sorted() const &" << endl;
	return Foo(*this).sorted();
	// Don't do this. Infinite recursion.
	//Foo ret(*this);
	//return ret.sorted();
}
Foo &Foo::retFoo() {
	return *this;
}
Foo Foo::retVal() {
	return Foo();
}