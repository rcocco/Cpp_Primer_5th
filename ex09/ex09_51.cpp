#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::cout;
using std::endl;
class Date {
	friend ostream &print(ostream &os, const Date &item);
public:
	// "January 1,1900"
	// "12/31/1990"
	// "Jan 1 1900"
	Date(const string &date) {
		string::size_type pos = date.find_first_of("0123456789");
		if (pos) { // January 1,1900 or Jan 1 1900
			convertMonth(date);
		}
		else { // 12 / 31 / 1990
			month = stoi(date, &pos);// pos is now the index of the first non number
			pos = date.find_first_of("0123456789", pos);
		}
		string::size_type offset = 0;
		day = stoi(date.substr(pos), &offset);
		pos = date.find_first_of("0123456789", pos+offset);
		year = stoi(date.substr(pos));
	}
private:
	void convertMonth(const string &m) {
		if (m.find("Jan") == 0u) month = 1;
		else if (m.find("Feb") == 0u) month = 2;
		else if (m.find("Mar") == 0u) month = 3;
		else if (m.find("Apr") == 0u) month = 4;
		else if (m.find("May") == 0u) month = 5;
		else if (m.find("Jun") == 0u) month = 6;
		else if (m.find("Jul") == 0u) month = 7;
		else if (m.find("Aug") == 0u) month = 8;
		else if (m.find("Sep") == 0u) month = 9;
		else if (m.find("Oct") == 0u) month = 10;
		else if (m.find("Nov") == 0u) month = 11;
		else if (m.find("Dec") == 0u) month = 12;
	}
	unsigned year, month, day;
};
ostream &print(ostream &os, const Date &item) {
	os << item.year << "-" << item.month << "-"
		<< item.day;
	return os;
}

int main() {
	Date d1("January 25, 1900");
	print(cout,d1) << endl;
	Date d2("12/21/1990");
	print(cout,d2) << endl;
	Date d3("Oct 15 2020");
	print(cout,d3) << endl;
	return 0;
}