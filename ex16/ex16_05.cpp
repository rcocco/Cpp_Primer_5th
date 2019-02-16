#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::cout;
using std::endl;
template <typename T,unsigned N>
ostream &print(ostream &os, T (&arr)[N]) {
	for (T v : arr) {
		os << v << " ";
	}
	return os;
}
int main() {
	int arr1[] = { 1,2,3,4,5 };
	print(cout, arr1) << endl;
	double arr2[] = { 1.5,2.5,3.5,4.5 };
	print(cout, arr2) << endl;
	string arr3[] = { "aa","bb","cc","dd" };
	print(cout, arr3) << endl;
	return 0;
}