#include <iostream>
#include <stdexcept>
using std::out_of_range;
using std::cout;
using std::endl;
template <unsigned N> class QuizAnswer {
public:
	void set(unsigned pos,bool b = true) {
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
	unsigned long long answer[getIndex(N)]{0};
};
int main() {
	QuizAnswer<100> d;
	d.set(65);
	cout << d.get(64) << endl;
	cout << d.get(65) << endl;
	return 0;
}