#include <iostream>
using std::cout;
using std::endl;
int main() {
	int i = 10;
	while (i >= 0) {
		cout << i << " ";
		--i;
	}
	cout << endl;
	return 0;
}