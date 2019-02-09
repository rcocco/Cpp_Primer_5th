#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H
#include <memory>
#include <vector>
#include <cstddef>
#include <string>
#include "StrBlob.h"
class StrBlobPtr {
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &a, std::size_t sz = 0):
		wptr(a.data), curr(sz) {}
	std::string &deref() const;
	StrBlobPtr &incr();
	bool equal(const StrBlobPtr &rhs) const;
	bool notEqual(const StrBlobPtr &rhs) const;
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};
#endif