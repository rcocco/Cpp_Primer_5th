#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
struct Sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
int main() {
	Sales_data data1, data2;
	cout << "Please input sales data that have same ISBN: "
		<< endl;
	double price1,price2;
	cin >> data1.bookNo >> data1.units_sold >> price1
		>> data2.bookNo >> data2.units_sold >> price2;
	data1.revenue = data1.units_sold * price1;
	data2.revenue = data2.units_sold * price2;
	if (data1.bookNo == data2.bookNo) {
		unsigned totalCnt = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;
		cout << "ISBN, Volume, Revenue, Average Price: "
			<< data1.bookNo << " " << totalCnt << " "
			<< totalRevenue << " ";
		if (totalCnt != 0) {
			cout << totalRevenue / totalCnt << endl;
		}
		else {
			cout << "(no sales)" << endl;
		}
		return 0;
	}
	else {
		cerr << "Data must refer to the same ISBN"
			<< endl;
		return -1;
	}
}