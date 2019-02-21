#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include "Sales_data.h"
class Token {
public:
	Token() :tok(INT), ival{ 0 }{}
	Token(const Token &t) :tok(t.tok) { copyUnion(t); }
	Token(Token &&t) :tok(t.tok) { moveUnion(std::move(t)); }
	Token &operator=(const Token&);
	Token &operator=(Token &&);
	~Token() {
		if (tok == STR) sval.~basic_string();
		else if (tok == SALE) sdval.~Sales_data();
	}
	// in namespace std: 
	// typedef basic_string<char> string;
	// so string is just an alias-declaration
	// if you want to use ~string(), you need
	// using std::string;
	Token &operator=(const std::string &);
	Token &operator=(const Sales_data &);
	Token &operator=(char);
	Token &operator=(int);
	Token &operator=(double);
private:
	enum { INT, CHAR, DBL, STR, SALE } tok;
	union {
		char cval;
		int ival;
		double dval;
		std::string sval;
		Sales_data sdval;
	};
	void copyUnion(const Token&);
	void moveUnion(Token &&);
};
#endif