#include "StrBlob.h"
#include "StrBlobPtr.h"
#include <stdexcept>
using std::shared_ptr;
using std::size_t;
using std::ptrdiff_t;
using std::string;
using std::vector;
using std::runtime_error;
using std::out_of_range;
StrBlobPtr::StrBlobPtr(StrBlob &a, std::size_t sz) :
	wptr(a.data), curr(sz) {}
shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}
string &StrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}
StrBlobPtr &StrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}
string &StrBlobPtr::operator[](ptrdiff_t i) const {
	auto n = static_cast<ptrdiff_t>(curr) + i;
	// may overflow if curr is very large
	auto p = check(n, "out of range");
	return (*p)[n];
}
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock()) {
		throw runtime_error("Iterator not point to same StrBlob");
	}
	// Rule2 : if p1 != p2 ===>  p1 < p2 or p1 > p2 
	// but if they are point to different StrBlob
	// whether p1 < p2 or p1 > p2 is not right
	// the operator is meaningless
	return lhs.curr == rhs.curr;
}
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !(lhs==rhs);
}
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock()) {
		throw runtime_error("Iterator not point to same StrBlob");
	}
	return lhs.curr < rhs.curr;
}
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return rhs < lhs;
}
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !(rhs < lhs);
}
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !(lhs < rhs);
}