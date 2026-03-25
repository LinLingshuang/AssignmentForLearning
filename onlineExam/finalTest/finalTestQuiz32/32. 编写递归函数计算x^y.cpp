/*32. 编写递归函数计算x^y
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


#include<iostream>
using namespace std;

int getpower(int x, int y) {
	int result = 1;
	if (y < 0)
		return 0;
	else {
		for (int i = 0; i < y; i++) {
			result *= x;

		}
		return result;
	}
}

double getpower(double x, int y) {
	double result = 1;
	if (y < 0) {
		for (int i = 0; i > y; i--) {
			result /= x;

		}
		return result;
	}
	else {
		for (int i = 0; i < y; i++) {
			result *= x;

		}
		return result;
	}

}

int main() {
	int a;
	double b;
	int m;
	cin >> a >> b >> m;
	cout << getpower(a, m) << endl;
	cout << getpower(b, m);

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
