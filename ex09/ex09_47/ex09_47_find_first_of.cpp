#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
int main() {
	string numbers = "0123456789";
	string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string s = "ab2c3d7R4E6";
	cout << s << endl;
	cout << "numbers: " << endl;
	for (string::size_type pos = 0;
		(pos = s.find_first_of(numbers,pos))!=string::npos;
		++pos) {
		cout << "s[" << pos << "] = " << s[pos] << endl;
	}
	cout << "letters: " << endl;
	for (string::size_type pos = 0;
		(pos = s.find_first_of(letters, pos)) != string::npos;
		++pos) {
		cout << "s[" << pos << "] = " << s[pos] << endl;
	}
	return 0;
}