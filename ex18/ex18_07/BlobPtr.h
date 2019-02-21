#ifndef BLOBPTR_H
#define BLOBPTR_H
#include <memory>
#include <vector>
#include <cstddef>
#include <string>
#include <stdexcept>
template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T>
BlobPtr<T> operator+(const BlobPtr<T> &, std::ptrdiff_t);
template <typename T>
BlobPtr<T> operator+(std::ptrdiff_t, const BlobPtr<T> &);
template <typename T>
BlobPtr<T> operator-(const BlobPtr<T> &, std::ptrdiff_t);
template <typename T>
BlobPtr<T> operator-(std::ptrdiff_t, const BlobPtr<T> &);
template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &);
template <typename T>
bool operator!=(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T>
bool operator< (const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T>
bool operator> (const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T>
bool operator<=(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T>
bool operator>=(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> class BlobPtr {
	friend BlobPtr<T> operator+<T>(const BlobPtr<T> &, std::ptrdiff_t);
	friend BlobPtr<T> operator+<T>(std::ptrdiff_t, const BlobPtr<T> &);
	friend BlobPtr<T> operator-<T>(const BlobPtr<T> &, std::ptrdiff_t);
	friend BlobPtr<T> operator-<T>(std::ptrdiff_t, const BlobPtr<T> &);
	friend bool operator==<T>(const BlobPtr<T> &lhs, const BlobPtr<T> &);
	friend bool operator!=<T>(const BlobPtr<T> &, const BlobPtr<T> &);
	friend bool operator< <T>(const BlobPtr<T> &, const BlobPtr<T> &);
	friend bool operator> <T>(const BlobPtr<T> &, const BlobPtr<T> &);
	friend bool operator<=<T>(const BlobPtr<T> &, const BlobPtr<T> &);
	friend bool operator>=<T>(const BlobPtr<T> &, const BlobPtr<T> &);
public:
	BlobPtr() :curr(0) {}
	BlobPtr(Blob<T> &a, std::size_t sz = 0);
	T &operator*() const;
	T *operator->() const;
	BlobPtr &operator++();
	BlobPtr &operator--();
	BlobPtr operator++(int);
	BlobPtr operator--(int);
	BlobPtr &operator+=(std::ptrdiff_t);
	BlobPtr &operator-=(std::ptrdiff_t);
	T &operator[](std::ptrdiff_t) const;
private:
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};
template <typename T>
BlobPtr<T>::BlobPtr(Blob<T> &a, std::size_t sz) try:
	wptr(a.data), curr(sz) {}
catch (...) {}
template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string &msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound BlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}
template <typename T>
T &BlobPtr<T>::operator*() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}
template <typename T>
T *BlobPtr<T>::operator->() const {
	return &(this->operator*());
}
template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}
template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--() {
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
	BlobPtr ret = *this;
	++*this;
	return ret;
}
template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
	BlobPtr ret = *this;
	--*this;
	return ret;
}
template <typename T>
T &BlobPtr<T>::operator[](std::ptrdiff_t i) const {
	return *(*this + i);
}
template <typename T>
BlobPtr<T> &BlobPtr<T>::operator+=(std::ptrdiff_t i) {
	auto n = static_cast<std::ptrdiff_t>(curr) + i;
	check(n, "out of range");
	curr = n;
	return *this;
}
template <typename T>
BlobPtr<T> &BlobPtr<T>::operator-=(std::ptrdiff_t i) {
	auto n = static_cast<std::ptrdiff_t>(curr) - i;
	check(n, "out of range");
	curr = n;
	return *this;
}
template <typename T>
BlobPtr<T> operator+(const BlobPtr<T> &item, std::ptrdiff_t i) {
	BlobPtr<T> ret = item;
	ret += i;
	return ret;
}
template <typename T>
BlobPtr<T> operator+(std::ptrdiff_t i, const BlobPtr<T> &item) {
	return item + i;
}
template <typename T>
BlobPtr<T> operator-(const BlobPtr<T> &item, std::ptrdiff_t i) {
	BlobPtr<T> ret = item;
	ret -= i;
	return ret;
}
template <typename T>
BlobPtr<T> operator-(std::ptrdiff_t i, const BlobPtr<T> &item) {
	return item - i;
}
template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock()) {
		throw std::runtime_error("Iterator not point to same StrBlob");
	}
	return lhs.curr == rhs.curr;
}
template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return !(lhs == rhs);
}
template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock()) {
		throw std::runtime_error("Iterator not point to same StrBlob");
	}
	return lhs.curr < rhs.curr;
}
template <typename T>
bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return rhs < lhs;
}
template <typename T>
bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return !(rhs < lhs);
}
template <typename T>
bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
	return !(lhs < rhs);
}
#endif