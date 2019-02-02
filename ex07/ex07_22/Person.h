#ifndef PERSON_H
#define PERSON_h
#include <iostream>
#include <string>
class Person {
	friend std::istream &read(std::istream&, Person&);
	friend std::ostream &print(std::ostream&, Person&);
public:
	Person() = default;
	Person(const std::string &n,const std::string &a):
		name(n),address(a) { }
	Person(std::istream&);
	std::string getName() const { return name; }
	std::string getAddress() const { return address; }
private:
	std::string name;
	std::string address;
};
std::istream &read(std::istream&, Person&);
std::ostream &print(std::ostream&, Person&);
#endif
