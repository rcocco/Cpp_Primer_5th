#ifndef TOKEN_H
#define TOKEN_H
#include <string>
class Token {
public:
	Token() :tok(INT), ival{ 0 }{}
	Token(const Token &t) :tok(t.tok) { copyUnion(t); }
	Token &operator=(const Token&);
	~Token() { if (tok == STR) sval.~basic_string(); }
	// in namespace std: 
	// typedef basic_string<char> string;
	// so string is just an alias-declaration
	// if you want to use ~string(), you need
	// using std::string;
	Token &operator=(const std::string &);
	Token &operator=(char);
	Token &operator=(int);
	Token &operator=(double);
private:
	enum { INT, CHAR, DBL, STR } tok;
	union {
		char cval;
		int ival;
		double dval;
		std::string sval;
	};
	void copyUnion(const Token&);
};
#endif