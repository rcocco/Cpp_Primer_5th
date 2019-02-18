#ifndef SHARED_PTR_H
#define SHARED_PTR_H
#include <cstddef>
#include <functional>
template <typename> class Shared_ptr;
template <typename T>
void swap(Shared_ptr<T> &, Shared_ptr<T> &);
template <typename T> class Shared_ptr {
	friend void swap<T>(Shared_ptr<T> &, Shared_ptr<T> &);
public:
	Shared_ptr() :p(nullptr), use(nullptr),del(nullptr) {}
	Shared_ptr(T *ptr, std::function<void(T*)> deleter = nullptr) :
		p(ptr), use(new std::size_t(1)), del(deleter) {}
	Shared_ptr(const Shared_ptr &);
	Shared_ptr &operator=(const Shared_ptr &);
	~Shared_ptr();
	explicit operator bool() const { return p; }
	T& operator*() const { return *p; }
	T* operator->() const { return &operator*(); }
	bool unique() const { return use_count() == 1; }
	std::size_t use_count() const { return use == nullptr ? 0 : *use; }
	void reset(T * = nullptr, std::function<void(T*)> = nullptr);
	T *get() const { return p; }
	void swap(Shared_ptr &);
private:
	T *p;
	std::size_t *use;
	std::function<void(T*)> del;
};
template <typename T>
Shared_ptr<T>::Shared_ptr(const Shared_ptr &rhs):
	p(rhs.p), use(rhs.use),del(rhs.del){
	++*use;
}
template <typename T>
Shared_ptr<T> &Shared_ptr<T>::operator=(const Shared_ptr &rhs) {
	++*rhs.use;
	if (--*use == 0) {
		del ? del(p) : delete p;
		delete use;
	}
	p = rhs.p;
	use = rhs.use;
	del = rhs.del;
	return *this;
}
template <typename T>
Shared_ptr<T>::~Shared_ptr() {
	if (--*use == 0) {
		del ? del(p) : delete p;
		delete use;
	}
}
template <typename T>
void Shared_ptr<T>::reset(T *ptr, std::function<void(T*)> deleter) {
	if (--*use == 0) {
		del ? del(p) : delete p;
		delete use;
		p = nullptr;
		use = nullptr;
		del = nullptr;
	}
	if (ptr) {
		p = ptr;
		use = new int(1);
		del = deleter;
	}
}
template <typename T>
void Shared_ptr<T>::swap(Shared_ptr &rhs) {
	using std::swap;
	swap(p, rhs.p);
	swap(use, rhs.use);
	swap(del, rhs.del);
}
template <typename T>
void swap(Shared_ptr<T> &lhs, Shared_ptr<T> &rhs) {
	using std::swap;
	swap(lhs.p, rhs.p);
	swap(lhs.use, rhs.use);
	swap(lhs.del, rhs.del);
}
#endif