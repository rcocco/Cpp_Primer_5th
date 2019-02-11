#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <memory>
#include <utility>
#include <cstddef>
#include <initializer_list>
class String {
	friend std::ostream &operator<<(std::ostream &os, const String &s);
	friend bool operator==(const String &lhs, const String &rhs);
	friend bool operator!=(const String &lhs, const String &rhs);
	friend bool operator<(const String &lhs, const String &rhs);
	friend bool operator>(const String &lhs, const String &rhs);
	friend bool operator<=(const String &lhs, const String &rhs);
	friend bool operator>=(const String &lhs, const String &rhs);
public:
	typedef std::size_t size_t;
	String() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const char*);
	String(std::initializer_list<char>);
	String(const String&);
	String(String &&) noexcept;
	String &operator=(const String&);
	String &operator=(String &&);
	~String();
	void push_back(char);
	char &operator[](size_t n) {
		// build-in operator[] for pointer
		// a[b] == *(a + b)
		return elements[n];
	}
	const char &operator[](size_t n) const {
		return elements[n];
	}
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	void reserve(size_t);
	void resize(size_t, char);
	char *begin() const { return elements; }
	char *end() const { return first_free; }
private:
	static std::allocator<char> alloc;
	void chk_n_alloc() {
		if (size() == capacity()) reallocate();
	}
	std::pair<char*, char*> alloc_n_copy
		(const char*, const char*);
	void free();
	void reallocate();
	char *elements;
	char *first_free;
	char *cap;
};
std::ostream &operator<<(std::ostream &os, const String &s);
bool operator==(const String &lhs, const String &rhs);
bool operator!=(const String &lhs, const String &rhs);
bool operator<(const String &lhs, const String &rhs);
bool operator>(const String &lhs, const String &rhs);
bool operator<=(const String &lhs, const String &rhs);
bool operator>=(const String &lhs, const String &rhs);
#endif