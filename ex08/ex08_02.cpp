#include <iostream>
#include <string>
using std::string;
using std::istream;
using std::cin;
using std::cout;
using std::endl;
istream &read(istream &is) {
	string s;
	while (is >> s) {
		cout << s << endl;
	}
	is.clear();
	return is;
}
int main() {
	read(cin);
	cout << "Please enter a number: " << endl;
	int v;
	cin >> v;
	cout << v << endl;
	return 0;
}