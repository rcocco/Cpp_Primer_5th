#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
	string last,word,maxWord;
	int count = 0,maxCount = 0;
	if (cin >> last) {
		count = 1;
		maxWord = last;
		maxCount = count;
		while (cin >> word) {
			if (word == last) {
				++count;
			}
			else {
				if (count > maxCount) {
					maxWord = last;
					maxCount = count;
				}
				last = word;
				count = 1;
			}
		}
		if (count > maxCount) {
			maxWord = last;
			maxCount = count;
		}
		if (maxCount > 1) {
			cout << maxWord << " occurs: "
				<< maxCount << (maxCount > 1 ? " times" : " time")
				<< endl;
		}
		else {
			cout << "All words occur 1 time." << endl;
		}
	}
	return 0;
}