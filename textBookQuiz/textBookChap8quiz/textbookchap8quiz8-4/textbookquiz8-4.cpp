/*请编写一个计数器Counter类，对其重载运算符“+”*/

#include<iostream>
using namespace std;

class Counter {
public:
	Counter(double v = 0) : value(v) {}
	Counter operator+(Counter& other)
	{
		return value + other.value;
	}
	double getvalue() { return value; }
private:
	double value;

};


int main() {
	Counter c1(12.3), c2(56.3);
	cout << (c1 + c2).getvalue() << endl;

}