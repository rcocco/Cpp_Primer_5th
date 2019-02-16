#ifndef ANDQUERY_H
#define ANDQUERY_H
#include "BinaryQuery.h"
#include "Query.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include <iostream>
class AndQuery:public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "&") {
		std::cout << "AndQuery(const Query &, const Query &)" << std::endl;
	}
};
#endif