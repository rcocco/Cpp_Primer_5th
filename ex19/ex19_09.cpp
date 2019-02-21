#include <iostream>
#include <string>
#include <typeinfo>
using std::cout;
using std::endl;
using std::string;
class Base {};
class Derived:public Base{};
int main() {
	int arr[10];
	Derived d;
	Base *p = &d;
	cout << typeid(char).name() << endl
		<< typeid(short).name() << endl
		<< typeid(int).name() << endl
		<< typeid(long).name() << endl
		<< typeid(long long).name() << endl
		<< typeid(unsigned int).name() << endl
		<< typeid(unsigned long).name() << endl
		<< typeid(unsigned long long).name() << endl
		<< typeid(float).name() << endl
		<< typeid(double).name() << endl
		<< typeid(string).name() << endl
		<< typeid(Base).name() << endl
		<< typeid(Derived).name() << endl
		<< typeid(p).name() << endl
		<< typeid(*p).name() << endl
		<< typeid(arr).name() << endl;
	return 0;
}
