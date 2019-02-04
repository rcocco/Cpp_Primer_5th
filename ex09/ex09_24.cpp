#include <vector>
using std::vector;
int main() {
	vector<int> vec;
	auto i1 = vec.at(0);
	auto i2 = vec[0];
	auto i3 = vec.front();
	auto i4 = *vec.begin();
	return 0;
}