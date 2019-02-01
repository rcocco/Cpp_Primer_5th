#include <iostream>
using std::cout;
using std::endl;
void swap(int *p, int *q) {
	int temp = *p;
	*p = *q;
	*q = temp;
}
int main() {
	int a = 3, b = 5;
	cout << a << " " << b << endl;
	swap(&a, &b);
	cout << a << " " << b << endl;
	return 0;
}