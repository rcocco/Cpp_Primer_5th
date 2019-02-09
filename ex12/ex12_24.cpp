#include <iostream>
#include <string>
#include <cstddef>
using std::size_t;
using std::string;
using std::cin;
using std::cout;
using std::endl;

char *readString(size_t length) {
	char* s = new char[length+1]();
	cin.get(s, length);
	return s;
}
int main() {
	cout << "Enter the size of string: ";
	int len;
	cin >> len;
	string temp;
	getline(cin, temp); // ignore \n
	auto s = readString(len);
	cout << s << endl;
	delete[] s;
	return 0;
}