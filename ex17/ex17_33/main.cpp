#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include <vector>
#include <random>
#include <string>
#include <ctime>
using std::ifstream;
using std::istringstream;
using std::runtime_error;
using std::vector;
using std::map;
using std::string;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::time;
using std::cout;
using std::endl;
map<string, vector<string>> buildMap(ifstream &map_file) {
	map<string, vector<string>> trans_map;
	string key;
	string value;
	while (map_file >> key && getline(map_file, value)) {
		if (value.size() > 1)
			trans_map[key].push_back(value.substr(1)); //最后一次为准
		else
			throw runtime_error("no rule for" + key);
	}
	return trans_map;
}
const string &transform(const string &s, const map<string, vector<string>> &m) {
	static default_random_engine e(time(nullptr));
	auto map_it = m.find(s);
	if (map_it != m.cend()) {
		uniform_int_distribution<unsigned> u(0, map_it->second.size() - 1);
		return map_it->second[u(e)];
	}
	else {
		return s;
	}
}
void word_transform(ifstream &map_file, ifstream &input) {
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text)) {
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}
int main() {
	ifstream map_file("map_file.txt");
	ifstream input("data_tobeconvert.txt");
	if (map_file && input) {
		word_transform(map_file, input);
	}
	else {
		return -1;
	}
	return 0;
}