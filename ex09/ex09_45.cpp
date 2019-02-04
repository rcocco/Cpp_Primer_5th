#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
string addPreSuffix(string name, const string &pre, const string &suf) {
	name.insert(name.begin(), 1, ' ');
	name.insert(name.begin(), pre.begin(), pre.end());
	name.append(" ");
	name.append(suf);
	return name;
}
int main() {
	string name = "Smith";
	cout << addPreSuffix(name, "Mr", "III") << endl;
	return 0;
}