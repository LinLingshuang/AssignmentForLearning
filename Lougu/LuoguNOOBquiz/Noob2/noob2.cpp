/*题目描述
已知：Sn​=1+ 1/2+1/3+...+1/n。显然对于任意一个整数 k，当 n 足够大的时候，Sn​>k。
现给出一个整数 k，要求计算出一个最小的 n，使得 Sn​>k。

输入格式
一个正整数 k。
输出格式
一个正整数 n。
输入输出样例
输入 #1复制

1
输出 #1复制

2
说明/提示
【数据范围】

对于 100% 的数据，1≤k≤15。*/

#include<iostream>
using namespace std;

int main() {
	int k; 
	double n=0.0;
	cin >> k;
	double sum = 0;
	while (sum <= k) {
		n++;
		sum += 1 / n;
	}
	cout << n;
}





/*double levelsum(int x) {
	double result=0;
	for (double i = x; i > 0; i--) {
		result += 1 / i;
	}
	return result;
}
*/
/*double levelsum(double x) {
	if (x == 0)return 0.0;
	else {
		return 1 / x + levelsum(x - 1);
	}
}

int main() {
	int k;
	double n=1;
	cin >> k;
	while (levelsum(n) <= k) {
		n++;
	}
	cout << n;
}
*/


