#include "StrBlob.h"
#include "StrBlobPtr.h"
#include <stdexcept>
using std::shared_ptr;
using std::size_t;
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
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !(lhs==rhs);
}