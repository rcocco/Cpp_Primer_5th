#ifndef HASPTR_H
#define HASPTR_H
#include <string>
class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr &rhs) :
		ps(new std::string(*rhs.ps)), i(rhs.i) {}
	HasPtr &operator=(const HasPtr &rhs) {
		delete ps; // No default constructor , ps won't be nullptr
		ps = new std::string(*rhs.ps);
		i = rhs.i;
		return *this;
	}
private:
	std::string *ps;
	int i;
};
#endif