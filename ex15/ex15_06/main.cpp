#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
using std::cout;
using std::endl;
int main() {
	Quote basic("001X", 12.5);
	Bulk_quote bulk("001X",12.5,4,0.2);
	print_total(cout, basic, 4);
	print_total(cout, bulk, 4);
	return 0;
}