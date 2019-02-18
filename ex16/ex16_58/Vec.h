#ifndef VEC_H
#define VEC_H
#include <memory>
#include <string>
#include <cstddef>
#include <utility>
#include <iterator>
#include <initializer_list>
template <typename> class Vec;
template <typename T>
bool operator==(const Vec<T> &, const Vec<T> &);
template <typename T>
bool operator!=(const Vec<T> &, const Vec<T> &);
template <typename T>
bool operator<(const Vec<T> &, const Vec<T> &);
template <typename T>
bool operator>(const Vec<T> &, const Vec<T> &);
template <typename T>
bool operator<=(const Vec<T> &, const Vec<T> &);
template <typename T>
bool operator>=(const Vec<T> &, const Vec<T> &);
template <typename T> class Vec {
	friend bool operator==<T>(const Vec<T> &, const Vec<T> &);
	friend bool operator!=<T>(const Vec<T> &, const Vec<T> &);
	friend bool operator< <T>(const Vec<T> &, const Vec<T> &);
	friend bool operator> <T>(const Vec<T> &, const Vec<T> &);
	friend bool operator<=<T>(const Vec<T> &, const Vec<T> &);
	friend bool operator>=<T>(const Vec<T> &, const Vec<T> &);
public:
	typedef std::size_t size_t;
	Vec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(std::initializer_list<T>);
	Vec(const Vec&);
	Vec(Vec &&) noexcept;
	Vec &operator=(const Vec&);
	Vec &operator=(Vec &&) noexcept;
	Vec &operator=(std::initializer_list<T>);
	~Vec();
	void push_back(const T&);
	void push_back(T&&);
	template <typename...Args>
	void emplace_back(Args&&...args);
	T &operator[](size_t n) {
		// build-in operator[] for pointer
		// a[b] == *(a + b)
		return elements[n];
	}
	const T &operator[](size_t n) const {
		return elements[n];
	}
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	void reserve(size_t);
	void resize(size_t, const T&);
	T *begin() const { return elements; }
	T *end() const { return first_free; }
private:
	static std::allocator<T> alloc;
	void chk_n_alloc() {
		if (size() == capacity()) reallocate();
	}
	std::pair<T*, T*> alloc_n_copy(const T*, const T*);
	void free();
	void reallocate();
	T *elements;
	T *first_free;
	T *cap;
};
template <typename T>
std::allocator<T> Vec<T>::alloc;
template <typename T>
void Vec<T>::push_back(const T &s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
template <typename T>
void Vec<T>::push_back(T &&s) {
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}
template <typename T>
template <typename...Args>
void Vec<T>::emplace_back(Args&&...args) {
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}
template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e) {
	auto data = alloc.allocate(e - b);
	return { data,std::uninitialized_copy(b,e,data) };
}
template <typename T>
void Vec<T>::free() {
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}
template <typename T>
Vec<T>::Vec(std::initializer_list<T> il) {
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
template <typename T>
Vec<T>::Vec(const Vec &s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
template <typename T>
Vec<T>::Vec(Vec &&s) noexcept :elements(s.elements), first_free(s.first_free), cap(s.cap) {
	s.elements = s.first_free = s.cap = nullptr;
}
template <typename T>
Vec<T>::~Vec() { free(); }
template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs) {
	auto data = std::alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
template <typename T>
Vec<T> &Vec<T>::operator=(std::initializer_list<T> il) {
	auto data = std::alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
template <typename T>
Vec<T> &Vec<T>::operator=(Vec &&rhs) noexcept {
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}
template <typename T>
void Vec<T>::reallocate() {
	auto newcapacity = size() ? 2 * size() : 1;
	reserve(newcapacity);
}
template <typename T>
void Vec<T>::reserve(size_t n) {
	if (n > capacity()) {
		auto first = alloc.allocate(n);
		auto last = std::uninitialized_copy(std::make_move_iterator(begin()),
			std::make_move_iterator(end()), first);
		free();
		elements = first;
		first_free = last;
		cap = elements + n;
	}
}
template <typename T>
void Vec<T>::resize(size_t n, const T &s) {
	if (n > size()) {
		reserve(n);
		while (size() != n) {
			alloc.construct(first_free++, s);
		}
	}
	else {
		while (first_free != elements + n) {
			alloc.destroy(--first_free);
		}
	}
}
template <typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs) {
	if (lhs.size() != rhs.size()) return false;
	for (auto lb = lhs.begin(), rb = rhs.begin(); 
		lb != lhs.end() && rb != rhs.end(); 
		++lb, ++rb) {
		if (*lb != *rb) {
			return false;
		}
	}
	return true;
}
template <typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs) {
	return !(lhs == rhs);
}
template <typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs) {
	auto lbeg = lhs.begin(), rbeg = rhs.begin();
	for (; lbeg != lhs.end() && rbeg != rhs.end(); ++lbeg, ++rbeg) {
		if (*lbeg < *rbeg) return true;
		else if (*rbeg < *lbeg) return false;
	}
	return lbeg == lhs.end() && rbeg != rhs.end();
}
template <typename T>
bool operator>(const Vec<T> &lhs, const Vec<T> &rhs) {
	return rhs < lhs;
}
template <typename T>
bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs) {
	return !(rhs < lhs);
}
template <typename T>
bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs) {
	return !(lhs < rhs);
}
#endif