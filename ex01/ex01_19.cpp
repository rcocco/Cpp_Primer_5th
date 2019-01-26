#include <iostream>
int main() {
	std::cout << "Please input two numbers: ";
	int a, b;
	std::cin >> a >> b;
	if (a <= b) {
		while (a <= b) {
			std::cout << a << " ";
			++a;
		}
	}
	else {
		while (b <= a) {
			std::cout << b << " ";
			++b;
		}
	}
	std::cout << std::endl;
	return 0;
}