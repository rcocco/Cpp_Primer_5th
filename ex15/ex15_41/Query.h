#ifndef QUERY_H
#define QUERY_H
#include <string>
#include <iostream>
#include <cstddef>
#include "TextQuery.h"
#include "QueryResult.h"
#include "Query_base.h"
class Query {
	friend Query operator~(const Query &);
	// NotQuery must include Query.h because member query
	// but operator~ need include NotQuery.h to new()
	// for inline function , it must be defined in header
	// so inline is not possible
	// https://stackoverflow.com/questions/3992980/c-inline-member-function-in-cpp-file
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
public:
	using size_t = std::size_t;
	Query(const std::string &s);
	Query(const Query &rhs) :q(rhs.q), use(rhs.use) {
		++*use;
	}
	Query &operator=(const Query &rhs) {
		++*rhs.use;
		if (--*use == 0) {
			delete q;
			delete use;
		}
		q = rhs.q;
		use = rhs.use;
		return *this;
	}
	~Query() {
		if (--*use == 0) {
			delete q;
			delete use;
		}
	}
	QueryResult eval(const TextQuery &t) const {
		return q->eval(t);
	}
	std::string rep() const {
		return q->rep();
	}
private:
	Query(Query_base* query) :q(query),use(new size_t(1)) {}
	Query_base *q;
	std::size_t *use;
};
Query operator~(const Query &);
Query operator|(const Query &, const Query &);
Query operator&(const Query &, const Query &);
std::ostream &operator<<(std::ostream &os, const Query &);
#endif