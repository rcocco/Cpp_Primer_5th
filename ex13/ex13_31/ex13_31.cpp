#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "HasPtr.h"
using std::istringstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::sort;
int main() {
	vector<HasPtr> vec;
	string text = "The Academy Awards show is so determined to stick to a brisk three hours this year, they've instituted a 90-second rule. That's how long winners have to hear their name, kiss their friends, walk to the stage, and give their speech. At the Oscars nomination lunch this week, the Academy showed a video of Steven Soderbergh's past acceptance as a model of efficiency. He got on stage so fast that he had time to say something about his art, and thank a dozen people we've never heard of before.";
	istringstream iss(text);
	string word;
	while (iss >> word) {
		vec.push_back(HasPtr(word));
	}
	sort(vec.begin(), vec.end());
	return 0;
}