#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
	int grade;
	cin >> grade;
	string finalgrade = (grade > 90) ? "high pass" :
		(grade > 75) ? "pass" :
		(grade >= 60)? "low pass":"fail";
	cout << finalgrade << endl;

	if (grade > 90) {
		finalgrade = "high pass";
	}
	else if (grade > 75) {
		finalgrade = "pass";
	}
	else if (grade >= 60) {
		finalgrade = "low pass";
	}
	else {
		finalgrade = "pass";
	}
	cout << finalgrade << endl;
	return 0;
}