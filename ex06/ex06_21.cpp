#include <iostream>
using std::cout;
using std::endl;
int compare(int v, const int *p) {
	if (!p || v > *p) {
		return v;
	}
	else {
		return *p;
	}
}
int main() {
	int i = 5;
	cout << compare(1, &i) << endl;
	int *p = nullptr;
	cout << compare(2, p) << endl;
	return 0;
}