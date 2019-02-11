#include "StrBlob.h"
#include "ConstStrBlobPtr.h"
#include <stdexcept>
using std::shared_ptr;
using std::size_t;
using std::ptrdiff_t;
using std::string;
using std::vector;
using std::runtime_error;
using std::out_of_range;
ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &a, std::size_t sz) :
	wptr(a.data), curr(sz) {}
shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}
const string &ConstStrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}
ConstStrBlobPtr &ConstStrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}
const string &ConstStrBlobPtr::operator[](ptrdiff_t i) const {
	auto n = static_cast<ptrdiff_t>(curr) + i;
	// may overflow if curr is very large
	auto p = check(n, "out of range");
	return (*p)[n];
}
bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock()) {
		throw runtime_error("Iterator not point to same StrBlob");
	}
	return lhs.curr == rhs.curr;
}
bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	return !(lhs == rhs);
}
bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock()) {
		throw runtime_error("Iterator not point to same StrBlob");
	}
	return lhs.curr < rhs.curr;
}
bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	return rhs < lhs;
}
bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	return !(rhs < lhs);
}
bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
	return !(lhs < rhs);
}