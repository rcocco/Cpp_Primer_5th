#include <iostream>
#include <sstream>
#include <string>
using std::string;
using std::ostringstream;
using std::cout;
using std::endl;
template <typename T> string debug_rep(const T &t) {
	ostringstream ret;
	ret << t;
	return ret.str();
}
template <typename T> string debug_rep(T *p) {
	ostringstream ret;
	ret << "pointer: " << p;
	if (p) {
		ret << " " << debug_rep(*p);
	}
	else {
		ret << " null pointer";
	}
	return ret.str();
}
string debug_rep(const string &s) {
	return '"' + s + '"';
}
string debug_rep(char *p) {
	return debug_rep(string(p));
}
string debug_rep(const char *p) {
	return debug_rep(string(p));
}
int main() {
	cout << debug_rep("hello") << endl;
	return 0;
}