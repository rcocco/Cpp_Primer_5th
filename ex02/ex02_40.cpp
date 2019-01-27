#include <string>
struct Sales_data {
	std::string bookNo;      // 书籍编号
	unsigned units_sold = 0; // 销售量 
	double price = 0.0;      // 售价
	double revenue = 0.0;    // 销售收入
	double discount = 0.0;   // 折扣
	unsigned min_qty = 10;   // 采用折扣所需的最低购买量
};
int main() {
 	return 0;
}