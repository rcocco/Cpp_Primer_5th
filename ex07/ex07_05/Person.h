#ifndef PERSON_H
#define PERSON_h
#include <string>
struct Person {
	std::string getName() const { return name; }
	std::string getAddress() const { return address; }
	std::string name;
	std::string address;
};
#endif
