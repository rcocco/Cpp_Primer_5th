#include <iostream>
#include <memory>
using std::shared_ptr;
using std::cout;
using std::endl;
struct destination{};
struct connection{};
connection connect(destination *dest) {
	cout << "open connection" << endl;
	return connection();
}
void disconnect(connection c) {
	cout << "close connection" << endl;
}
void end_connection(connection *p) { disconnect(*p); }
void f(destination &d) {
	cout << "Auto Free" << endl;
	connection c = connect(&d);
	shared_ptr<connection> p(&c, end_connection);
}
void f_noauto(destination &d) {
	cout << "No Auto Free" << endl;
	connection c = connect(&d);
}
int main() {
	destination dest;
	f_noauto(dest);
	cout << endl;
	f(dest);
	cout << endl;
	return 0;
}