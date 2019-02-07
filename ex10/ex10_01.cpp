#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main() {
	vector<int> ivec;
	int v;
	cout << "Enter numbers: " << endl;
	while (cin >> v) {
		ivec.push_back(v);
	}
	cout << "Count number: " << endl;
	cin.clear();
	cin >> v;
	auto c = std::count(ivec.begin(), ivec.end(), v);
	cout << "Number " << v << " occurs " 
		<< c << (c>1? " times":" time") << endl;
	return 0;
}