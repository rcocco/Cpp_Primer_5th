#include <iostream>
int main() {
	int i = 10, j = 20;
	int *p = &i;
	// ���ָ�뱾���ֵ����ָ����ָ�����ֵ
	std::cout << p << " " << *p << std::endl;
	// �ı�ָ���ֵ
	p = &j;
	std::cout << p << " " << *p << std::endl;
	// �ı�ָ����ָ�����ֵ
	*p = 50;
	std::cout << p << " " << *p << std::endl;
	return 0;
}