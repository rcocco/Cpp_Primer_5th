#ifndef QUERY_BASE_H
#define QUERY_BASE_H
#include <string>
#include "TextQuery.h"
#include "QueryResult.h"
class Query_base {
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual std::string rep() const = 0;
};
#endif