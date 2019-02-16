#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"
using std::cout;
using std::endl;
int main() {
	Quote basic("001X", 12.5);
	Bulk_quote bulk("002X",12.5,4,0.2);
	Quote &r1 = basic;
	r1.debug();
	cout << endl;
	Quote &r2 = bulk;
	r2.debug();
	return 0;
}