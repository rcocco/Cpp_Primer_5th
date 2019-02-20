#include <iostream>
#include <cmath>
using std::cout;
using std::sqrt;
using std::scientific;
using std::fixed;
using std::hexfloat;
using std::defaultfloat;
using std::uppercase;
int main() {
	cout << "default format: " << sqrt(2.0) << '\n'
		<< "scientific: " << scientific << sqrt(2.0) << '\n'
		<< "fixed decimal: " << fixed << sqrt(2.0) << '\n'
		<< "hexadecimal: " << hexfloat << uppercase << sqrt(2.0) << '\n'
		<< "use defaults: " << defaultfloat << sqrt(2.0) << "\n\n";
	return 0;
}