#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);
			//++iter;
		}
		++iter;
		cout << (iter-vi.begin()) << " "<< (vi.end() - iter) << endl;
	}
	for (auto v : vi) {
		cout << v << " ";
	}
	return 0;
}