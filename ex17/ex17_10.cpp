#include <iostream>
#include <bitset>
#include <vector>
using std::vector;
using std::bitset;
using std::cin;
using std::cout;
using std::endl;
int main() {
	vector<int> seq = { 1,2,3,5,8,13,21 };
	unsigned long long num = 0;
	for (auto v : seq) {
		num |= 1ul << v;
	}
	bitset<22> bs1(num);
	cout << bs1 << endl;

	bitset<22> bs2;
	for (auto v : seq) {
		bs2.set(v);
	}
	cout << bs2 << endl;
	return 0;
}