#include <iostream>
#include "Query.h"
using std::cout;
using std::endl;
int main() {
	Query q = Query("fiery") & Query("bird") | Query("wind");
	q.rep();
	return 0;
}