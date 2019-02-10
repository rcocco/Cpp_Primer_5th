#include "HasPtr.h"
#include <string>
using std::string;
HasPtr &HasPtr::operator=(const HasPtr &rhs) {
	++*rhs.use;
	if (--*use == 0) {
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}
HasPtr::~HasPtr() {
	if (--*use == 0) {
		delete ps;
		delete use;
	}
}