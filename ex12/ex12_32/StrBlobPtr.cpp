#include "StrBlob.h"
#include "StrBlobPtr.h"
#include <stdexcept>
using std::shared_ptr;
using std::size_t;
using std::string;
using std::vector;
using std::runtime_error;
using std::out_of_range;
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
bool StrBlobPtr::equal(const StrBlobPtr &rhs) const {
	return wptr.lock() == rhs.wptr.lock() && curr == rhs.curr;
}
bool StrBlobPtr::notEqual(const StrBlobPtr &rhs) const {
	return !equal(rhs);
}