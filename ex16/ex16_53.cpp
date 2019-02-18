#include <iostream>
#include <string>
using std::ostream;
using std::string;
using std::cout;
using std::endl;
template <typename T>
ostream &print(ostream &os, const T &t) {
	return os << t;
}
template <typename T, typename...Args>
ostream &print(ostream &os, const T &t, const Args&...rest) {
	os << t << ", ";
	return print(os, rest...);
}
int main() {
	print(cout, 1) << endl;
	print(cout, 1, 2.5) << endl;
	print(cout, 1, 2.5, "aa", string("bb"), 't') << endl;
	return 0;
}