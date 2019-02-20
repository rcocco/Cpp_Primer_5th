#ifndef NOTQUERY_H
#define NOTQUERY_H
#include "Query_base.h"
#include "Query.h"
#include "QueryResult.h"
#include <string>
namespace chapter15 {
	class NotQuery :public Query_base {
		friend Query operator~(const Query &);
		NotQuery(const Query &q) :query(q) {}
		std::string rep() const { return "~(" + query.rep() + ")"; }
		chapter12::QueryResult eval(const chapter12::TextQuery&) const;
		Query query;
	};
}
#endif