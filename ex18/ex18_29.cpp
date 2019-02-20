#include <iostream>
using std::cout;
using std::endl;
class Class { public:int i = 5; };
class Base : public Class { public:void add() { i=10; } };
class D1 : virtual public Base {  };
class D2 : virtual public Base {  };
class MI : public D1, public D2 {  };
class Final : public MI, public Class { };
int main() {
	Base *pb; Class *pc; MI *pmi; D2 *pd2;
	Final f;
	f.add();
	//cout << f.i << endl;
	pc = &f;
	cout << pc->i << endl;
	return 0;
}