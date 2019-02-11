#include <iostream>
#include <string>
#include "Sales_data.h"
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){
	Sales_data sd("001X", 2, 25.0);
	string isbn = static_cast<string>(sd);
	cout << isbn << endl;
	double revenue = static_cast<double>(sd);
	cout << revenue << endl;
	return 0;
}