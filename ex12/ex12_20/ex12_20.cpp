#include <iostream>
#include <fstream>
#include <string>
#include "StrBlob.h"
#include "StrBlobPtr.h"
using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::cerr;
int main() {
	ifstream ifs("poetry.txt");
	if (!ifs) {
		return -1;
	}
	StrBlob strblob;
	string line;
	while (getline(ifs, line)) {
		strblob.push_back(line);
	}
	for (auto beg = strblob.begin(); beg.notEqual(strblob.end()); beg.incr()) {
		cout << beg.deref() << endl;
	}
	return 0;
}