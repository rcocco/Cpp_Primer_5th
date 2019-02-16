#include "Query.h"
#include "WordQuery.h"
#include "NotQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include <iostream>
using std::ostream;
Query::Query(const std::string &s) :q(new WordQuery(s)),use(new size_t(1)) {}
Query operator~(const Query &operand) {
	return new NotQuery(operand);
}
Query operator&(const Query &lhs, const Query &rhs) {
	return new AndQuery(lhs, rhs);
}
Query operator|(const Query &lhs, const Query &rhs) {
	return new OrQuery(lhs, rhs);
}
ostream &operator<<(ostream &os, const Query &query) {
	return os << query.rep();
}