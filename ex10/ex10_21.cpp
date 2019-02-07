#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;
int main() {
	int v = 5;
	auto f = [&v]()->bool {
		if (v>0) {
			--v;
			return false;
		}
		else {
			return true;
		}
	};
	for (int i = 0; i < 7; ++i) {
		cout << v << " ";
		cout << (f()?"true":"false") << endl;
	}
	cout << endl;
	return 0;
}