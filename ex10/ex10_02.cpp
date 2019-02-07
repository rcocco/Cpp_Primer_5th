#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
	list<string> svec;
	string v;
	cout << "Enter strings: " << endl;
	while (cin >> v) {
		svec.push_back(v);
	}
	cout << "Count string: " << endl;
	cin.clear();
	cin >> v;
	auto c = std::count(svec.begin(), svec.end(), v);
	cout << "String " << v << " occurs " 
		<< c << (c>1? " times":" time") << endl;
	return 0;
}