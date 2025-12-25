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
	char a[100];
	char b[100];
	char c[200];
	cin >> a >> b;
	int i = 0,j = 0;
	while (a[i] != '\0') {
		c[i] = a[i];
		i++;
	}
	while (b[j] != '\0') {
		c[i + j] = b[j];
		j++;

	}
	c[i + j] = '\0';
	cout << c;
}