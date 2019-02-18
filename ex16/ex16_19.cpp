#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::ostream;
using std::cout;
using std::endl;
template <typename C>
ostream &print(ostream &os,const C &c) {
	// not work for some containers like list
	// because they have no subscript operator
	for (typename C::size_type i = 0; i < c.size(); ++i) {
		os << c[i] << " ";
	}
	return os;
}
int main() {
	vector<int> ivec{ 1,2,3,4,5 };
	print(cout, ivec) << endl;
	string s = "abcdef";
	print(cout, s) << endl;
	return 0;
}