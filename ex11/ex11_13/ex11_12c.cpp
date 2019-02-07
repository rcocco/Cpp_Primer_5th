#include <iostream>
#include <string>
#include <vector>
#include <utility>
using std::vector;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::endl;
int main() {
	vector<pair<string, int>> vec;
	string s;
	int i;
	while (cin >> s >> i) {
		vec.push_back(pair<string,int>(s,i));
	}
	for (const auto &si : vec) {
		cout << si.first << " " << si.second << endl;
	}
	return 0;
}