#include <iostream>
using std::cout;
using std::endl;
int add10(int v) {
	auto add = [v](int a) {return v + a; };
	return add(10);
}
int main() {
	cout << add10(25) << endl;
	return 0;
}