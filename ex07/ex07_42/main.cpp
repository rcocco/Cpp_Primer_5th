#include <iostream>
#include "Book.h"
int main() {
	Book b1("C++ Primer (5th Edition)", "978-0321714114", 59.99,
		"Stanley B. Lippman", "Addison-Wesley Professional");
	print(std::cout, b1) << std::endl;
	Book b2;
	read(std::cin,b2);
	print(std::cout, b2) << std::endl;
	return 0;
}