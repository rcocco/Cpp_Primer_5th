#include <iostream>
#include <string>
#include <cstddef>
using std::size_t;
using std::string;
using std::cout;
using std::endl;

char *concat(const char *s1, const char *s2) {
	if (s1 && s2) {
		size_t s1len = 0, s2len = 0;
		for (auto p1 = s1; *p1 != '\0'; ++p1, ++s1len);
		for (auto p2 = s2; *p2 != '\0'; ++p2, ++s2len);
		size_t slen = s1len + s2len;
		char *s = new char[slen+1];
		auto p = s;
		for (auto p1 = s1; *p1 != '\0'; ++p,++p1) {
			*p = *p1;
		}
		for (auto p2 = s2; *p2 != '\0'; ++p,++p2) {
			*p = *p2;
		}
		*p = '\0';
		return s;
	}
	else {
		return nullptr;
	}
}
char *concat(const string &s1, const string &s2) {
	string str = s1 + s2;
	char *s = new char[str.size()+1];
	auto p = s;
	for (auto ch : str) {
		*p++ = ch;
	}
	*p = '\0';
	return s;
}
int main() {
	auto s = concat("Hello", "World");
	cout << s << endl;
	delete[] s;
	auto s1 = concat(string("Hello"), string("World"));
	cout << s1 << endl;
	delete[] s1;
	return 0;
}