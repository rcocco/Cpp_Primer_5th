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
	// 假定ISBN号相同的数据是聚在一起的
	Sales_data total;
	cout << "Please input sales data: "
		<< endl;
	double price;
	if (cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			if (total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else {
				cout << "ISBN, Volume, Revenue, Average Price: "
					<< total.bookNo << " " << total.units_sold << " "
					<< total.revenue << " ";
				if (total.units_sold != 0) {
					cout << total.revenue / total.units_sold << endl;
				}
				else {
					cout << "(no sales)" << endl;
				}
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}
		cout << "ISBN, Volume, Revenue, Average Price: "
			<< total.bookNo << " " << total.units_sold << " "
			<< total.revenue << " ";
		if (total.units_sold != 0) {
			cout << total.revenue / total.units_sold << endl;
		}
		else {
			cout << "(no sales)" << endl;
		}
	}
	else {
		cerr << "No Data!" << endl;
		return -1;
	}
	return 0;
}