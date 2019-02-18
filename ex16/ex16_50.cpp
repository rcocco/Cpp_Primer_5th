#include <iostream>
#include <typeinfo>
#include <string>
using std::string;
using std::cout;
using std::endl;
template <typename T> struct Type {};
template <typename T> void f(T val) {
	cout << "f(T val)" << endl 
		<< "T = " << typeid(Type<T>).name() << endl
		<< "val = " << typeid(Type<decltype(val)>).name() 
		<< endl;
}
template <typename T> void f(const T *val) {
	cout << "f(const T *val)" << endl
		<< "T = " << typeid(Type<T>).name() << endl
		<< "val = " << typeid(Type<decltype(val)>).name()
		<< endl;
}
template <typename T> void g(T val) {
	cout << "g(T val)" << endl
		<< "T = " << typeid(Type<T>).name() << endl
		<< "val = " << typeid(Type<decltype(val)>).name()
		<< endl;
}
template <typename T> void g(T *val) {
	cout << "g(T *val)" << endl
		<< "T = " << typeid(Type<T>).name() << endl
		<< "val = " << typeid(Type<decltype(val)>).name()
		<< endl;
}
int main() {
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;
	// g(T), T = int, val = int
	g(42);
	// g(T*), T = int, val = int*
	g(p);
	// g(T), T = int, val = int
	g(ci);
	// g(T*), T = const int, val = const int *
	g(p2);
	// f(T), T = int, val = int
	f(42);
	// f(T), T = int*, val = int*
	f(p);
	// f(T), T = int, val = int
	f(ci);
	// f(const T*) T = int, val = const int *
	f(p2);
	return 0;
}