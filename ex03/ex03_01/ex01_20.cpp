#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
struct Sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
int main() {
	Sales_data book;
	cout << "Please input sales data: " << endl;
	double price;
	while (cin >> book.bookNo >> book.units_sold >> price) {
		book.revenue = book.units_sold * price;
		cout << "ISBN, Volume, Revenue, Average Price: "
			<< book.bookNo << " " << book.units_sold << " "
			<< book.revenue << " " << price << endl;
	}
 	return 0;
}