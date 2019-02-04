#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cout;
using std::endl;
int main() {
	vector<string> svec{ "1.1","2.2","3.3","4.4","5.5" };
	double sum = 0;
	for (const auto &s : svec) {
		sum += stod(s);
	}
	cout << sum << endl;
	return 0;
}