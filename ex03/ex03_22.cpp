#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using std::string;
using std::vector;
using std::cout;
using std::endl;
int main() {
	vector<string> text = { "p1 1st sentence.",
		"p1 2nd sentence.","p1 3rd sentence.","",
		"p2 1st sentence.","p2 2nd sentence." };
	for (auto it = text.begin(); 
		it != text.end() && !it->empty(); ++it) {
		for (auto c_it = it->begin(); c_it != it->end(); ++c_it) {
			*c_it = toupper(*c_it);
		}
	}
	for (auto it = text.cbegin(); it != text.cend(); ++it) {
		cout << *it << endl;
	}
	return 0;
}