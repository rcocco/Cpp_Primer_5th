#include <iostream>
using std::cin;
using std::cout;
using std::endl;
double add(double a, double b) { // �β�
	double result = a + b; // ��ͨ�ֲ�����
	static unsigned count = 0; // ��̬�ֲ�����
	++count;
	cout << "Execute " << count
		<< (count > 1 ? " times. " : " time. ");
	return result;
}
int main() {
	cout << "Enter two numbers: ";
	double v1,v2;
	while (cin >> v1 >> v2) {
		cout << "The sum value is "
			<< add(v1,v2) << endl;
		cout << "Enter a number: ";
	}
	return 0;
}