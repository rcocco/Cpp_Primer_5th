#include <iostream>
using std::cout;
using std::endl;
template <typename T,unsigned N>
constexpr unsigned size(T (&arr)[N]) {
	return N;
}
int main() {
	int arr[] = { 1,2,3,4,5 };
	cout << size(arr) << endl;
	double arr2[] = { 1.5,2.5,3.5,4.5 };
	cout << size(arr2) << endl;
	return 0;
}