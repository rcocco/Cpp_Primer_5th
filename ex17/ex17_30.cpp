#include <iostream>
#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;
using std::cout;
using std::endl;
default_random_engine e;
uniform_int_distribution<unsigned> *u = new uniform_int_distribution<unsigned>();
unsigned rand_unsigned() {
	return u->operator()(e);
}
unsigned rand_unsigned(unsigned seed) {
	e.seed(seed);
	return rand_unsigned();
}
unsigned rand_unsigned(unsigned seed, unsigned min, unsigned max) {
	delete u;
	if (min > max) {
		unsigned temp = min;
		min = max;
		max = min;
	}
	u = new uniform_int_distribution<unsigned>(min, max);
	return rand_unsigned(seed);
}
int main() {
	rand_unsigned(15,0,200);
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
	rand_unsigned(25,0,400);
	for (int i = 0; i < 5; ++i) {
		cout << rand_unsigned() << endl;
	}
	cout << endl;
	delete u;
	return 0;
}