#include <iostream>
#include "Quote.h"
#include "Limited_quote.h"
using std::cout;
using std::endl;
int main() {
	Quote basic("001X", 12.5);
	Limited_quote limited("001X",12.5,4,0.2);
	print_total(cout, basic, 4);
	print_total(cout, limited, 8);
	return 0;
}