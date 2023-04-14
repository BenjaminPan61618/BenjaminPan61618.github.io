#include<iostream>
using namespace std;
class Salesman
{
	private:
	int num;
    int quantity;
    double price;
    double total;	
	static double sum;
	static int n;
	public:
	static double discount;
	Salesman(int n, int q, double p) : num(n), quantity(q), price(p) {
        if (quantity >= 10) {
            total = quantity * price * discount * 0.98;
        } else {
            total = quantity * price * discount;
        }
        sum += total;
        Salesman::n += quantity;
    }
    static double average() {
        return sum / n;
    }
    static void display() {
        cout << "总销售金额为："<< endl << sum << endl;
        cout << "每件商品的平均售价为："<< endl <<  average() <<  endl;
	}
};
    double Salesman::sum = 0;
    double Salesman::discount = 0;
	int Salesman::n = 0;
	
int main(){
    double discount;

    cout << "请输入当天的折扣：";
    cin >> discount;
    Salesman::discount = discount;
    Salesman s1(101, 5, 23.5);
    Salesman s2(102, 12, 24.56);
    Salesman s3(103, 100, 21.5);
    Salesman::display();

	return 0;
}
