#include <iostream>
#include <utility>
using std::cout;
using std::endl;
template <typename F,typename T1,typename T2>
void flip(F f, T1 &&t1, T2 &&t2) {
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}
void f(int v1, int &v2) {
	cout << v1 << " " << ++v2 << endl;
}
void g(int &&i, int &j) {
	cout << i << " " << j << endl;
}
int main() {
	int j = 2;
	flip(f, j, 42);
	flip(g, j, 42);
	return 0;
}