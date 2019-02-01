#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
int main(int argc, char *argv[]) {
	string s;
	for (int i = 0; i < argc; ++i) {
		s += argv[i];
	}
	cout << s << endl;
	return 0;
}