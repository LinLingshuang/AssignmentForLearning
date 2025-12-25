/*4. Fiboonacci斐波那契数列
【问题描述】

用递归的方法编写函数求Fiboonacci级数，计算并输出Fiboonacci斐波那契数列的前N项。

【输入形式】

输入一个正整数N，表示需要计算Fiboonacci斐波那契数列的前N项。

【输出形式】

输出Fiboonacci斐波那契数列的前N项，两个数之间用一个空格隔开。

【样例输入】

10

【样例输出】

1 1 2 3 5 8 13 21 34 55

【样例说明】

输入计算Fiboonacci斐波那契数列的前10项*/


#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int Fiboonacci(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	else {
		return Fiboonacci(n - 1) + Fiboonacci(n - 2);
	}


}

int main() {
	int n = 0;
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cout << Fiboonacci(i)<<" ";
	}
	

}