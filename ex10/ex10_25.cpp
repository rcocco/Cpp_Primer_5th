#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <functional>
using std::string;
using std::vector;
using std::size_t;
using std::bind;
using namespace std::placeholders;
using std::cin;
using std::cout;
using std::endl;
string make_plural(size_t ctr, const string &word, const string &ending) {
	return (ctr > 1) ? word + ending : word;
}
void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}
bool check_size(const string &s, string::size_type sz) {
	return s.size() < sz;
}
void biggies(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	auto wc = partition(words.begin(), words.end(),
		bind(check_size,_1,sz));
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer" << endl;
	for_each(wc, words.end(),
		[](const string &s) {cout << s << " "; });
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