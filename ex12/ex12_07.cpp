#include <iostream>
#include <vector>
#include <memory>
using std::shared_ptr;
using std::vector;
using std::make_shared;
using std::cin;
using std::cout;
using std::endl;
shared_ptr<vector<int>> new_vector() {
	return make_shared<vector<int>>();
}
void read_ivec(shared_ptr<vector<int>> p) {
	int v;
	while (cin >> v) {
		p->push_back(v);
	}
}
void print_ivec(shared_ptr<vector<int>> p) {
	for (auto v : *p) {
		cout << v << " ";
	}
	cout << endl;
}
int main() {
	shared_ptr<vector<int>> p = new_vector();
	read_ivec(p);
	print_ivec(p);
	return 0;
}