#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std::placeholders;
using std::vector;
using std::greater;
using std::not_equal_to;
using std::multiplies;
using std::string;
using std::bind;
using std::transform;
using std::count_if;
using std::find_if;
using std::cin;
using std::cout;
using std::endl;
int main() {
	// (a)
	vector<int> ivec{ 1,2,1025,1026,1027,4,5,1023 };
	auto count = count_if(ivec.begin(), ivec.end(),
		bind(greater<int>(), _1, 1024));
	cout << count << endl;
	// (b)
	vector<string> svec{ "pooh","pooh","not","pooh" };
	auto first_not = find_if(svec.begin(), svec.end(),
		bind(not_equal_to<string>(),_1,"pooh"));
	if (first_not != svec.end()) cout << *first_not << endl;
	// (c)
	transform(ivec.begin(), ivec.end(), ivec.begin(),
		bind(multiplies<int>(),_1,2));
	for (auto i : ivec) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}