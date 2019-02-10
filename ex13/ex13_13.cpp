#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
struct X {
	X() { std::cout << "X()" << std::endl; }
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	X &operator=(const X&) {
		std::cout << "X &operator=(const X&)" << std::endl; 
		return *this;
	}
	~X() { std::cout << "~X()" << std::endl; }
};
void f1(X) {}
void f2(X&) {}
int main() {
	X x;
	cout << "---------" << endl;
	f1(x);
	cout << "---------" << endl;
	f2(x);
	cout << "---------" << endl;
	X *p = new X;
	cout << "---------" << endl;
	vector<X> vec;
	vec.push_back(x);
	cout << "---------" << endl;
	delete p;
	cout << "---------" << endl;
	X x2 = x;
	cout << "---------" << endl;
	x2 = x;
	cout << "---------" << endl;
	return 0;
}