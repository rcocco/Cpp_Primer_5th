#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;
using std::vector;
class InputString {
public:
	InputString(istream &i = cin) :is(i){}
	string operator()() const {
		string line;
		if (!getline(is, line)) {
			line = "";
		}
		return line;
	}
private:
	istream &is;
};
int main() {
	InputString inputer;
	vector<string> vec;
	string line;
	while (!(line = inputer()).empty()) {
		vec.push_back(line);
	}
	for (const auto &s : vec) {
		cout << s << endl;
	}
	return 0;
}