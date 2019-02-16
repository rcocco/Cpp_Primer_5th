#ifndef ORQUERY_H
#define ORQUERY_H
#include "BinaryQuery.h"
#include "Query.h"
#include "QueryResult.h"
#include "TextQuery.h"
class OrQuery :public BinaryQuery {
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "|") {}
	QueryResult eval(const TextQuery &) const;
};
#endif