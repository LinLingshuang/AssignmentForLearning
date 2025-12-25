/*3-10、编写函数求两个整数的最大公约数和最小公倍数。要求两个整数 以及结果
在 主函数中输入输出。*/

#include <iostream>

using namespace std;

void yueshu(int m,int x,int y) {
	for (int i = m; i > -1; i--) {
		int last1 = x % i;
		int last2 = y % i;
		if (last1 == 0 && last2 == 0) {
			cout << i;
			break;
		}
	}
}

void beishu(int x,int y) {
	int debei1 = x;
	int debei2 = y;

	while (debei1 != debei2) {
		if (debei1 > debei2) {
			debei2 += y;
		}
		else {
			debei1 += x;
		}
	}
	cout << " " << debei1;
}

int main() {
	int num1, num2;
	cin >> num1 >> num2;

	int max = num1;
	if (num2 > max)max = num2;

	yueshu(max, num1, num2);
	beishu(num1, num2);
}