#include <iostream>
#include <forward_list>
#include <string>
using std::forward_list;
using std::string;
using std::cout;
using std::endl;
void search_insert(forward_list<string> &flist, const string &s1, const string &s2) {
	auto curr = flist.begin(), prev = flist.before_begin();
	bool inserted = false;
	while (curr != flist.end()) {
		if (*curr == s1) {
			curr = flist.insert_after(curr, s2);
			inserted = true;
		}
		prev = curr;
		++curr;
	}
	if (!inserted) {
		flist.insert_after(prev, s2);
	}
}
int main() {
	forward_list<string> flist{"aa","bb","aa","dd","ee"};
	search_insert(flist, "aa", "q");
	for (auto v : flist) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}