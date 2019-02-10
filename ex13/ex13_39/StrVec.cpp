#include "StrVec.h"
#include <memory>
#include <string>
#include <utility>
#include <cstddef>
using std::string;
using std::pair;
using std::size_t;
using std::allocator;
using std::uninitialized_copy;
allocator<string> StrVec::alloc;
void StrVec::push_back(const string &s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
pair<string*, string*> 
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
	auto data = alloc.allocate(e - b);
	return { data,uninitialized_copy(b,e,data) };
}
void StrVec::free() {
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}
StrVec::StrVec(const StrVec &s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec::~StrVec() { free(); }
StrVec &StrVec::operator=(const StrVec &rhs) {
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
void StrVec::reallocate() {
	auto newcapacity = size() ? 2 * size() : 1;
	reserve(newcapacity);
}
void StrVec::reserve(size_t n) {
	if (n > capacity()) {
		auto newdata = alloc.allocate(n);
		auto dest = newdata;
		auto elem = elements;
		for (size_t i = 0; i != size(); ++i) {
			alloc.construct(dest++, std::move(*elem++));
		}
		free();
		elements = newdata;
		first_free = dest;
		cap = elements + n;
	}
}
void StrVec::resize(size_t n,const string &s) {
	if (n > size()) {
		reserve(n);
		while (size() != n) {
			alloc.construct(first_free++,s);
		}
	}
	else {
		while (first_free != elements + n) {
			alloc.destroy(--first_free);
		}
	}
}