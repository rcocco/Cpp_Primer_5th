#include <iostream>
#include <stdexcept>
using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;
int main() {
	int a, b;
	while (true) {
		try {
			cout << "Enter two numbers: ";
			if (cin >> a >> b) {
				if (b == 0) throw std::runtime_error("Division by zero.");
				cout << a / b << endl;
			}
			break;
		}
		catch (runtime_error err) {
			cout << err.what()
				<< "\nTry Again? Enter y or n" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;
		}
	}
	return 0;
}