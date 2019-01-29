#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<int> vec1 = { 1,2,3,4,5 };
	vector<int> vec2 = { 1,2,3,4,5 };
	if (vec1 == vec2) {
		cout << "EQUAL" << endl;
	}
	cout << endl;
	return 0;
}