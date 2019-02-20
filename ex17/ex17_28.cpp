#include <iostream>
#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;
using std::cout;
using std::endl;
unsigned rand_unsigned() {
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u;
	return u(e);
}
int main() {
	for (int i = 0; i < 30; ++i) {
		cout << rand_unsigned() << endl;
	}
	return 0;
}