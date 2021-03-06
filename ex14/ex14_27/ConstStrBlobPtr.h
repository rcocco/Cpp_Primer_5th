#ifndef CONSTSTRBLOBPTR_H
#define CONSTSTRBLOBPTR_H
#include <memory>
#include <vector>
#include <cstddef>
#include <string>
class StrBlob;
class ConstStrBlobPtr {
	friend bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
	friend bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
	friend bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
	friend bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
	friend bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
	friend bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
public:
	ConstStrBlobPtr() :curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0);
	const std::string &operator*() const;
	ConstStrBlobPtr &operator++();
	ConstStrBlobPtr &operator--();
	ConstStrBlobPtr operator++(int);
	ConstStrBlobPtr operator--(int);
	const std::string &operator[](std::ptrdiff_t) const;
	// ConstStrBlobPtr always return const string
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};
bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
#endif