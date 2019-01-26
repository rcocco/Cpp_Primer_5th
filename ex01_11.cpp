#include <iostream>
int main() {
	std::cout << "Please input two numbers: ";
	int a,b;
	std::cin >> a >> b;
	while (a <= b) { // 暂时假定第一个数小于等于第二个数
		std::cout << a << " ";
		++a;
	}
	std::cout << std::endl;
	return 0;
}