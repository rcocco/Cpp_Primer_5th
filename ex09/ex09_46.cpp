#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
string addPreSuffix(string name, const string &pre, const string &suf) {
	name.insert(0, " ");
	name.insert(0, pre);
	name.insert(name.size(), " ");
	name.insert(name.size(), suf);
	return name;
}
int main() {
	string name = "Smith";
	cout << addPreSuffix(name, "Mr", "III") << endl;
	return 0;
}