#include <iostream>
int main() {
	int i = 10, j = 20;
	int *p = &i;
	// 输出指针本身的值，与指针所指对象的值
	std::cout << p << " " << *p << std::endl;
	// 改变指针的值
	p = &j;
	std::cout << p << " " << *p << std::endl;
	// 改变指针所指对象的值
	*p = 50;
	std::cout << p << " " << *p << std::endl;
	return 0;
}