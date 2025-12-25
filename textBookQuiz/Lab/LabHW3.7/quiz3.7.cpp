/*完成函数，参数为两个unsigned short int型数，返回值为第一个参数除以第
二个参数的结果，数据类型为short int；如果第二个参数为0，则返回值为-1。在
主程序中实现输入输出。注意观察函数的参数传入传出、返回值*/

#include<iostream>
using namespace std;

short int fun(unsigned short int a, unsigned short int b) {
	if (b == 0)return -1;
	else return a / b;
}

int main() {
	unsigned short int x, y;
	cin >> x >> y;
	cout << fun(x, y);
}