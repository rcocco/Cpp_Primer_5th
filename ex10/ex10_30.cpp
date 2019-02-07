#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
using std::cin;
using std::cout;
int main() {
	istream_iterator<int> in_iter(cin), eof;
	vector<int> vec(in_iter, eof);
	sort(vec.begin(), vec.end());
	ostream_iterator<int> out_iter(cout, " ");
	copy(vec.begin(), vec.end(), out_iter);
	return 0;
}