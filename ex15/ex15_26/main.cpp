#include <iostream>
#include "Bulk_quote.h"
#include "Quote.h"
using std::cout;
using std::endl;
void testBulk() {
	Bulk_quote bq1;
	cout << "************************" << endl;
	Bulk_quote bq2 = bq1;
	cout << "************************" << endl;
	Bulk_quote bq3 = std::move(bq2);
	cout << "************************" << endl;
}
void testQuote() {
	Quote q1;
	cout << "************************" << endl;
	Quote q2 = q1;
	cout << "************************" << endl;
	Quote q3 = std::move(q2);
	cout << "************************" << endl;
}
void testQuotePointer() {
	Quote *p = new Bulk_quote;
	cout << "************************" << endl;
	delete p;
	cout << "************************" << endl;
}
int main() {
	cout << "Test Bulk_quote" << endl;
	cout << "************************" << endl;
	testBulk();
	cout << "************************" << endl;
	cout << "Test Quote" << endl;
	cout << "************************" << endl;
	testQuote();
	cout << "************************" << endl;
	cout << "Test Quote pointer" << endl;
	cout << "************************" << endl;
	testQuotePointer();
	cout << "************************" << endl;
	return 0;
}