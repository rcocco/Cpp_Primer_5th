#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	for (int value; cin >> value;) {
		cout << value << endl;
	}

	constexpr unsigned size = 5;
	int arr[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = i;
	}
	for (auto v : arr) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}