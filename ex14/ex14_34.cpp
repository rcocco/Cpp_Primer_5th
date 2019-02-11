#include <iostream>
using std::cin;
using std::cout;
using std::endl;
class ITE {
public:
	int operator()(bool a, int b, int c) {
		return a ? b : c;
	}
};
int main() {
	ITE func;
	cout << func(true, 2, 4) << endl;
	return 0;
}