#include <iostream>
#include <list>
#include "Blob.h"
using std::list;
using std::cout;
using std::endl;
int main() {
	list<int> ilist{ 1,2,3,4,5 };
	Blob<int> iblob(ilist.begin(), ilist.end());
	for (auto b = iblob.begin(); b != iblob.end(); ++b) {
		cout << *b << " ";
	}
	cout << endl;
	double arr[3] = { 1.5,2.5,3.5 };
	Blob<double> dblob(arr, arr + 3);
	for (auto b = dblob.begin(); b != dblob.end(); ++b) {
		cout << *b << " ";
	}
	cout << endl;
	return 0;
}