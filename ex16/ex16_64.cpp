#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using std::vector;
using std::string;
using std::cout;
using std::endl;
template <typename T>
unsigned int count_vector(const vector<T> &vec, const T &val) {
	unsigned int count = 0;
	for (auto beg = vec.begin(); beg != vec.end(); ++beg) {
		if (*beg == val) {
			++count;
		}
	}
	return count;
}
template <>
unsigned int count_vector(const vector<const char*> &vec, const char* const &val) {
	unsigned int count = 0;
	for (auto beg = vec.begin(); beg != vec.end(); ++beg) {
		if (std::strcmp(*beg,val) == 0) {
			++count;
		}
	}
	return count;
}
int main() {
	vector<double> dvec{ 1.5,2.5,3.5,2.5,2.5,4,5 };
	cout << count_vector(dvec, 2.5) << endl;
	vector<int> ivec{ 1,2,3,4,3,3,4,5,3 };
	cout << count_vector(ivec, 3) << endl;
	vector<string> svec{ "aa","bb","aa","cc","aa" };
	cout << count_vector(svec, string("aa")) << endl;
	vector<const char*> cvec{ new char[3] {'a','a','\0'},
		new char[3] {'b','b','\0'},
		new char[3] {'a','a','\0'},
		new char[3] {'c','c','\0'},
		new char[3] {'a','a','\0'} };
	const char *cc = "aa";
	cout << count_vector(cvec, cc) << endl;
	for (const auto &p : cvec) {
		delete[]p;
	}
	return 0;
}