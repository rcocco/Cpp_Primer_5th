#include <iostream>
using std::cout;
using std::endl;
int main() {
	auto add = [](int a, int b) {return a + b; };
	cout << add(2, 5) << endl;
	return 0;
}