/*3-15、编写递归函数getPower计算xy
,在同一个程序中针对整型和实型实现两个重
载函数：
int getPower(int x, int y); //整型版本，，当y<0时，返回0
double getPower(double x, int y); //实型版本
在主程序中实现输入输出，分别输入一个整数a和一个实数b作为底数，再输入一
个整数m作为指数，输出am和bm。
另外请读者思考，如果在调用getPower函数计算am时希望得到一个实型结果（实型结果 表
示范围更大，而且可以准确表示m<0时的结果），该如何调用？注意观察递归调用的*/


#include<iostream>
using namespace std;

int getPower(int x, int y) {
	int sum = 1;
	if (y < 0)return 0;
	else {
		for (int i = 0; i < y; i++) {
			sum *= x;
		}
		return sum;
	}
}

double getPower(double x, int y) {
	double sum = 1.0;
	if (y >= 0) {
		for (int i = 0; i < y; i++) {
			sum *= x;
		}
		return sum;
	}
	else {
		for (int i = 0; i > y; i--) {
			sum /= x;
		}
		return sum;
	}
}

int main() {
	int a,m;
	double b;
	cin >> a >> b >> m;
	cout << getPower(a, m) <<' '<< getPower(b, m);

}