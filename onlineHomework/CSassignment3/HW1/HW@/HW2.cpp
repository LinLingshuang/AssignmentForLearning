/*2. 求两个整数的最大公约数和最小公倍数
【问题描述】

求两个整数的最大公约数和最小公倍数。要求两个整数以及结果在主函数中输入输出。

【输入形式】

输入两个正整数a和b，两个数之间用空格分隔。

【输出形式】

输出这两个整数的最大公约数和最小公倍数，两个数之间用空格分隔。

【样例输入】

12 18

【样例输出】

6 36

【样例说明】

表示求12和18的最大公约数和最小公倍数，最大公约数为6，最小公倍数为36*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int num1,num2;
	cin >> num1 >> num2;
	
	int max = num1;
	if (num2 > max)max = num2;
	for (int i = max; i > -1; i--) {
		int last1 = num1 % i;
		int last2 = num2 % i;
		if (last1 == 0 && last2 == 0) {
			cout << i;
			break;
		}
	}
	
	int debei1 = num1;
	int debei2 = num2;

	while (debei1 != debei2) {
		if (debei1 > debei2) {
			debei2 += num2;
		}
		else {
			debei1 += num1;
		}
	}
	cout << " " << debei1;
	return 0;
}