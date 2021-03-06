#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"
#include <stdexcept>
using std::make_shared;
using std::vector;
using std::string;
using std::initializer_list;
using std::out_of_range;
StrBlob::StrBlob() :data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) :
	data(make_shared<vector<string>>(il)) {}
void StrBlob::check(size_type i, const string &msg) const {
	if (i >= data->size())
		throw out_of_range(msg);
}
string &StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}
const string &StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}
string &StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}
const string &StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}
void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}
StrBlobPtr StrBlob::begin() {
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end() {
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}
ConstStrBlobPtr StrBlob::cbegin() const {
	return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::cend() const {
	auto ret = ConstStrBlobPtr(*this, data->size());
	return ret;
}
ConstStrBlobPtr StrBlob::begin() const {
	return cbegin();
}
ConstStrBlobPtr StrBlob::end() const {
	return cend();
}