#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::replace_if;
class Equal {
public:
	Equal(int v) :val(v) {}
	bool operator()(int a) {
		return val == a;
	}
private:
	int val;
};
int main() {
	vector<int> vec{ 1,2,3,4,3,5,3,6,3 };
	int oldVal = 3;
	int newVal = 10;
	replace_if(vec.begin(), vec.end(), Equal(oldVal), newVal);
	for (auto v : vec) {
		cout << v << endl;
	}
	return 0;
}