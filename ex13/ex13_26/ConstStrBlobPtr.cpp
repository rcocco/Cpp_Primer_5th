#include "StrBlob.h"
#include "ConstStrBlobPtr.h"
#include <stdexcept>
using std::shared_ptr;
using std::size_t;
using std::string;
using std::vector;
using std::runtime_error;
using std::out_of_range;
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
bool ConstStrBlobPtr::equal(const ConstStrBlobPtr &rhs) const {
	return wptr.lock() == rhs.wptr.lock() && curr == rhs.curr;
}
bool ConstStrBlobPtr::notEqual(const ConstStrBlobPtr &rhs) const {
	return !equal(rhs);
}