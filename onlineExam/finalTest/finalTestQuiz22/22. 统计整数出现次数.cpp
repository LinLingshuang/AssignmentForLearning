/*22. 统计整数出现次数
【问题描述】
输入一组无序的整数，编程输出其中出现次数最多的整数及其出现次数。
【输入形式】
先从标准输入读入整数的个数（大于等于1，小于等于100），然后在下一行输入这些整数，各整数之间以一个空格分隔。
【输出形式】
在标准输出上输出出现次数最多的整数及其出现次数，两者以一个空格分隔；若出现次数最多的整数有多个，则按照整数升序分行输出。
【样例输入】
10
0 -50 0 632 5813 -50 9 -50 0 632
【样例输出】
-50 3
0 3
【样例说明】
输入了10个整数，其中出现次数最多的是-50和0，都是出现3次。*/

#include <iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
	int num;
	cin >> num;
	map<int, int>input;
	vector<int>tempinput;
	int temp;
	for (int i = 0; i < num; i++) {
		cin >> temp;
		input[temp]=0;
		tempinput.push_back(temp);
	}
	for (auto ptr : tempinput) {
		input[ptr]++;
	}
	int max = 0;
	for (auto iter : input) {
		if (iter.second >= max) {
			max = iter.second;
		}
	}
	for (auto iter : input) {
		if (iter.second == max) {
			cout << iter.first << ' ' << iter.second<<endl;
		}
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
