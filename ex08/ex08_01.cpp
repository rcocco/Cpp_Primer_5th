#include <iostream>
#include <string>
using std::string;
using std::istream;
using std::cout;
using std::endl;
istream &read(istream &is) {
	string s;
	while (is >> s) {
		cout << s << endl;
	}
	is.clear();
	return is;
}
int main() {
	return 0;
}