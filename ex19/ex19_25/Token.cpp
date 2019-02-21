#include "Token.h"
#include "Sales_data.h"
#include <string>
#include <iostream>
using std::string;
using std::ostream;
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
void Token::moveUnion(Token &&t) {
	switch (t.tok) {
		// for build-in type:
		// val = t.val is same as  val = std::move(t.val)
	case Token::INT: ival = t.ival; break;
	case Token::CHAR: cval = t.cval; break;
	case Token::DBL: dval = t.dval; break;
	case Token::STR: new(&sval) string(std::move(t.sval)); break;
	case Token::SALE: new(&sdval) Sales_data(std::move(t.sdval)); break;
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
Token &Token::operator=(Token &&t) {
	if (tok == STR && t.tok != STR) sval.~string();
	else if (tok == SALE && t.tok != SALE) sdval.~Sales_data();
	if (tok == STR && t.tok == STR)
		sval = std::move(t.sval);
	else if (tok == SALE && t.tok == SALE)
		sdval = std::move(t.sdval);
	else
		copyUnion(t);
	tok = t.tok;
	return *this;
}
ostream& operator<<(ostream &os, const Token &t) {
	switch (t.tok) {
	case Token::INT: os << t.ival; break;
	case Token::CHAR: os << t.cval; break;
	case Token::DBL: os << t.dval; break;
	case Token::STR: os << t.sval; break;
	case Token::SALE: os << t.sdval; break;
	}
	return os;
}