#ifndef FOO_H
#define FOO_H
#include <vector>
#include <initializer_list>
class Foo {
public:
	Foo() = default;
	Foo(std::initializer_list<int> il) :data(il) {}
	Foo sorted() && ;
	Foo sorted() const &;
	Foo &retFoo();
	Foo retVal();
private:
	std::vector<int> data;
};
#endif