#include "String.h"
#include <memory>
#include <utility>
#include <iostream>
#include <initializer_list>
using std::pair;
using std::allocator;
using std::initializer_list;
using std::ostream;
using std::uninitialized_copy;
using std::cout;
using std::endl;

allocator<char> String::alloc;
String::String(const char *s) {
	const char *e = s;
	for (; *e != '\0'; ++e);
	auto newdata = alloc_n_copy(s, e);
	elements = newdata.first;
	first_free = cap = newdata.second;
}
void String::push_back(char c) {
	chk_n_alloc();
	alloc.construct(first_free++, c);
}
pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e) {
	auto data = alloc.allocate(e - b);
	return { data,uninitialized_copy(b,e,data) };
}
void String::free() {
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}
String::String(initializer_list<char> il) {
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
String::String(const String &s) {
	cout << "Copy constructor : " << s << endl;
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
String::String(String &&s) noexcept:elements(s.elements),first_free(s.first_free),cap(s.cap){
	cout << "Move constructor : " << s << endl;
	s.elements = s.first_free = s.cap = nullptr;
}
String::~String() { free(); }
String &String::operator=(const String &rhs) {
	cout << "Copy assignment : " << rhs << endl;
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
String &String::operator=(String &&rhs) {
	cout << "Move assignment : " << rhs << endl;
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}
void String::reallocate() {
	auto newcapacity = size() ? 2 * size() : 1;
	reserve(newcapacity);
}
void String::reserve(size_t n) {
	if (n > capacity()) {
		auto newdata = alloc.allocate(n);
		auto dest = newdata;
		auto elem = elements;
		for (size_t i = 0; i != size(); ++i) {
			alloc.construct(dest++, *elem++);
		}
		free();
		elements = newdata;
		first_free = dest;
		cap = elements + n;
	}
}
void String::resize(size_t n, char c) {
	if (n > size()) {
		reserve(n);
		while (size() != n) {
			alloc.construct(first_free++, c);
		}
	}
	else {
		while (first_free != elements + n) {
			alloc.destroy(--first_free);
		}
	}
}
ostream &operator<<(ostream &os, const String &s) {
	for (auto b = s.begin(); b != s.end(); ++b) {
		os << *b;
	}
	return os;
}