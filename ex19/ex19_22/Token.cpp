#include "Token.h"
#include "Sales_data.h"
#include <string>
using std::string;
Token &Token::operator=(int i) {
	if (tok == STR) sval.~string();
	else if (tok == SALE) sdval.~Sales_data();
	ival = i;
	tok = INT;
	return *this;
}
Token &Token::operator=(char c) {
	if (tok == STR) sval.~string();
	else if (tok == SALE) sdval.~Sales_data();
	cval = c;
	tok = CHAR;
	return *this;
}
Token &Token::operator=(double d) {
	if (tok == STR) sval.~string();
	else if (tok == SALE) sdval.~Sales_data();
	dval = d;
	tok = DBL;
	return *this;
}
Token &Token::operator=(const string &s) {
	if (tok == STR) {
		sval = s;
	}
	else {
		if (tok == SALE)
			sdval.~Sales_data();
		new (&sval) string(s);
	}
	tok = STR;
	return *this;
}
Token &Token::operator=(const Sales_data &s) {
	if (tok == SALE) {
		sdval = s;
	}
	else {
		if (tok == STR)
			sval.~string();
		new (&sdval) Sales_data(s);
	}
	tok = SALE;
	return *this;
}
void Token::copyUnion(const Token &t) {
	switch (t.tok) {
	case Token::INT: ival = t.ival; break;
	case Token::CHAR: cval = t.cval; break;
	case Token::DBL: dval = t.dval; break;
	case Token::STR: new(&sval) string(t.sval); break;
	case Token::SALE: new(&sdval) Sales_data(t.sdval); break;
	}
}
Token &Token::operator=(const Token &t) {
	if (tok == STR && t.tok != STR) sval.~string();
	else if (tok == SALE && t.tok != SALE) sdval.~Sales_data();
	if (tok == STR && t.tok == STR)
		sval = t.sval;
	else if (tok == SALE && t.tok == SALE)
		sdval = t.sdval;
	else
		copyUnion(t);
	tok = t.tok;
	return *this;
}