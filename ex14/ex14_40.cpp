#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstddef>
using std::string;
using std::vector;
using std::size_t;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
class ShorterString {
public:
	bool operator()(const string &s1, const string &s2) const {
		return s1.size() < s2.size();
	}
};
class SizeComp {
public:
	SizeComp(size_t n) :sz(n) {}
	bool operator()(const string &s) const {
		return s.size() >= sz;
	}
private:
	size_t sz;
};
class PrintString {
public:
	PrintString(ostream &o = cout, char c = ' ') :
		os(o), sep(c) {}
	void operator()(const string &s) const {
		os << s << sep;
	}
private:
	ostream &os;
	char sep;
};
string make_plural(size_t ctr, const string &word, const string &ending) {
	return (ctr > 1) ? word + ending : word;
}
void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}
void biggies(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(),ShorterString());
	auto wc = find_if(words.begin(), words.end(),SizeComp(sz));
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer" << endl;
	for_each(wc, words.end(),PrintString());
	cout << endl;
}
int main() {
	// the quick red fox jumps over the slow red turtle
	vector<string> words;
	string s;
	while (cin >> s) {
		words.push_back(s);
	}
	biggies(words, 5);
	return 0;
}