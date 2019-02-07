#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using std::string;
using std::vector;
using std::list;
using std::back_inserter;
using std::cout;
using std::endl;
int main() {
	vector<string> vec{ "And","in","see","the",
	"brave","day","the","sunk","in","hideous","night" };
	sort(vec.begin(), vec.end());
	list<string> dest;
	unique_copy(vec.begin(), vec.end(), back_inserter(dest));
	for (auto &s : dest) {
		cout << s << endl;
	}
	return 0;
}