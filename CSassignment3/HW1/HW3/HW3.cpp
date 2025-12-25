/*3. 编写递归函数计算x^y
【问题描述】

编写递归函数getPower计算x^y，在同一个程序中针对整型和实型实现两个重载函数：

int getPower(int x, int y); // 整型版本，当y < 0时，返回0

double getPower(double x, int y); // 实型版本，当y < 0时，返回非0实数

在主程序中实现输入输出，分别输入一个整数a和一个实数b作为底数，再输入一个整数m作为指数，输出a^m和b^m。


【输入形式】

一个整数a，作为底数。

一个实数b，作为底数。

一个整数m，作为指数。


【输出形式】

输出a的m次幂的整型结果。

输出b的m次幂的实型结果。


【样例输入】

2

1.5

3


【样例输出】

8

3.375


【样例说明】

表示计算2^3和1.5^3，整型结果为8，实型结果为3.375*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int getpower(int x,int y) {
	int result=1; 
	while (y--) {
		result *= x;
	}
	return result;
}

double getpower(double x,double y) {
	double result=1;
	while (y--) {
		result *= x;
	}
	return result;
}


int main() {
	int a;
	double b;
	int m;
	cin >> a >> b >> m;
	double t = m;
	int result1=getpower(a, m);
	double result2=getpower(b, t);
	cout << result1 << endl << result2;
	return 0;
}


