#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <initializer_list>
using std::map;
using std::vector;
using std::string;
using std::initializer_list;
using std::cout;
using std::endl;
void addChildren(map<string, vector<string>> &families,const string &familyName,initializer_list<string> childrenNames = {}) {
	vector<string> &names = families[familyName];
	names.insert(names.end(), childrenNames);
}
void print(const map<string, vector<string>> &families) {
	for (const auto &f : families) {
		cout << f.first << " : ";
		for (const auto &s : f.second) {
			cout << s << " | ";
		}
		cout << endl;
	}
}
int main() {
	map<string, vector<string>> families;
	addChildren(families, "George", { "William","Charles","Jean Nicolas" });
	print(families);
	cout << endl;
	addChildren(families, "Phillips", { "John" });
	print(families);
	cout << endl;
	addChildren(families, "Phillips", { "David","Louisa" });
	print(families);
	return 0;
}