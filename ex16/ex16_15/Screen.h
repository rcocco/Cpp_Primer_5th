#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <string>
template <std::string::size_type ht,std::string::size_type wd>
class Screen {
public:
	typedef std::string::size_type pos;
	Screen(char c = ' ') : contents(ht * wd,c) { }
	Screen set(char c);
	Screen set(pos r, pos col, char ch);
	char get() const { return contents[cursor]; }
	char get(pos r, pos c) const;
	Screen move(pos r, pos c);
	Screen display(std::ostream &os)
			{ do_display(os); return *this; }
	const Screen display(std::ostream &os) const 
			{ do_display(os); return *this; }
private:
	void do_display(std::ostream &os) const { os << contents; }
	pos cursor = 0;
	std::string contents;
};
template <std::string::size_type ht, std::string::size_type wd>
inline Screen<ht, wd> Screen<ht, wd>::set(char c) {
	contents[cursor] = c;
	return *this;
}
template <std::string::size_type ht, std::string::size_type wd>
inline Screen<ht, wd> Screen<ht, wd>::set(pos r, pos col, char ch) {
	contents[r*wd + col] = ch;
	return *this;
}
template <std::string::size_type ht, std::string::size_type wd>
inline char Screen<ht, wd>::get(pos r, pos c) const {
	pos row = r * wd;
	return contents[row + c];
}
template <std::string::size_type ht, std::string::size_type wd>
inline Screen<ht, wd> Screen<ht, wd>::move(pos r, pos c) {
	pos row = r * wd;
	cursor = row + c;
	return *this;
}
template <std::string::size_type ht, std::string::size_type wd>
std::ostream &operator<<(std::ostream &os, const Screen<ht, wd> &screen) {
	for (std::string::size_type i = 0; i < ht; ++i) {
		for (std::string::size_type j = 0; j < wd; ++j) {
			os << screen.get(i, j);
		}
		os << std::endl;
	}
	return os;
}
template <std::string::size_type ht, std::string::size_type wd>
std::istream &operator>>(std::istream &is, Screen<ht, wd> &screen) {
	char ch;
	for (std::string::size_type i = 0; i < ht; ++i) {
		for (std::string::size_type j = 0; j < wd; ++j) {
			if (is.get(ch)) {
				screen.set(i, j, ch);
			}
			else {
				return is;
			}
		}
	}
	return is;
}
#endif
