#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cin;
using std::cout;
int main() {
	vector<string> ivec;
	string value;
	while (cin >> value) {
		ivec.push_back(value);
	}
	return 0;
}