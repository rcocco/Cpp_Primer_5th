#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main() {
	cout << "Please input two numbers: ";
	int a, b;
	cin >> a >> b;
	while (a <= b) { // ��ʱ�ٶ���һ����С�ڵ��ڵڶ�����
		cout << a << " ";
		++a;
	}
	cout << endl;
	return 0;
}