#ifndef QUERY_H
#define QUERY_H
#include <memory>
#include <string>
#include <iostream>
#include "TextQuery.h"
#include "QueryResult.h"
#include "Query_base.h"
namespace chapter15 {
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
		Query(const std::string &s);
		chapter12::QueryResult eval(const chapter12::TextQuery &t) const {
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
}
#endif