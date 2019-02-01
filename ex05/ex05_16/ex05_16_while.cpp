#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int value;
	while (cin >> value) {
		cout << value << endl;
	}

	constexpr unsigned size = 5;
	int arr[size];
	int i = 0;
	while (i < size) {
		arr[i] = i;
		++i;
	}
	for (auto v : arr) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}