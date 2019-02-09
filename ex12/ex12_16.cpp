#include <memory>
using std::unique_ptr;
void f(unique_ptr<int> ptr) {

}
int main() {
	unique_ptr<int> p(new int(42));
	unique_ptr<int> p2 = p;
	f(p);
	return 0;
}