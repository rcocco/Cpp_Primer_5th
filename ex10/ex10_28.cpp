#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
using std::vector;
using std::deque;
using std::back_inserter;
using std::inserter;
using std::front_inserter;
using std::cout;
using std::endl;
int main() {
	vector<int> vec{ 1,2,3,4,5,6,7,8,9 };
	deque<int> deq1, deq2, deq3;
	copy(vec.begin(), vec.end(), inserter(deq1, deq1.begin()));
	for_each(deq1.begin(), deq1.end(), [](int v) {cout << v << " "; });
	cout << endl;
	copy(vec.begin(), vec.end(), back_inserter(deq2));
	for_each(deq2.begin(), deq2.end(), [](int v) {cout << v << " "; });
	cout << endl;
	copy(vec.begin(), vec.end(), front_inserter(deq3));
	for_each(deq3.begin(), deq3.end(), [](int v) {cout << v << " "; });
	cout << endl;
	return 0;
}