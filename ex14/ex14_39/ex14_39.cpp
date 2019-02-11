#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cstddef>
using std::string;
using std::size_t;
using std::vector;
using std::ifstream;
using std::istream_iterator;
using std::count_if;
using std::cin;
using std::cout;
using std::endl;
class StrLenBetween {
public:
	StrLenBetween(size_t mi,size_t ma):min(mi),max(ma){}
	bool operator()(const string &s) const {
		return s.size() >= min && s.size() <= max;
	}
private:
	size_t min;
	size_t max;
};
class StrLenGreaterEqual {
public:
	StrLenGreaterEqual(size_t n) :sz(n){}
	bool operator()(const string &s) const {
		return s.size() >= sz;
	}
private:
	size_t sz;
};
int main() {
	ifstream ifs("poetry.txt");
	istream_iterator<string> in(ifs), eof;
	vector<string> vec(in, eof);
	cout << "len : 1 - 9 count: " << count_if(vec.begin(), vec.end(), StrLenBetween(1, 9)) << endl;
	cout << "len : >= 10 count: " << count_if(vec.begin(), vec.end(), StrLenGreaterEqual(10)) << endl;
	return 0;
}