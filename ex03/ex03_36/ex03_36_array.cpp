#include <iostream>
#include <iterator>
using std::begin;
using std::end;
using std::cout;
using std::endl;
int main() {
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,3,4,5 };
	auto b1 = begin(arr1), e1 = end(arr1),
		b2 = begin(arr2), e2 = end(arr2);
	while (b1 != e1 && b2 != e2 && *b1 == *b2) {
		++b1;
		++b2;
	}
	if (b1 == e1 && b2 == e2) {
		cout << "EQUAL" << endl;
	}
	cout << endl;
	return 0;
}