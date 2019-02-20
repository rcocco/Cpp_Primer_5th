#include "Query.h"
#include "WordQuery.h"
#include "NotQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include <iostream>
#include <memory>
using std::ostream;
using std::shared_ptr;
namespace chapter15 {
	Query::Query(const std::string &s) :q(new WordQuery(s)) {}
	Query operator~(const Query &operand) {
		return shared_ptr<Query_base>(new NotQuery(operand));
	}
	Query operator&(const Query &lhs, const Query &rhs) {
		return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
	}
	Query operator|(const Query &lhs, const Query &rhs) {
		return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
	}
	ostream &operator<<(ostream &os, const Query &query) {
		return os << query.rep();
	}
}