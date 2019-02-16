#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
template<typename T>
int compare(const T &v1, const T &v2) {
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}
int main() {
	cout << compare(3, 1) << endl;
	cout << compare(1.0, 2.0) << endl;
	cout << compare(string("aa"), string("aa"));
	return 0;
}