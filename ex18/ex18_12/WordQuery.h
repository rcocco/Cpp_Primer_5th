#ifndef WORDQUERY_H
#define WORDQUERY_H
#include "Query_base.h"
#include "QueryResult.h"
#include <string>
namespace chapter15 {
	class WordQuery : public Query_base {
		friend class Query;
		WordQuery(const std::string &s) :query_word(s) {}
		chapter12::QueryResult eval(const chapter12::TextQuery &t) const {
			return t.query(query_word);
		}
		std::string rep() const { return query_word; }
		std::string query_word;
	};
}
#endif