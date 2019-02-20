#include <iostream>
#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;
using std::cout;
using std::endl;
default_random_engine e;
uniform_int_distribution<unsigned> u;
unsigned rand_unsigned() {
	return u(e);
}
unsigned rand_unsigned(unsigned seed) {
	e.seed(seed);
	return rand_unsigned();
}
int main() {
	rand_unsigned(15);
	for (int i = 0; i < 5; ++i) {
		cout << rand_unsigned() << endl;
	}
	cout << endl;
	rand_unsigned(25);
	for (int i = 0; i < 5; ++i) {
		cout << rand_unsigned() << endl;
	}
	cout << endl;
	rand_unsigned(15);
	for (int i = 0; i < 5; ++i) {
		cout << rand_unsigned() << endl;
	}
	cout << endl;
	return 0;
}