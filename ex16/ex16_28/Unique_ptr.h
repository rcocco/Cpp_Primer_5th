#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H
#include <cstddef>
class DefaultDelete {
	template <typename T, typename D> friend class Unique_ptr;
	template <typename T> void operator()(T *p) const {
		delete p;
	}
};
template <typename,typename> class Unique_ptr;
template <typename T, typename D>
void swap(Unique_ptr<T,D> &, Unique_ptr<T,D> &);
template <typename T, typename D = DefaultDelete> class Unique_ptr {
	friend void swap<T,D>(Unique_ptr<T, D> &, Unique_ptr<T, D> &);
public:
	Unique_ptr(D deleter = D()) :p(nullptr), use(nullptr), del(deleter) {}
	Unique_ptr(T *ptr, D deleter = D()) :p(ptr), use(new std::size_t(1)), del(deleter) {}
	Unique_ptr(const Unique_ptr &) = delete;
	Unique_ptr(Unique_ptr &&) noexcept;
	Unique_ptr &operator=(const Unique_ptr &) = delete;
	Unique_ptr &operator=(Unique_ptr &&) noexcept;
	Unique_ptr &operator=(decltype(nullptr));
	~Unique_ptr();
	explicit operator bool() const { return p; }
	T &operator*() const { return *p; }
	T *operator->() const { return &operator*(); }
	T *get() { return p; }
	T *release();
	void reset(decltype(nullptr) = nullptr);
	void reset(T *);
	void swap(Unique_ptr &);
private:
	T *p;
	std::size_t *use;
	D del;
};
template <typename T,typename D>
Unique_ptr<T, D>::Unique_ptr(Unique_ptr &&rhs) noexcept:
	p(std::move(rhs.p)),use(std::move(rhs.use)),
	del(std::move(rhs.del)){
	rhs.p = nullptr;
	rhs.use = nullptr;
}
template <typename T, typename D>
Unique_ptr<T, D> &Unique_ptr<T, D>::operator=(Unique_ptr &&rhs) noexcept {
	if (this != &rhs) {
		if (use && --*use == 0) {
			del(p);
			delete use;
		}
		p = std::move(rhs.p);
		use = std::move(rhs.use);
		del = std::move(rhs.del);
		rhs.p = nullptr;
		rhs.use = nullptr;
	}
	return *this;
}
template <typename T, typename D>
Unique_ptr<T, D> &Unique_ptr<T, D>::operator=(decltype(nullptr)) {
	if (use && --*use == 0) {
		del(p);
		delete use;
	}
	p = nullptr;
	use = nullptr;
	return *this;
}
template <typename T, typename D>
Unique_ptr<T, D>::~Unique_ptr() {
	if (use && --*use == 0) {
		del(p);
		delete use;
	}
}
template <typename T, typename D>
T *Unique_ptr<T, D>::release() {
	T *ptr = p;
	if (use) {
		delete use;
	}
	p = nullptr;
	use = nullptr;
	return ptr;
}
template <typename T, typename D>
void Unique_ptr<T, D>::reset(decltype(nullptr) null_ptr) {
	if (use && --*use == 0) {
		del(p);
		delete use;
	}
	p = nullptr;
	use = nullptr;
}
template <typename T, typename D>
void Unique_ptr<T, D>::reset(T *ptr) {
	reset();
	p = ptr;
	use = new std::size_t(1);
}
template <typename T, typename D>
void Unique_ptr<T, D>::swap(Unique_ptr &rhs) {
	using std::swap;
	swap(p, rhs.p);
	swap(use, rhs.use);
	swap(del, rhs.del);
}
template <typename T, typename D>
void swap(Unique_ptr<T, D> &lhs, Unique_ptr<T, D> &rhs) {
	using std::swap;
	swap(lhs.p, rhs.p);
	swap(lhs.use, rhs.use);
	swap(lhs.del, rhs.del);
}
#endif