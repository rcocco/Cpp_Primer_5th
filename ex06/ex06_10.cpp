#include <iostream>
using std::cout;
using std::endl;
void swap(int *p, int *q) {
	int temp = *p;
	*p = *q;
	*q = temp;
}
int main() {
	int a = 5, b = 15;
	cout << a << " " << b << endl;
	swap(&a, &b);
	cout << a << " " << b << endl;
	return 0;
}