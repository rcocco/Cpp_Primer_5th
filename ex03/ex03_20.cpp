#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main() {
	vector<int> ivec;
	int value;
	while (cin >> value) {
		ivec.push_back(value);
	}
	for (decltype(ivec.size()) index = 1; index < ivec.size(); ++index) {
		cout << ivec[index - 1] + ivec[index] << " ";
	}
	cout << endl;
	
	for (decltype(ivec.size()) index = 0; index < (ivec.size() / 2); ++index) {
		cout << ivec[index] + ivec[ivec.size() - 1 - index] << " ";
	}
	if (ivec.size() % 2 != 0) {
		cout << ivec[ivec.size() / 2];
	}
	cout << endl;
	return 0;
}