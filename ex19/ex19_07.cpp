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
	AndQuery aq;
	WordQuery wq;
	Query_base &qb = aq;
	Query_base &qb1 = wq;
	try {
		AndQuery &raq = dynamic_cast<AndQuery&>(qb);
		cout << "cast success" << endl;
	}
	catch (std::bad_cast) {
		cout << "cast failed" << endl;
	}
	return 0;
}
