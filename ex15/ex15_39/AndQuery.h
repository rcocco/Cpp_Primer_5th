#ifndef ANDQUERY_H
#define ANDQUERY_H
#include "BinaryQuery.h"
#include "Query.h"
#include "QueryResult.h"
#include "TextQuery.h"
class AndQuery:public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "&") {}
	QueryResult eval(const TextQuery &) const;
};
#endif