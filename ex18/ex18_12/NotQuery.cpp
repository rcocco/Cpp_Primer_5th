#include "NotQuery.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include <memory>
#include <set>
#include <cstddef>
using std::set;
using std::size_t;
using chapter12::QueryResult;
using chapter12::TextQuery;
using std::make_shared;
namespace chapter15 {
	QueryResult NotQuery::eval(const TextQuery &text) const {
		auto result = query.eval(text);
		auto ret_lines = make_shared<set<line_no>>();
		auto beg = result.begin(), end = result.end();
		auto sz = result.get_file()->size();
		for (size_t n = 0; n != sz; ++n) {
			if (beg == end || *beg != n)
				ret_lines->insert(n);
			else if (beg != end)
				++beg;
		}
		return QueryResult(rep(), ret_lines, result.get_file());
	}
}