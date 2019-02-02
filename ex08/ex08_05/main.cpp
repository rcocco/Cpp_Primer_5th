#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;
vector<string> readFile(const string &fileName) {
	vector<string> svec;
	ifstream input(fileName);
	if (input) {
		string s;
		while (input >> s) {
			svec.push_back(s);
		}
	}
	return svec;
}
int main() {
	auto svec = readFile("poetry.txt");
	for (const auto &s : svec) {
		cout << s << endl;
	}
	return 0;
}