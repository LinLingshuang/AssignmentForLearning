/*30. 字符串处理-删除重复字符
【问题描述】

编程实现DeleteSame函数的功能。假设有如下的函数调用：num=DeleteSame(oldstr, newstr)；其中，oldstr是字符串，该函数删除字符串oldstr中重复出现的字符，只保留首次出现的各个字符，将结果保存至字符串newstr，并且返回被删除的字符个数。

说明：

1.函数原型：int DeleteSame(char *oldstr, char *newstr)；

2.字符串最长为49个字符。



【输入形式】

输入字符串oldstr，该字符串中重复出现的字符将被删除，只保留首次出现的各个字符


【输出形式】

输出字符串newstr（只保留字符串oldstr中首次出现的各个字符），被删除的字符个数。


【样例输入】

样例输入1

The-value=of=pi=is-3.1415926535

样例输入2

helloC++



【样例输出】

样例输出1

The-valu=ofpis3.145926 9

样例输出2

heloC+ 2



【样例说明】

暂无

*/
//方法一
#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

int main() {
	string old;
	getline(cin, old);
	int len = old.length();
	string New;
	int sum = 0;
	for (int i = 0; i < len; i++) {
		if (old.find(old[i]) == i) {
			New += old[i];
		}
		else {
			sum += 1;
		}
	}
	cout << New << " " << sum;
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
