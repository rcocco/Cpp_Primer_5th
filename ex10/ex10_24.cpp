#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using std::string;
using std::vector;
using std::bind;
using namespace std::placeholders;
using std::cout;
using std::endl;
bool check_size(const string &s, string::size_type sz) {
	return sz > s.size();
}
int main() {
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	string s = "foxes";
	auto it = find_if(vec.begin(), vec.end(),
		bind(check_size,s,_1));
	cout << "vec[" << (it-vec.begin()) << "]="
		<< *it << endl;
	return 0;
}