#include <iostream>
#include <list>
#include <deque>
using std::list;
using std::deque;
using std::cout;
using std::endl;
int main() {
	list<int> ilist{ 0,1,2,3,4,5,6,7,8,9 };
	deque<int> odd;
	deque<int> even;
	for (auto v : ilist) {
		if (v % 2) {
			odd.push_back(v);
		}
		else {
			even.push_back(v);
		}
	}
	cout << "odd: ";
	for (auto v : odd) {
		cout << v << " ";
	}
	cout << endl;
	cout << "even: ";
	for (auto v : even) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}