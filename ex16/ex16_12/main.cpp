#include <iostream>
#include "Blob.h"
using std::cout;
using std::endl;
int main() {
	Blob<int> a{ 1,2,3,4 }, b{ 1,2,3,4 };
	for (auto b = a.begin(); b != a.end(); ++b) {
		cout << *b << endl;
	}
	auto q = a.begin() + 2;
	cout << *q << endl;
	cout << *(q - 1) << endl;
	cout << (a == b) << endl;
	return 0;
}