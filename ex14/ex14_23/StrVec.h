#ifndef STRVEC_H
#define STRVEC_H
#include <memory>
#include <string>
#include <cstddef>
#include <utility>
#include <initializer_list>
class StrVec {
	friend bool operator==(const StrVec &lhs, const StrVec &rhs);
	friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
	friend bool operator<(const StrVec &lhs, const StrVec &rhs);
	friend bool operator>(const StrVec &lhs, const StrVec &rhs);
	friend bool operator<=(const StrVec &lhs, const StrVec &rhs);
	friend bool operator>=(const StrVec &lhs, const StrVec &rhs);
public:
	typedef std::size_t size_t;
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(std::initializer_list<std::string>);
	StrVec(const StrVec&);
	StrVec(StrVec &&) noexcept;
	StrVec &operator=(const StrVec&);
	StrVec &operator=(StrVec &&) noexcept;
	StrVec &operator=(std::initializer_list<std::string>);
	~StrVec();
	void push_back(const std::string&);
	void push_back(std::string&&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	void reserve(size_t);
	void resize(size_t, const std::string& = std::string());
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }
private:
	static std::allocator<std::string> alloc;
	void chk_n_alloc() {
		if (size() == capacity()) reallocate();
	}
	std::pair<std::string*, std::string*> alloc_n_copy
	(const std::string*, const std::string*);
	void free();
	void reallocate();
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};
bool operator==(const StrVec &lhs, const StrVec &rhs);
bool operator!=(const StrVec &lhs, const StrVec &rhs);
bool operator<(const StrVec &lhs, const StrVec &rhs);
bool operator>(const StrVec &lhs, const StrVec &rhs);
bool operator<=(const StrVec &lhs, const StrVec &rhs);
bool operator>=(const StrVec &lhs, const StrVec &rhs);
#endif