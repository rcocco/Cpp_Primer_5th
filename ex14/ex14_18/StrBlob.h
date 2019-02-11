#ifndef STRBLOB_H
#define STRBLOB_H
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>
#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"
class StrBlob {
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator<=(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator>(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator>=(const StrBlob &lhs, const StrBlob &rhs);
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	StrBlob(const StrBlob &);
	StrBlob &operator=(const StrBlob &);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const std::string &t) { data->push_back(t); }
	void push_back(std::string &&t) { data->push_back(std::move(t)); }
	void pop_back();
	std::string &front();
	const std::string &front() const;
	std::string &back();
	const std::string &back() const;
	StrBlobPtr begin();
	StrBlobPtr end();
	ConstStrBlobPtr cbegin() const;
	ConstStrBlobPtr cend() const;
	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;
};
bool operator==(const StrBlob &lhs, const StrBlob &rhs);
bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
bool operator<(const StrBlob &lhs, const StrBlob &rhs);
bool operator<=(const StrBlob &lhs, const StrBlob &rhs);
bool operator>(const StrBlob &lhs, const StrBlob &rhs);
bool operator>=(const StrBlob &lhs, const StrBlob &rhs);
#endif