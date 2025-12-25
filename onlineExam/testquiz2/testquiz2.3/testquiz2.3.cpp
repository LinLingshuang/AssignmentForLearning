/*【问题描述】
从键盘输入两个字符串，用字符数组保存字符串，不要使用系统函数。
【输入形式】
输入第一个字符串，换行后输入第二个字符串
【输出形式】
把连接好后的字符串输出到屏幕上
【样例输入】
hello
world
【样例输出】
helloworld
【样例说明】
【评分标准】*/
#include<iostream>
using namespace std;

int main() {
	char* a = new char[1000];
	char* b = new char[1000];

	cin >> a;
	cin >> b;

	

	int n1 = 0;
	int n2 = 0;

	while (a[n1] != '\0') {
		n1++;
	}
	
	while (b[n2] != '\0') {
		n2++;
	}
	
	char* result = new char[2000];
	for (int i = 0; i < n1 + n2; i++) {
		if (i < n1) {
			result[i] = a[i];

		}
		else {
			result[i] = b[i - n1];
		}

	}

	result[n1 + n2] = '\0';
	cout << result;

	delete[] a;
	delete[] b;
	delete[] result;
}
