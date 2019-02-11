#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <exception>
using std::string;
using std::map;
using std::function;
using std::minus;
using std::exception;
using std::cin;
using std::cout;
using std::endl;

int add(int i, int j) { return i + j; }
auto mod = [](int i, int j) {return i % j; };
struct divide {
	int operator()(int denominator, int divisor) {
		return denominator / divisor;
	}
};
int main(){
	map<string, function<int(int, int)>> binops = {
	{"+",add},
	{"-",minus<int>()},
	{"/",divide()},
	{"*",[](int i,int j) {return i * j; }},
	{"%",mod}};
	string op;
	int a, b;
	while (true) {
		try {
			cout << "Enter expression(a op b): " << endl;
			if (cin >> a >> op >> b) {
				cout << binops[op](a, b) << endl;
			}
			else {
				cout << "Error input.\nTry Again? Enter y or n: ";
				string line;
				cin.clear();
				getline(cin,line);
				string s;
				if (!getline(cin,s) || s == "n") {
					break;
				}
			}
		}
		catch (exception err) {
			cout << "Error input.\nTry Again? Enter y or n: ";
			string line;
			cin.clear();
			getline(cin, line);
			string s;
			if (!getline(cin, s) || s == "n") {
				break;
			}
		}
	}
	return 0;
}