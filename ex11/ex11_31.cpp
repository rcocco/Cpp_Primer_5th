#include <iostream>
#include <map>
#include <string>
using std::multimap;
using std::string;
using std::cout;
using std::endl;

void remove_author(multimap<string, string> &authors,const string &author) {
	auto entries = authors.count(author);
	auto iter = authors.find(author);
	while (entries) {
		iter = authors.erase(iter);
		--entries;
	}
}
int main() {
	return 0;
}