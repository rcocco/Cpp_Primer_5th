#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <memory>
using std::ifstream;
using std::unique_ptr;
using std::vector;
using std::exception;
void exercise1(int *b, int *e) {
	vector<int> v(b, e);
	int *p = new int[v.size()];
	try {
		ifstream in("ints");
		throw exception();
	}
	catch(exception e){
		delete[]p;
	}
}
void exercise2(int *b, int *e) {
	vector<int> v(b, e);
	unique_ptr<int[]> p(new int[v.size()]);
	ifstream in("ints");
	throw exception();
}
int main() {
	exercise1(nullptr, nullptr);
	exercise2(nullptr, nullptr);
	return 0;
}