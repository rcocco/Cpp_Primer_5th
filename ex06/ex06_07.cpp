#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int count() {
	static int value = 0;
	return value++;
}
int main() {
	cout << "Enter a number: ";
	int v1;
	while (cin >> v1) {
		cout << "count() return "
			<< count() << endl;
		cout << "Enter a number: ";
	}
	return 0;
}