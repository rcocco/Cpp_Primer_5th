#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using std::cout;
using std::endl;
using std::count_if;
using std::mem_fn;
using std::string;
using std::vector;
unsigned countEmpty(const vector<string> &vec) {
	return count_if(vec.begin(), vec.end(),
		mem_fn(&string::empty));
}
int main() {
	vector<string> vec{ "aa", "bb", "", "", "cc", "", "dd" };
	cout << "Empty string: " << countEmpty(vec) << endl;
	return 0;
}
