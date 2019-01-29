#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
int main() {
	char s1[] = "test";
	char s2[] = "test";
	int result = strcmp(s1, s2);
	if (result < 0) {
		cout << "s1 < s2";
	}
	else if (result > 0) {
		cout << "s1 > s2";
	}
	else {
		cout << "s1 == s2";
	}
	cout << endl;
	return 0;
}