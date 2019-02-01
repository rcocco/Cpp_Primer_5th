#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	unsigned spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
	unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;
	string line;
	while (getline(cin, line)) {
		// getline读入换行符，但不存入字符串中，因此手动补全
		line += '\n';
		char lastCh = '\0';
		for (auto &ch : line) {
			switch (ch) {
			case 'a':
			case 'A':
				++aCnt;
				break;
			case 'e':
			case 'E':
				++eCnt;
				break;
			case 'i':
				++iCnt;
				if (lastCh == 'f') ++fiCnt;
				break;
			case 'f':
				if (lastCh == 'f') ++ffCnt;
				break;
			case 'l':
				if (lastCh == 'f') ++flCnt;
				break;
			case 'I':
				++iCnt;
				break;
			case 'o':
			case 'O':
				++oCnt;
				break;
			case 'u':
			case 'U':
				++uCnt;
				break;
			case ' ':
				++spaceCnt;
				break;
			case '\t':
				++tabCnt;
				break;
			case '\n':
				++newlineCnt;
				break;
			}
			lastCh = ch;
		}
	}
	cout << "Number of vowel a: \t" << aCnt << '\n'
		<< "Number of vowel e: \t" << eCnt << '\n'
		<< "Number of vowel i: \t" << iCnt << '\n'
		<< "Number of vowel o: \t" << oCnt << '\n'
		<< "Number of vowel u: \t" << uCnt << '\n'
		<< "Number of ff : \t\t" << ffCnt << '\n'
		<< "Number of fl : \t\t" << flCnt << '\n'
		<< "Number of fi : \t\t" << fiCnt << '\n'
		<< "Number of space : \t" << spaceCnt << '\n'
		<< "Number of tab : \t" << tabCnt << '\n'
		<< "Number of newline: \t" << newlineCnt << endl;
	return 0;
}