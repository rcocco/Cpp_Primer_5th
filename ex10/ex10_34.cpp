#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<int> vec = { 1,2,3,4,5,6,7 };
	for (auto beg = vec.crbegin();beg!=vec.crend();++beg) {
		cout << *beg << endl;
	}
	return 0;
}