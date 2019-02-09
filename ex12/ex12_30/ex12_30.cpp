#include <iostream>
#include <fstream>
#include <string>
#include "TextQuery.h"
#include "QueryResult.h"
using std::ifstream;
using std::string;
using std::cin;
using std::cout;
using std::endl;
void runQueries(ifstream &infile) {
	TextQuery tq(infile);
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}
int main() {
	ifstream ifs("poetry.txt");
	if (ifs) {
		runQueries(ifs);
	}
	else {
		return -1;
	}
	return 0;
}