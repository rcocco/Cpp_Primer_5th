#include <iostream>
#include <fstream>
#include "Query.h"
#include "TextQuery.h"
#include "QueryResult.h"
using std::ifstream;
using std::cout;
using std::cerr;
using std::endl;
int main() {
	ifstream ifs("dandelion.txt");
	if (ifs) {
		TextQuery tq(ifs);
		Query q = Query("ago") | Query("deer");
		print(cout, q.eval(tq));
	}
	else {
		cerr << "Cannot open file." << endl;
		return -1;
	}
	return 0;
}