#include "Screen.h"
#include "Window_mgr.h"
#include <string>
using std::string;
Window_mgr::Window_mgr() :screens{ Screen(24,80,' ') } { }
void Window_mgr::clear(ScreenIndex i) {
	Screen &s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}