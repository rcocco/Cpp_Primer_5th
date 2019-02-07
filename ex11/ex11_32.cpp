#include <iostream>
#include <map>
#include <string>
using std::multimap;
using std::string;
using std::cout;
using std::endl;

void addBooks(multimap<string, string> &authors) {
	authors.insert({ "Victor Rousseau", "The Beetle Horde" });
	authors.insert({ "Captain S. P. Meek", "The Cave Of Horror" });
	authors.insert({ "Ray Cummings", "Phantoms Of Reality" });
	authors.insert({ "M. L. Staley", "The Stolen Mind" });
	authors.insert({ "C. V. Tench", "Compensation" });
	authors.insert({ "Murray Leinster", "Tanks" });
	authors.insert({ "Anthony Pelcher", "Invisible Death" });
	authors.insert({ "Harl Vincent", "Old Crompton's Secret" });
	authors.insert({ "Charles Willard Diffin", "Spawn of the Stars" });
	authors.insert({ "Hugh B. Cave", "The Corpse on the Grating" });
	authors.insert({ "Sophie Wenzel Ellis", "Creatures of the Light" });
	authors.insert({ "S. P. Meek", "Into Space" });
	authors.insert({ "Victor Rousseau", "The Beetle Horde (Part 2 of 2)" });
	authors.insert({ "Anthony Pelcher", "Mad Music" });
	authors.insert({ "S. P. Meek", "The Thief of Time" });
}
void print(const multimap<string, string> &authors) {
	for (const auto &ab : authors) {
		cout << ab.first << " - ";
		cout << ab.second << endl;
	}
}
void remove_author(multimap<string, string> &authors,const string &author) {
	auto entries = authors.count(author);
	auto iter = authors.find(author);
	while (entries) {
		iter = authors.erase(iter);
		--entries;
	}
}
int main() {
	multimap<string, string> authors;
	addBooks(authors);
	print(authors);
	cout << endl;
	string search_item("Victor Rousseau");
	remove_author(authors,search_item);
	print(authors);
	return 0;
}