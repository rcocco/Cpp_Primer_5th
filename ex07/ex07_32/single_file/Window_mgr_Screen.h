#ifndef WINDOW_MGR_SCREEN_H
#define WINDOW_MGR_SCREEN_H
#include <string>
#include <vector>
class Screen;
class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	Window_mgr();
	void clear(ScreenIndex);
private:
	std::vector<Screen> screens;
};
class Screen {
	friend void Window_mgr::clear(ScreenIndex);
public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c = ' ') : height(ht), width(wd),
		contents(ht * wd, c) { }
	Screen set(char c);
	Screen set(pos r, pos col, char ch);
	char get() const { return contents[cursor]; }
	char get(pos r, pos c) const;
	Screen move(pos r, pos c);
	Screen display(std::ostream &os)
	{
		do_display(os); return *this;
	}
	const Screen display(std::ostream &os) const
	{
		do_display(os); return *this;
	}
private:
	void do_display(std::ostream &os) const { os << contents; }
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};
inline Screen Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}
inline Screen Screen::set(pos r, pos col, char ch) {
	contents[r*width + col] = ch;
	return *this;
}
inline char Screen::get(pos r, pos c) const {
	pos row = r * width;
	return contents[row + c];
}
inline Screen Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}
void Window_mgr::clear(ScreenIndex i) {
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}
Window_mgr::Window_mgr():screens{ Screen(24, 80, ' ') } { }
#endif
