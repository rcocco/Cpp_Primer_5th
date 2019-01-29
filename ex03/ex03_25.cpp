#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main() {
	vector<unsigned> scores(11, 0);
	unsigned grade;
	// Test data:
	// 42 65 95 100 39 67 95 76 88 76 83 92 76 93
	while (cin >> grade) {
		if (grade <= 100) {
			++*(scores.begin() + grade / 10);
		}
	}
	// Output: 0 0 0 1 1 0 2 3 2 4 1
	for (auto v : scores) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}