/*1. 单词出现次数查找
【问题描述】
在一给定的文件中查找单词，输出单词在各行出现的次数。待查找的单词不超过10个，每个单词的字符数也不超过10。文件中每行字符数不超过100。注意：
1. 单词中除了字母、数字外有可能包含其它字符，但不包含空格符；
2. 单词大小写查找相关；
3. 不考虑单词重叠查找，例如：待查找单词为"aa"，假如文件第一行为"the word aaaaaa"，则单词"aa"在第一行出现了三次。
【输入形式】
假设要处理的文件保存在当前目录下，文件名为：in.c。
待查找的单词从控制台输入，各单词间以一个空格分隔，最后一个单词后有回车换行。
【输出形式】
将单词出现的次数输出到当前目录下的found.txt文件中，每个单词独占一行：先输出单词，后跟冒号":"，最后是出现的次数。
每行出现次数用"行号,在该行出现次数"表示，若在多行出现，则次数之间用";"分隔，最后一个出现次数后也带分号。若查找不到单词，则只输出单词和冒号。详见下述样例。 
【样例输入】
假设当前目录下in.c的内容为：
#include <stdio.h>
int main()
{
 int n,a,c1,c2,i;
 scanf("%d",&n);
 c1=c2=0;
 for ( i=0; i<n; i++ )
 {
  scanf("%d",&a);
  if ( a>=0 )
   c1++;
  else
   c2++;
 }
 printf("%d %d",&c1,&c2);
 return 0;
}
从控制台输入的单词为：
in int return double
【样例输出】
当前目录下的found.txt内容应为：
in:1,1;2,2;4,1;15,1;
int:2,1;4,1;15,1;
return:16,1;
double:
【样例说明】
文件in.c中，单词in出现了五次，在第一行出现一次，在第二行出现二次，在第四行出现一次，在第十五行出现一次。
单词int，return类似。单词double没有出现，所以只输出了double:。
【评分标准】
共有5个测试点。*/
#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
using namespace std;


int main()
{
	string originInput;
	getline(cin, originInput);

	int strNum = 0;
	string tempStr;
	vector<string>input;

	for (char c : originInput) {
		if (c == ' ') {
			input.push_back(tempStr);
			strNum++;
			tempStr.clear();
		}
		else {
			tempStr.push_back(c);
		}

	}
	input.push_back(tempStr);
	tempStr.clear();
	strNum++;


	ifstream in;
	in.open("in.c");
	int lineNum = 1;

	vector<map<int, int>>result;

	vector<map<int, string>>file;
	string tempStr1;
	while (getline(in, tempStr1)) {
		pair<int, string>tempPair;
		tempPair.first = lineNum;
		tempPair.second = tempStr1;
		map<int, string>tempMap;
		tempMap.insert(tempPair);
		file.push_back(tempMap);
		lineNum++;
	}
	in.close();

	for (auto test : input) {
		for (auto ptr : file) {

			for (auto ptr1 : ptr) {
				
				int testLength = test.length();
				int tempNum = 0;
				int findNum = 0;
				for (char c : ptr1.second) {
					if (c == test[tempNum]) {
						if (tempNum == testLength - 1) {
							findNum++;
							tempNum = 0;
							continue;
						}
						tempNum++;

					}
					else {
						tempNum = 0;
					}

				}
				pair<int, int>resultPair;
				resultPair.first = ptr1.first;
				resultPair.second = findNum;
				map<int, int>resultMap;
				resultMap.insert(resultPair);
				result.push_back(resultMap);
			}
		}
	}

	ofstream out;
	out.open("found.txt");
	int j = 0;
	for (auto test : input) {
		cout << test << ':';
		out << test << ':';
		for (int i = 0; i < lineNum - 1; i++) {
			auto iter = result[(lineNum - 1) * j + i];
			for (auto iter1 : iter) {

				if (iter1.second != 0) {
					cout << iter1.first << ',' << iter1.second << ';';
					out << iter1.first << ',' << iter1.second << ';';
				}

			}
		}
		cout << endl;
		out << endl;
		j++;
	}
	
	out.close();

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
