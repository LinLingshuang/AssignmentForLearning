/*3-9、编写函数判别一个整数是否是质数？要求在主函数中输入输出。*/

#include<iostream>
#include<cmath>
using namespace std;

void fun(int n) {
	int a, b;
	b = sqrt(n);
	bool output = false;
	for (a = 2; a <= b; a++) {
		if (n % a == 0) {
			cout << "不是质数";
			output = true;
			break;
		}
	}
	if (!output) {
		cout << "是质数";
	}
}

int main() {
	int num;
	cin >> num;
	fun(num);
}