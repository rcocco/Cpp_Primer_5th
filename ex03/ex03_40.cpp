#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iterator>
using std::begin;
using std::end;
using std::cout;
using std::endl;
int main() {
	char s1[] = "abcde";
	char s2[] = "123456789";
	// ��������ʱά����Ҫ������constexprֵ
	// begin��end�����з���constexprֵ�İ汾��strlen����û��
	char s3[(end(s1)-begin(s1)) + (end(s2)-begin(s2)) - 1];
	strcpy(s3, s1);
	strcat(s3, s2);
	cout << s3 << endl;
	return 0;
}