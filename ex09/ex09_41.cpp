#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cout;
using std::endl;
int main() {
	vector<char> cvec{ 'H','e','l','l','o','!' };
	string s(cvec.begin(), cvec.end());
	cout << s << endl;
	return 0;
}