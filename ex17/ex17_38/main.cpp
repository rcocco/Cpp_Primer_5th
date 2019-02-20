#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::ostream;
template <unsigned N>
ostream &print(const char(&s)[N], ostream &os = cout) {
	for (unsigned i = 0; i < N && s[i]!='\0'; ++i) {
		os << s[i];
	}
	return os;
}
int main() {
	ifstream ifs("unformatio.txt");
	if (ifs) {
		char s[40];
		while (ifs) {
			ifs.getline(s, 30);
			print(s);
			// getline(arr,n,delim) will set failbit
			// if read n-1 chars and next char is not delim 
			if (!ifs.bad() && ifs.fail() && ifs.gcount() == 29) {
				ifs.clear();
				continue;
			}
			cout << endl;
		}
	}
	return 0;
}