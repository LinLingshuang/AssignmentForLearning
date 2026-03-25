/*17. 扩展字符
【问题描述】
编写一函数expand(s1,s2)，用以将字符串s1中的缩记符号在字符串s2中扩展为等价的完整字符，例如将a-d扩展为abcd。该函数可以处理大小写字母和数字，并可以处理a-b-c、a-z0-9与-a-z等类似的情况。在main函数中测试该函数：从键盘输入包含缩记符号的字符串，然后调用该函数进行扩展，输出扩展结果。

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
#include<string>
#include<vector>
using namespace std;

void expand(string& s1, string& s2) {
	int first = 0, end = 0;
	bool isexpanding = false;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == '-') {
			isexpanding = true;
		}
		if (!isexpanding) {
			if (first != i)
				s2.push_back(s1[first]);
			first = i;
		}
		if (isexpanding && s1[i] != '-') {
			end = i;
			if (s1[first] < s1[end]) {
				for (int j = 0; j < s1[end] - s1[first]; j++) {
					s2.push_back(s1[first] + j);
				}
				first = end;
				isexpanding = false;
			}
			else if (s1[first] >= s1[end]) {
				for (int j = first; j < end; j++) {
					s2.push_back(s1[j]);
				}
				first = end;
				isexpanding = false;
			}
		}
		if (i == s1.length() - 1) {
			s2.push_back(s1[i]);
		}

	}


}

int main() {
	string oldstr, newstr;
	getline(cin, oldstr);
	expand(oldstr, newstr);
	cout << newstr;
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
