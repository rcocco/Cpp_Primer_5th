#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::istringstream;
using std::ifstream;
using std::string;
using std::cout;
using std::endl;
int main() {
	ifstream input("poetry.txt");
	if (input) {
		string line;
		string longestWord;
		while (getline(input, line)) {
			istringstream words(line);
			string word;
			while (words >> word) {
				if (word.find_first_of("bdfghjklpqty") == string::npos && word.size() > longestWord.size()) {
					longestWord = word;
				}
			}
		}
		cout << longestWord << endl;
	}
	return 0;
}