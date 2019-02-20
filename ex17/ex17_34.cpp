#include <iostream>
#include <iomanip>
#include <string>
int main() {
	std::cout << true << " " << std::boolalpha
		<< true << std::noboolalpha << std::endl;
	std::cout << std::oct << 2 << " " << std::showbase
		<< 2 << std::dec << std::noshowbase << std::endl;
	std::cout << 2.0 << " " << std::showpoint << 2.0
		<< std::noshowpoint << std::endl;
	std::cout << 2 << " " << std::showpos << 2
		<< std::noshowpos << std::endl;
	std::cout << std::hex << 65530 << " " << std::uppercase
		<< 65530 << std::nouppercase << std::dec << std::endl;
	std::cout << std::setw(12) << -12.5 << std::endl;
	std::cout << std::left << std::setw(12) << -12.5 << std::endl;
	std::cout << std::internal << std::setw(12) << -12.5 << std::endl;
	std::cout << std::right << std::setw(12) << -12.5 << std::endl;
	std::cout << -12.5 << " " << std::fixed << -12.5 << std::endl;
	std::cout << std::scientific << -12.5 << " "
		<< std::hexfloat << -12.5 << std::endl;
	std::cout << std::defaultfloat << -12.5 << std::endl;
	std::cout << std::setprecision(7) << 12.123456789 << " "
		<< 12.123456789 << std::endl;
	std::cout << std::setfill('#') << std::setw(12) << 12.5
		<< std::setfill(' ') << std::endl;
	std::cout << std::setbase(16) << 64123 << std::setbase(10) << std::endl;
	std::cout << std::unitbuf << 1 << 2 << 3 << std::nounitbuf << std::endl;
	std::cout << 2 << std::flush << std::ends;
	std::cout << 2 << std::endl;
	char ch;
	std::cin >> std::noskipws >> ch >> std::skipws;
	std::cout << "[" << ch << "]" << std::endl;
	return 0;
}