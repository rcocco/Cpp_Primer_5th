#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main() {
	cout << "Please input two numbers: ";
	int a, b;
	cin >> a >> b;
	while (a <= b) { // 暂时假定第一个数小于等于第二个数
		cout << a << " ";
		++a;
	}
	cout << endl;
	return 0;
}