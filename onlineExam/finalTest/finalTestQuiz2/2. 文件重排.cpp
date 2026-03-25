/*2. 文件重排
【问题描述】

近几年有人提出了这样一种算法，它虽然只是单纯地对文件进行重排，本身并不压缩文件。
该算法如下：对一个长度为n的字符串S，首先根据它构造n个字符串，其中第i个字符串由将S的前i-1个字符置于末尾得到。然后把这n个字符串按照首字符从小到大排序，如果两个字符串的首字符相等，则按照它们在S中的位置从小到大排序。排序后的字符串的尾字符可以组成一个新的字符串S'，它的长度也是n，并且包含了S中的每一个字符。最后输出S'以及S的首字符在S'中的位置p。
【输入文件】

输入文件filezip.in包含两行，第1行是一个整数n（1 <=n<=10000），代表S的长度，第2行是字符串S。
【输出文件】
输出文件filezip.out包含两行，第1行是S'，第2行是整数p。
【输入样例】

7
example
【输出样例】

xelpame          
7*/

#include <iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;


int main()
{
	ifstream in;
	in.open("filezip.in");
	int a;
	int resultnum = 2;

	string b;
	in >> a >> b;
	cin >> a >> b;

	in.close();

	vector<string>temp(a);

	for (int i = 0; i < a; i++) {
		int c = 0;
		for (int j = 0; j < a; j++) {
			if (a - j > i) {
				temp[i].push_back(b[j + i]);
			}
			else {
				temp[i].push_back(b[c]);
				c++;
			}
		}
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a - 1; j++) {
			if (temp[j][0] > temp[j + 1][0]) {
				string temp2 = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = temp2;

				if (j + 1 == resultnum) {
					resultnum = j + 2;
				}
				else if (j + 2 == resultnum) {
					resultnum = j + 1;
				}
			}
		}
	}

	string result;
	for (int i = 0; i < a; i++) {
		result.push_back(temp[i][a - 1]);
	}

	ofstream out;
	out.open("filezip.out");

	cout << result;
	cout << endl;
	cout << resultnum;

	out << result;
	out << endl;
	out << resultnum;


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
