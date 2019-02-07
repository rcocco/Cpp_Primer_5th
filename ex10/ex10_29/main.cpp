#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
using std::ifstream;
using std::vector;
using std::string;
using std::istream_iterator;
using std::ostream_iterator;
using std::cout;
using std::endl;
int main() {
	ifstream in("poetry.txt");
	if (in) {
		istream_iterator<string> in_iter(in), eof;
		vector<string> vec(in_iter, eof);
		ostream_iterator<string> out_iter(cout,"\n");
		copy(vec.begin(), vec.end(), out_iter);
	}
	return 0;
}