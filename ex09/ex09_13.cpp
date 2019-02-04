#include <iostream>
#include <vector>
#include <list>
using std::vector;
using std::list;
using std::cout;
using std::endl;
int main() {
	list<int> ilist{ 1,2,3,4 };
	vector<double> dvec1(ilist.begin(), ilist.end());
	for (auto v : dvec1) {
		cout << v << " ";
	}
	cout << endl;
	vector<int> ivec{ 5,6,7,8 };
	vector<double> dvec2(ivec.begin(),ivec.end());
	for (auto v : dvec2) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}