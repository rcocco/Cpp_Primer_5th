#include "OrQuery.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include <memory>
#include <set>
using std::set;
using chapter12::QueryResult;
using chapter12::TextQuery;
using std::make_shared;
namespace chapter15 {
	QueryResult OrQuery::eval(const TextQuery &text) const {
		auto right = rhs.eval(text), left = lhs.eval(text);
		auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
		ret_lines->insert(right.begin(), right.end());
		return QueryResult(rep(), ret_lines, left.get_file());
	}
}