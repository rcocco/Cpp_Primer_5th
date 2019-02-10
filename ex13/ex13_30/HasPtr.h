#ifndef HASPTR_H
#define HASPTR_H
#include <iostream>
#include <string>
class HasPtr {
	friend void swap(HasPtr &lhs, HasPtr &rhs);
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr &p) :
		ps(new std::string(*p.ps)), i(p.i) {}
	HasPtr &operator=(const HasPtr &rhs);
	~HasPtr() {
		delete ps;
	}
private:
	std::string *ps;
	int i;
};
inline void swap(HasPtr &lhs, HasPtr &rhs) {
	std::cout << "swap " << *lhs.ps << " and " 
		<< *rhs.ps << std::endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}
#endif