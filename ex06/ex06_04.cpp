#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int fact(int val) {
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}
int main() {
	int value;
	cout << "Enter a number: ";
	while (cin >> value) {
		cout << "The factorial of " << value
			<< " is " << fact(value) << endl;
		cout << "Enter a number: ";
	}
	return 0;
}