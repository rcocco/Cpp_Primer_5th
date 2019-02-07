#include <iostream>
#include <vector>
#include <numeric>
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<int> ivec = { 1,2,3,4,5 };
	auto sum = std::accumulate(ivec.cbegin(), ivec.cend(), 0);
	cout << sum << endl;
	return 0;
}