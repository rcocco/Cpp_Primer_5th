#ifndef CONSTSTRBLOBPTR_H
#define CONSTSTRBLOBPTR_H
#include <memory>
#include <vector>
#include <cstddef>
#include <string>
#include "StrBlob.h"
class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() :curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0):
		wptr(a.data), curr(sz) {}
	const std::string &deref() const;
	ConstStrBlobPtr &incr();
	bool equal(const ConstStrBlobPtr &rhs) const;
	bool notEqual(const ConstStrBlobPtr &rhs) const;
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};
#endif