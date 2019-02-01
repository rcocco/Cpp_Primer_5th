#include <iostream>
#include "Chapter6.h"
using std::cin;
using std::cout;
using std::endl;
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