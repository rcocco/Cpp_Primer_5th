#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using std::string;
using std::stack;
using std::cerr;
using std::cout;
using std::endl;
struct ExpItem {
	ExpItem(int t, double n = 0.0) :type(t), num(n) {}
	int type;
	double num;
	static const int NUM = 0, LP = 1,RP = 2,
		ADD = 3, SUB = 4;
};
double calSubExp(stack<ExpItem> &substk) {
	double sum = 0;
	while (substk.size() > 1) {
		double left = substk.top().num;
		substk.pop();
		int op = substk.top().type;
		substk.pop();
		double right = substk.top().num;
		substk.pop();
		if (op == ExpItem::ADD) {
			substk.push(ExpItem(ExpItem::NUM, left + right));
		}
		else{
			substk.push(ExpItem(ExpItem::NUM, left - right));
		}
	}
	return substk.top().num;
}
int main() {
	// 只有数字、加减和括号的简单表达式
	string exp = "-5.3 + ((-2.5 + 3) + 4)";
	// Easy expression.
	// Only numbers, plus , minus and parenthesis. 
	int leftParenthesis = 0;
	stack<ExpItem> stk;
	string::size_type pos = 0, offset = 0;
	while (pos < exp.size()) {
		pos = exp.find_first_not_of(" ", pos);
		if (exp[pos] == '(') {
			stk.push(ExpItem(ExpItem::LP));
			++leftParenthesis;
			++pos;
		}
		else if (exp[pos] == ')' && leftParenthesis) {
			stack<ExpItem> subStk;
			while (stk.top().type != ExpItem::LP) {
				subStk.push(stk.top());
				stk.pop();
			}
			stk.pop();
			--leftParenthesis;
			double subResult = calSubExp(subStk);
			stk.push(ExpItem(ExpItem::NUM, subResult));
			++pos;
		}
		else if (exp[pos] == '+' || exp[pos] == '-') {
			if (stk.empty() || stk.top().type != ExpItem::NUM) {
				double num = stod(exp.substr(pos), &offset);
				stk.push(ExpItem(ExpItem::NUM, num));
				pos += offset;
			}
			else if(exp[pos] == '+'){
				stk.push(ExpItem(ExpItem::ADD));
				++pos;
			}
			else {
				stk.push(ExpItem(ExpItem::SUB));
				++pos;
			}
		}
		else if (isdigit(exp[pos])) {
			double num = stod(exp.substr(pos), &offset);
			stk.push(ExpItem(ExpItem::NUM, num));
			pos += offset;
		}
		else {
			cerr << "Invalid Expression at : " << exp[pos] << endl;
			return -1;
		}
	}
	stack<ExpItem> subStk;
	while (!stk.empty()) {
		subStk.push(stk.top());
		stk.pop();
	}
	double subResult = calSubExp(subStk);
	cout << subResult << endl;
	return 0;
}