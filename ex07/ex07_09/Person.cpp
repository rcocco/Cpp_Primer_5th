#include "Person.h"
using std::istream;
using std::ostream;
istream &read(istream &is, Person &item) {
	is >> item.name >> item.address;
	return is;
}
ostream &print(ostream &os, Person &item) {
	os << item.getName() << " " << item.getAddress();
	return os;
}