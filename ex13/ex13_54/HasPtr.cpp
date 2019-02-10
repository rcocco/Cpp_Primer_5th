#include "HasPtr.h"
#include <string>
using std::string;
HasPtr &HasPtr::operator=(const HasPtr &rhs) {
	auto newp = new string(*rhs.ps);
	delete ps;
	ps = newp;
	i = rhs.i;
	return *this;
}
HasPtr &HasPtr::operator=(HasPtr &&rhs) {
	if (this != &rhs) {
		delete ps;
		ps = rhs.ps;
		i = rhs.i;
		rhs.ps = nullptr;
	}
	return *this;
}