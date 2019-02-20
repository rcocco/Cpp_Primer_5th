#include <iostream>
using std::cout;
using std::endl;
class Class { };
class Base : public Class {
public:
	Base() :v(0) {} // implicit use Class default constructor
	Base(int num) :v(num) {}
	Base(const Base &rhs) :v(rhs.v) {}
	int v;
};
class D1 : virtual public Base {
public:
	D1() :Base() {}
	D1(int num) :Base(num) {}
	D1(const D1 &rhs) :Base(rhs) {}
};
class D2 : virtual public Base {
public:
	D2() :Base() {}
	D2(int num) :Base(num) {}
	D2(const D2 &rhs) :Base(rhs) {}
};
class MI : public D1, public D2 {
public:
	MI() :D1(), D2() {}
	MI(int num) :D1(num), D2(num) {}
	MI(const MI &rhs) :D1(rhs), D2(rhs) {}
};
class Final : public MI, public Class {
public:
	Final() :Base(), MI(){} // implicit use Class constructor
	Final(int num) :Base(num), MI(num){}
	Final(const Final &rhs) :Base(rhs), MI(rhs) {}
};
int main() {
	Final f1;
	cout << f1.v << endl;
	Final f2(42);
	cout << f2.v << endl;
	Final f3 = f2;
	cout << f3.v << endl;
	return 0;
}