#ifndef QUERY_H
#define QUERY_H
#include <memory>
#include <string>
#include <iostream>
#include "TextQuery.h"
#include "QueryResult.h"
#include "Query_base.h"
class Query {
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
public:
	Query(const std::string &s);
	QueryResult eval(const TextQuery &t) const {
		return q->eval(t);
	}
	std::string rep() const {
		return q->rep();
	}
private:
	Query(std::shared_ptr<Query_base> query) :q(query) {}
	std::shared_ptr<Query_base> q;
};
Query operator~(const Query &);
Query operator|(const Query &, const Query &);
Query operator&(const Query &, const Query &);
std::ostream &operator<<(std::ostream &os, const Query &);
#endif