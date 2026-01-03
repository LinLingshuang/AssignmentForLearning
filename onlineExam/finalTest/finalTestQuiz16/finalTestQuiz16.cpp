/*16. 字符位置统计
【问题描述】
编写一个程序，输入一个字符串str(长度不超过30)和一个字符ch，通过指针查找、统计字符串str中字符ch出现的位置(区分大小写)。
【输入形式】
输入一个字符串str，以及一个字符ch
【输出形式】
若ch在str中存在，输出位置，位置之间以空格分隔
若ch在str中不存在，输出NULL
输出后面无换行符
【样例输入1】
Shanghaijiaotongdaxue h
【样例输出1】
1 5
【样例输入2】
Helloworld @
【样例输出2】
NULL*/

#include <iostream>
#include<string>

using namespace std;



int main()
{
	string str;
	char del;

	cin >> str >> del;
	int place = 0;
	bool haveFind = false;
	for (char c : str) {
		if (c == del) {
			cout << place << ' ';
			haveFind = true;
		}

		place++;
	}
	if (!haveFind) {
		cout << "NULL";
	}


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
