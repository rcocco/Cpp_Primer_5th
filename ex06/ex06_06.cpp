#include <iostream>
using std::cin;
using std::cout;
using std::endl;
double add(double a, double b) { // 形参
	double result = a + b; // 普通局部变量
	static unsigned count = 0; // 静态局部变量
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