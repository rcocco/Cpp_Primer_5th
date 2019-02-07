#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <initializer_list>
using std::multimap;
using std::vector;
using std::string;
using std::initializer_list;
using std::cout;
using std::endl;
void addChildren(multimap<string, string> &families, const string &familyName, initializer_list<string> childrenNames = {}) {
	for (const auto &childName : childrenNames) {
		families.insert({ familyName,childName });
	}
}
void print(const multimap<string, string> &families) {
	string lastName;
	for (const auto &lf : families) {
		if (lf.first != lastName) {
			cout << endl;
			cout << lf.first << " : ";
			lastName = lf.first;
		}
		cout << lf.second << " | ";
	}
}
int main() {
	multimap<string, string> families;
	addChildren(families, "George", { "William","Charles","Jean Nicolas" });
	print(families);
	cout << endl;
	addChildren(families, "Phillips", { "John" });
	print(families);
	cout << endl;
	addChildren(families, "Phillips", { "David","Louisa" });
	print(families);
	cout << endl;
	return 0;
}