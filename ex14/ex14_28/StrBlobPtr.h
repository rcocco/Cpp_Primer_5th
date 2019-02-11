#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H
#include <memory>
#include <vector>
#include <cstddef>
#include <string>
class StrBlob;
class StrBlobPtr {
	friend StrBlobPtr operator+(const StrBlobPtr &, std::ptrdiff_t);
	friend StrBlobPtr operator+(std::ptrdiff_t, const StrBlobPtr &);
	friend StrBlobPtr operator-(const StrBlobPtr &, std::ptrdiff_t);
	friend StrBlobPtr operator-(std::ptrdiff_t, const StrBlobPtr &);
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
	StrBlobPtr &operator+=(std::ptrdiff_t);
	StrBlobPtr &operator-=(std::ptrdiff_t);
	std::string &operator[](std::ptrdiff_t) const;
	// StrBlobPtr always return string, not const string
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};
StrBlobPtr operator+(const StrBlobPtr &, std::ptrdiff_t);
StrBlobPtr operator+(std::ptrdiff_t, const StrBlobPtr &);
StrBlobPtr operator-(const StrBlobPtr &, std::ptrdiff_t);
StrBlobPtr operator-(std::ptrdiff_t, const StrBlobPtr &);
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
#endif