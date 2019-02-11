#include "StrVec.h"
#include <memory>
#include <string>
#include <utility>
#include <xutility>
#include <initializer_list>
using std::string;
using std::pair;
using std::allocator;
using std::initializer_list;
using std::make_move_iterator;
using std::uninitialized_copy;

allocator<string> StrVec::alloc;
void StrVec::push_back(const string &s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
void StrVec::push_back(string &&s) {
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
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
StrVec::StrVec(initializer_list<string> il) {
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec::StrVec(const StrVec &s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec::StrVec(StrVec &&s) noexcept :elements(s.elements), first_free(s.first_free), cap(s.cap) {
	s.elements = s.first_free = s.cap = nullptr;
}
StrVec::~StrVec() { free(); }
StrVec &StrVec::operator=(const StrVec &rhs) {
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}
void StrVec::reallocate() {
	auto newcapacity = size() ? 2 * size() : 1;
	reserve(newcapacity);
}
void StrVec::reserve(size_t n) {
	if (n > capacity()) {
		auto first = alloc.allocate(n);
		auto last = uninitialized_copy(make_move_iterator(begin()), 
			make_move_iterator(end()), first);
		free();
		elements = first;
		first_free = last;
		cap = elements + n;
		//auto newdata = alloc.allocate(n);
		//auto dest = newdata;
		//auto elem = elements;
		//for (size_t i = 0; i != size(); ++i) {
		//	alloc.construct(dest++, std::move(*elem++));
		//}
		//free();
		//elements = newdata;
		//first_free = dest;
		//cap = elements + n;
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
bool operator==(const StrVec &lhs, const StrVec &rhs) {
	if (lhs.size() != rhs.size()) return false;
	for (auto lb = lhs.begin(), rb = rhs.begin(); lb != lhs.end() && rb != rhs.end(); ++lb, ++rb) {
		if (*lb != *rb) {
			return false;
		}
	}
	return true;
}
bool operator!=(const StrVec &lhs, const StrVec &rhs) {
	return !(lhs == rhs);
}
bool operator<(const StrVec &lhs, const StrVec &rhs) {
	auto lbeg = lhs.begin(), rbeg = rhs.begin();
	for (; lbeg != lhs.end() && rbeg != rhs.end(); ++lbeg, ++rbeg) {
		if (*lbeg < *rbeg) return true;
		else if (*rbeg < *lbeg) return false;
	}
	return lbeg == lhs.end() && rbeg != rhs.end();
}
bool operator>(const StrVec &lhs, const StrVec &rhs) {
	return rhs < lhs;
}
bool operator<=(const StrVec &lhs, const StrVec &rhs) {
	return !(rhs < lhs);
}
bool operator>=(const StrVec &lhs, const StrVec &rhs) {
	return !(lhs < rhs);
}