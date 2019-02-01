#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int func(int, int);
int sum(int a, int b) {
	return a + b;
}
int subtract(int a, int b) {
	return a - b;
}
int multiply(int a, int b) {
	return a * b;
}
int divide(int a, int b) {
	if (b == 0) return 0;
	return a / b;
}
int main() {
	vector<int (*)(int,int)> fvec;
	fvec.push_back(sum);
	fvec.push_back(subtract);
	fvec.push_back(multiply);
	fvec.push_back(divide);
	cout << fvec[0](8, 2) << endl;
	cout << fvec[1](8, 2) << endl;
	cout << fvec[2](8, 2) << endl;
	cout << fvec[3](8, 2) << endl;
	return 0;
}