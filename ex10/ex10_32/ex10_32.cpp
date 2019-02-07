#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <numeric>
#include "Sales_item.h"
using std::vector;
using std::istream_iterator;
using std::bind;
using namespace std::placeholders;
using std::cin;
using std::cout;
using std::endl;
bool compareIsbnLess(const Sales_item &s1, const Sales_item &s2) {
	return s1.isbn() < s2.isbn();
}
bool compareIsbnNotSame(const Sales_item &s1, const Sales_item &s2) {
	return s1.isbn() != s2.isbn();
}
int main() {
	istream_iterator<Sales_item> in(cin), eof;
	vector<Sales_item> vec(in, eof);
	sort(vec.begin(), vec.end(), compareIsbnLess);
	if (!vec.empty()) {
		auto beg = vec.cbegin();
		while (beg != vec.cend()) {
			auto nextBeg = find_if(beg, vec.cend(), bind(compareIsbnNotSame, _1, *beg));
			auto total = std::accumulate(beg+1, nextBeg, *beg);
			cout << total << endl;
			beg = nextBeg;
		}
	}
	else {
		std::cerr << "No Data?!" << std::endl;
		return -1;
	}
	return 0;
}