/*字符串删除与排序
【问题描述】
输入若干个字符串(每个字符串的长度不超过30个字符，字符串总数不超过30)，
和一个英文字符。 要求： - 删除每个字符串中的字符(区分大小写)，
得到新的字符串 - 将新的字符串按照字典逆序排序后输出
【输入形式】
第一行输入英文字符
每一行输入一个字符串
最后一行单独输入特殊字符@做为结束标志
【输出形式】
删除ch的新字符串按字典逆序输出
每行输出一个字符串
【样例输入】
e
shangejiao
fudean
teongji
shangcai
@
【样例输出】
tongji
shangjiao
shangcai
fudan*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	char deleteword;
	int strnum = 0;
	vector<string>input(100);
	cin >> deleteword;
	do {
		cin >> input[strnum];
		strnum++;
	} while (input[strnum-1] != "@");

	vector<string>output(100);
	for (int i = 0; i < strnum - 1; i++) {
		int num = 0;
		output[i] = new char[100];
		for (char c : input[i]) {
			if (c != deleteword) {
				output[i][num] = c;
				num++;


			}
		}
		output[i][num] = '\0';
	}
	for (int i = 0; i < strnum-1; i++) {
		int n = 0;
		for (char c : output[i]) {
			if (c != '\0') {
				cout << output[i][n];
				n++;
			}
		}
		cout << endl;
	}
	
}
