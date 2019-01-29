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
	Sales_data total, data;
	cout << "Please input sales data that have same ISBN: "
		<< endl;
	double price;
	if (cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		while (cin >> data.bookNo >> data.units_sold >> price) {
			data.revenue = data.units_sold * price;
			if (total.bookNo == data.bookNo) {
				total.units_sold += data.units_sold;
				total.revenue += data.revenue;
			}
			else {
				cerr << "Invalid data! Data must refer to the same ISBN: "
					<< total.bookNo << endl;
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
		return 0;
	}
	else {
		cerr << "No Data!" << endl;
		return -1;
	}
}