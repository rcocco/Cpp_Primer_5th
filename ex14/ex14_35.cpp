#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;
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
	string s = inputer();
	cout << s << endl;
	return 0;
}