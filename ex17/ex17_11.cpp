#include <iostream>
using std::cout;
using std::endl;
template <unsigned N> class QuizAnswer {
public:
private:
	static constexpr unsigned getIndex(unsigned pos) {
		return pos / 64 + (pos % 64 == 0 ? 0 : 1);
	}
	unsigned long long answer[getIndex(N)]{0};
};

int main() {
	QuizAnswer<100> d;
	return 0;
}