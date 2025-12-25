/*编写一函数expand(s1,s2)，用以将字符串s1中的缩记符号在字符串s2中扩展为等价的完整字符，
例如将a-d扩展为abcd。该函数可以处理大小写字母和数字，并可以处理a-b-c、a-z0-9与-a-z等类似的情况。
在main函数中测试该函数：从键盘输入包含缩记符号的字符串，然后调用该函数进行扩展，输出扩展结果。

注意：

待扩展字符串中有可能包含空格，例如：a-d x-z应扩展成：abcd xyz。所以读入待扩展字符串时，应能够读入包含空格的字符串。

只要缩记符号-之后的字符比之前的字符的ASCII码值大，就要将它们之间的所有字符扩展出来，例如：Z-a之间的字符也要扩展出来；

特殊情况：a-b-c将被扩展为：abc。a-a将被扩展为：a-a。

   【输入形式】
从键盘输入包含扩展符的字符串
【输出形式】
输出扩展后的字符串
【输入样例】

a-c-u-B
【输出样例】

abcdefghijklmnopqrstu-B
【样例说明】
扩展输入a-c-u为：abcdefghijklmnopqrstu，而B比u值小，所以无法扩展，直接输出。*/
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	vector<int>b(n);
	int max = 0;
	int resultnum=0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int sum = 1;
		for (int j = 0; j <= i; j++) {
			if (a[j] == a[i]) {
				sum++;
			}
		}
		if (sum > max) {
			resultnum = 0;
			max = sum;
			b[resultnum] = a[i];

		}
		else if (sum == max) {
			resultnum++;
			b[resultnum] = a[i];
		}
	}
	for (int i = 0; i <= resultnum; i++) {
		for (int j = 0; j < resultnum - 1; j++) {
			if (b[j] < b[j + 1]) {
				int temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i <= resultnum; i++) {
		cout << b[i] << " " << max-1 << endl;
	}
	
}