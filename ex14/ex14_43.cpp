#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std::placeholders;
using std::vector;
using std::modulus;
using std::bind;
using std::none_of;
using std::cin;
using std::cout;
using std::endl;
int main() {
	vector<int> ivec{ 2,3,4,5 };
	int num;
	cin >> num;
	auto ret = none_of(ivec.begin(), ivec.end(), 
		bind(modulus<int>(), num, _1));
	// if num is divisible by element
	// modulus<int> return zero     ==> false
	// else
	// modulus<int> return non zero ==> true
	// so "num is divisible by any element in vector"
	// means "none of element return true"
	cout << (ret?"true":"false") << endl;
	return 0;
}