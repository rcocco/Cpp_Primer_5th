#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
vector<int> *new_vector() {
	return new vector<int>();
}
void read_ivec(vector<int> *p) {
	int v;
	while (cin >> v) {
		p->push_back(v);
	}
}
void print_ivec(vector<int> *p) {
	for (auto v : *p) {
		cout << v << " ";
	}
	cout << endl;
}
int main() {
	vector<int> *p = new_vector();
	read_ivec(p);
	print_ivec(p);
	delete p;
	p = nullptr;
	return 0;
}