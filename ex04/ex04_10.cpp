#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int v;
	while (cin >> v && v != 42) {
		cout << "Not 42" << endl;
	}
	return 0;
}