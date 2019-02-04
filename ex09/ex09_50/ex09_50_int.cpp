#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cout;
using std::endl;
int main() {
	vector<string> svec{ "1","2","3","4","5" };
	int sum = 0;
	for (const auto &s : svec) {
		sum += stoi(s);
	}
	cout << sum << endl;
	return 0;
}