// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cstdio>
#include <string>
//#include <algorithm>
#include <vector>as
using namespace std;
const int N = 10001;
char s[N];
int len, answhere;
string anst, anen;
vector <int> annu;
int main()
{
	scanf("%d %s", &len, s);
	//	printf("%d %s",len,st);
	anst += s[0];
	anen += s[len - 1];
	annu.push_back(len);
	for (int i = 1; i < len; i++)
	{
		char st = s[i], en = s[(len + i - 1) % len];
		//		printf("%c %c\n",st,en);
		int j = 0;
		while (anst[j] <= st && j < anst.size()) j++;
		if (j == 0)
		{
			anst.insert(anst.begin(), 1, st);
			anen.insert(anen.begin(), 1, en);
			annu.insert(annu.begin(), ((len + i - 1) % len) + 1);
		}
		else
		{
			anst.insert(j, 1, st);
			anen.insert(j, 1, en);
			annu.insert(annu.begin() + j, ((len + i - 1) % len) + 1);
		}
	}
	for (int i = 0; i < anen.size(); i++)
	{
		printf("%c", anen[i]);
		if (annu[i] == 1) answhere = i + 1;
	}
	printf("\n%d", answhere);
	return 0;
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
