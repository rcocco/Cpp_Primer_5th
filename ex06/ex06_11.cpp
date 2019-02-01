#include <iostream>
using std::cout;
using std::endl;
void reset(int &i) {
	i = 0;
}
int main() {
	int a = 5;
	cout << a << endl;
	reset(a);
	cout << a << endl;
	return 0;
}