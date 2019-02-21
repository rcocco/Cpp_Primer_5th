#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;
class Query_base {
public:
	Query_base() {}
	virtual ~Query_base() {}
};
class BinaryQuery :public Query_base {
public:
	BinaryQuery() {}
	~BinaryQuery() {}
};
class AndQuery :public BinaryQuery {
public:
	AndQuery() {}
	~AndQuery(){}
};
class WordQuery :public Query_base {
public:
	WordQuery() {}
	~WordQuery() {}
};
int main() {
	Query_base *qb = new AndQuery;
	Query_base *qb1 = new WordQuery;
	if (AndQuery *aq = dynamic_cast<AndQuery*>(qb)) {
		cout << "cast success" << endl;
	}
	else {
		cout << "cast failed" << endl;
	}
	return 0;
}
