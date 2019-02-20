#include <iostream>
#include <fstream>
#include "Query.h"
#include "TextQuery.h"
#include "QueryResult.h"
using std::ifstream;
using chapter12::TextQuery;
using chapter15::Query;
using std::cout;
using std::cerr;
using std::endl;
int main() {
	ifstream ifs("storyDataFile.txt");
	if (ifs) {
		TextQuery tq(ifs);
		Query q = Query("fiery") & Query("bird") | Query("wind");
		print(cout, q.eval(tq));
	}
	else {
		cerr << "Cannot open file." << endl;
		return -1;
	}
	return 0;
}