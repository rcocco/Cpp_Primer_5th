#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;
vector<string> readFile(const string &fileName) {
	vector<string> svec;
	ifstream input(fileName);
	if (input) {
		string s;
		while (getline(input, s)) {
			svec.push_back(s);
		}
	}
	return svec;
}
int main() {
	auto svec = readFile("poetry.txt");
	for (const auto &line : svec) {
		istringstream iss(line);
		string word;
		while (iss >> word) {
			cout << word << endl;
		}
	}
	return 0;
}