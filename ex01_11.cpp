#include <iostream>
int main() {
	std::cout << "Please input two numbers: ";
	int a,b;
	std::cin >> a >> b;
	while (a <= b) { // ��ʱ�ٶ���һ����С�ڵ��ڵڶ�����
		std::cout << a << " ";
		++a;
	}
	std::cout << std::endl;
	return 0;
}