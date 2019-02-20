#include <iostream>
#include <stdexcept>
using std::out_of_range;
using std::cout;
using std::endl;
template <unsigned N> class QuizAnswer {
public:
	void set(unsigned pos, bool b = true) {
		chk_pos(pos);
		if (b) {
			answer[pos / 64] |= 1ull << (pos % 64);
		}
		else {
			answer[pos / 64] &= ~(1ull << (pos % 64));
		}
	}
	bool get(unsigned pos) const {
		chk_pos(pos);
		return answer[pos / 64] & (1ull << (pos % 64));
	}
private:
	void chk_pos(unsigned pos) const {
		if (pos >= N) {
			throw out_of_range("out of range");
		}
	}
	static constexpr unsigned getIndex(unsigned pos) {
		return pos / 64 + (pos % 64 == 0 ? 0 : 1);
	}
	unsigned long long answer[getIndex(N)]{ 0 };
};
template <unsigned N>
unsigned score(const QuizAnswer<N> &qa, unsigned long long answer) {
	unsigned ret = 0;
	for (unsigned i = 0; i < N; ++i) {
		if (qa.get(i) == static_cast<bool>(answer & (1ull << i))) {
			++ret;
		}
	}
	return ret;
}
int main() {
	QuizAnswer<10> d;
	d.set(2);
	d.set(3);
	d.set(5);
	d.set(7);
	d.set(8);
	// right answer:  0110101100
	// answer1:       1010101001
	// answer2:       0110101101
	unsigned long long answer1 = 681;
	cout << score(d, answer1) << endl;
	unsigned long long answer2 = 429;
	cout << score(d, answer2) << endl;
	return 0;
}