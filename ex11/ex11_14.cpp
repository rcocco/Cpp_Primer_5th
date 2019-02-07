#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <initializer_list>
using std::map;
using std::vector;
using std::string;
using std::initializer_list;
using std::pair;
using std::cout;
using std::endl;
void addChildren(map<string, vector<pair<string,string>>> &families, const string &familyName, initializer_list<pair<string,string>> childrenNames = {}) {
	vector<pair<string, string>> &names = families[familyName];
	names.insert(names.end(), childrenNames);
}
void print(const map<string, vector<pair<string, string>>> &families) {
	for (const auto &f : families) {
		cout << f.first << " : ";
		for (const auto &nb : f.second) {
			cout << nb.first << "(" << nb.second << ")"
				<< " | ";
		}
		cout << endl;
	}
}
int main() {
	map<string, vector<pair<string,string>>> families;
	addChildren(families, "George", { {"William","1980-01-01"},{"Charles","1980-02-01"},{"Jean Nicolas","1980-03-01"} });
	print(families);
	cout << endl;
	addChildren(families, "Phillips", { {"John","1982-03-04"} });
	print(families);
	cout << endl;
	addChildren(families, "Phillips", { {"David","1984-04-05"},{"Louisa","1985-07-01"} });
	print(families);
	return 0;
}