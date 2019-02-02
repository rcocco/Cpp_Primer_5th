#include "Account.h"
void Account::rate(double newRate) {
	interestRate = newRate;
}
double Account::interestRate = initRate();
double Account::initRate() {
	return 3.0;
}