#include <iostream>
int main() {
	std::cout << "Please input two numbers: ";
	int a, b;
	std::cin >> a >> b;
	for (; a <= b; ++a) { // ��ʱ�ٶ���һ����С�ڵ��ڵڶ�����
		std::cout << a << " ";
	}
	std::cout << std::endl;
	return 0;
}