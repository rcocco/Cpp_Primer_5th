#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
class Employee {
public:
	Employee(const std::string &n = std::string()) :
		name(n), uuid(id++) {}
private:
	std::string name;
	int uuid;
	static int id;
};
#endif