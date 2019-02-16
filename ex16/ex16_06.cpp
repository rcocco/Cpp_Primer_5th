#include <iostream>
using std::cout;
using std::endl;
template <typename T,unsigned N>
T *begin(T (&arr)[N]) {
	return arr;
}
template <typename T,unsigned N>
T *end(T (&arr)[N]) {
	return arr + N;
}
int main() {
	int arr[] = { 1,2,3,4,5 };
	for (auto b = begin(arr); b != end(arr); ++b) {
		cout << *b << endl;
	}
	double arr2[] = { 1.5,2.5,3.5,4.5 };
	for (auto b = begin(arr2); b != end(arr2); ++b) {
		cout << *b << endl;
	}
	return 0;
}