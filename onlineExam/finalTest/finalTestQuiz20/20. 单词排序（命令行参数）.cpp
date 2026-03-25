/*20. 单词排序（命令行参数）
【问题描述】
编写一个程序，从一个文件中读入单词（即：以空格或回车换行分隔的字符串），并对单词进行排序，删除重复出现的单词，然后将结果输出到另一个文件中。
【输入形式】
源文件名和目标文件名在执行时作为程序命令行参数输入，例如若程序名为sort，
源文件名和目标文件名分别为sort.in和sort.out，则命令行为：sort  sort.in  sort.out。
程序将从当前目录下sort.in文件中读入单词。
【输出形式】
对单词进行排序，删除重复出现的单词，然后将结果输出到文件sort.out中。
【输入样例】
假如sort.in文件内容如下：
rrr  sss  aaa  bbb  ccc   ddf  aaa  dd
【输出样例】
sort.out文件内容为：
aaa bbb ccc dd  ddf  rrr sss
【样例说明】
读入文件sort.in，做适当的排序，并删除重复出现的单词，输出到文件sort.out*/

#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<set>

using namespace std;

int main(int argc, char* argv[])
{

	string name, inputname, outputname;
	inputname = argv[1];
	outputname = argv[2];
	
	ifstream in;
	in.open(inputname);
	set<string>input;
	string templine;
	while (getline(in, templine)) {
		string tempStr;
		for (char c : templine) {
			if (c != ' ') {
				tempStr.push_back(c);
			}
			else {
				input.insert(tempStr);
				tempStr.clear();
			}
		}
		if (tempStr != "") {
			input.insert(tempStr);
			tempStr.clear();
		}
		tempStr.clear();
	}
	in.close();

	ofstream out;
	out.open(outputname);
	
	for (auto iter : input) {
		if (iter != "") {
			out << iter << ' ';
		}
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
