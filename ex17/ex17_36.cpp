#include <iostream>
#include <cmath>
#include <iomanip>
using std::cout;
using std::sqrt;
using std::scientific;
using std::fixed;
using std::hexfloat;
using std::defaultfloat;
using std::uppercase;
using std::left;
using std::setw;
int main() {
	cout << left << setw(20) << "default format: " << sqrt(2.0) << '\n'
		<< setw(20) << "scientific: " << scientific << sqrt(2.0) << '\n'
		<< setw(20) << "fixed decimal: " << fixed << sqrt(2.0) << '\n'
		<< setw(20) << "hexadecimal: " << hexfloat << uppercase << sqrt(2.0) << '\n'
		<< setw(20) << "use defaults: " << defaultfloat << sqrt(2.0) << "\n\n";
	return 0;
}