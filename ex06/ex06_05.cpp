#include <iostream>
using std::cin;
using std::cout;
using std::endl;
double absvalue(double num) {
	if (num < 0)
		return -num;
	else
		return num;
}
int main() {
	cout << "Enter a number: ";
	double value;
	while (cin >> value) {
		cout << "The absolute value of " << value
			<< " is " << absvalue(value) << endl;
		cout << "Enter a number: ";
	}
	return 0;
}