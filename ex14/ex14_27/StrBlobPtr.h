#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H
#include <memory>
#include <vector>
#include <cstddef>
#include <string>
class StrBlob;
class StrBlobPtr {
	friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
	friend bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &a, std::size_t sz = 0);
	std::string &operator*() const;
	StrBlobPtr &operator++();
	StrBlobPtr &operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
	std::string &operator[](std::ptrdiff_t) const;
	// StrBlobPtr always return string, not const string
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
#endif