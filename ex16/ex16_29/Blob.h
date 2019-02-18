#ifndef BLOB_H
#define BLOB_H
#include <stdexcept>
#include <vector>
#include <string>
#include <initializer_list>
#include "Shared_ptr.h"
#include "DebugDelete.h"
#include "BlobPtr.h"
template <typename> class Blob;
template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &);
template <typename T>
bool operator!=(const Blob<T> &, const Blob<T> &);
template <typename T>
bool operator<(const Blob<T> &, const Blob<T> &);
template <typename T>
bool operator<=(const Blob<T> &, const Blob<T> &);
template <typename T>
bool operator>(const Blob<T> &, const Blob<T> &);
template <typename T>
bool operator>=(const Blob<T> &, const Blob<T> &);
template <typename T> class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T> &, const Blob<T> &);
	friend bool operator!=<T>(const Blob<T> &, const Blob<T> &);
	friend bool operator< <T>(const Blob<T> &, const Blob<T> &);
	friend bool operator<=<T>(const Blob<T> &, const Blob<T> &);
	friend bool operator> <T>(const Blob<T> &, const Blob<T> &);
	friend bool operator>=<T>(const Blob<T> &, const Blob<T> &);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	Blob();
	Blob(std::initializer_list<T> il);
	template <typename IT> Blob(IT beg, IT end);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	T &back();
	const T &back() const;
	T &front();
	const T &front() const;
	T &operator[](size_type i);
	const T &operator[](size_type i) const;
	BlobPtr<T> begin();
	BlobPtr<T> end();
private:
	Shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string &msg) const;
};
template<typename T>
Blob<T>::Blob() :data(Shared_ptr<std::vector<T>>(new std::vector<T>(),DebugDelete())) {}
template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) :
	data(Shared_ptr<std::vector<T>>(new std::vector<T>(il),DebugDelete())) {}
template <typename T>
template <typename IT>
Blob<T>::Blob(IT beg, IT end) : 
	data(Shared_ptr<std::vector<T>>(new std::vector<T>(beg,end), DebugDelete())) {}
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
	if (i >= data->size())
		throw std::out_of_range(msg);
}
template <typename T>
void Blob<T>::pop_back() {
	check(0, "pop_back on empty Blob");
	data->back();
}
template <typename T>
T &Blob<T>::back() {
	check(0, "back on empty Blob");
	return data->back();
}
template <typename T>
const T &Blob<T>::back() const {
	check(0, "back on empty Blob");
	return data->back();
}
template <typename T>
T &Blob<T>::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}
template <typename T>
const T &Blob<T>::front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}
template <typename T>
T &Blob<T>::operator[](size_type i) {
	check(i, "subscript out of range");
	return (*data)[i];
}
template <typename T>
const T &Blob<T>::operator[](size_type i) const {
	check(i, "subscript out of range");
	return (*data)[i];
}
template <typename T>
BlobPtr<T> Blob<T>::begin() {
	return BlobPtr<T>(*this);
}
template <typename T>
BlobPtr<T> Blob<T>::end() {
	auto ret = BlobPtr<T>(*this, data->size());
	return ret;
}
template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
	return *lhs.data == *rhs.data;
}
template <typename T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs) {
	return !(lhs == rhs);
}
template <typename T>
bool operator<(const Blob<T> &lhs, const Blob<T> &rhs) {
	return *lhs.data < *rhs.data;
}
template <typename T>
bool operator>(const Blob<T> &lhs, const Blob<T> &rhs) {
	return rhs < lhs;
}
template <typename T>
bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs) {
	return !(rhs < lhs);
}
template <typename T>
bool operator>=(const Blob<T> &lhs, const Blob<T> &rhs) {
	return !(lhs < rhs);
}
#endif