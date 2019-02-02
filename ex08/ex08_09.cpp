#include <iostream>
#include <sstream>
#include <string>
using std::string;
using std::istream;
using std::istringstream;
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
	string s = "When I do count the clock that tells the time";
	istringstream iss(s);
	read(iss);
	return 0;
}