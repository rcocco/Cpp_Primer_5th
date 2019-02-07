#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
using std::ifstream;
using std::ofstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::string;
using std::cerr;
using std::endl;
int main(int argc,char *argv[]) {
	if (argc != 4) {
		cerr << "Need Input and Output Files' Name." << endl;
		return -1;
	}
	ifstream input(argv[1]);
	if (!input) {
		cerr << string("Cannot open input file: ") + argv[1] << endl;
		return -1;
	}
	ofstream output1(argv[2]);
	if (!output1) {
		cerr << string("Cannot open the first output file: ") + argv[2] << endl;
		return -1;
	}
	ofstream output2(argv[3]);
	if (!output2) {
		cerr << string("Cannot open the second output file: ") + argv[3] << endl;
		return -1;
	}
	istream_iterator<int> in(input), eof;
	ostream_iterator<int> out_odd(output1," "), out_even(output2,"\n");
	while (in != eof) {
		if (*in % 2) {
			*out_odd++ = *in++;
		}
		else {
			*out_even++ = *in++;
		}
	}
	return 0;
}