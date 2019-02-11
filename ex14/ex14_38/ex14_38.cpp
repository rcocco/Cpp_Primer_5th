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
class StrLenEqual {
public:
	StrLenEqual(size_t n):sz(n){}
	bool operator()(const string &s) const {
		return s.size() == sz;
	}
private:
	size_t sz;
};
int main() {
	ifstream ifs("poetry.txt");
	istream_iterator<string> in(ifs), eof;
	vector<string> vec(in, eof);
	for (int i = 1; i <= 10; ++i) {
		StrLenEqual equal(i);
		cout << "len : " << i << " count: "
			<< count_if(vec.begin(), vec.end(), equal)
			<< endl;
	}
	return 0;
}