/*题目描述
若一个数（首位不为零）从左向右读与从右向左读都一样，我们就将其称之为回文数。

例如：给定一个十进制数 56，将 56 加 65（即把 56 从右向左读），得到 121 是一个回文数。

又如：对于十进制数 87：

STEP1：87+78=165
STEP2：165+561=726
STEP3：726+627=1353
STEP4：1353+3531=4884

在这里的一步是指进行了一次 N 进制的加法，上例最少用了 4 步得到回文数 4884。

写一个程序，给定一个 N（2≤N≤10 或 N=16）进制数 M（100 位之内），求最少经过几步可以得到回文数。
如果在 30 步以内（包含 30 步）不可能得到回文数，则输出 Impossible!。

输入格式
两行，分别是 N，M。

输出格式
如果能在 30 步以内得到回文数，输出格式形如 STEP=ans，其中 ans 为最少得到回文数的步数。

否则输出 Impossible!。

输入输出样例
输入 #1复制

10
87
输出 #1复制

STEP=4*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

string Trans(string input) {
	string result;
	for (int i = 0; i < input.length(); i++) {
		result[i] = input[input.length() - 1 - i];
	}
	return result;
}


int main() {
	int level = 10;
	string num;
	cin >> level >> num;
	int strlong = num.length();
	string levelup;
	string sum;
	int step = 0;
	while (step!=30) {
		sum[strlong] = num[strlong];
		for (int i = 0; i < strlong; i++) {



		}
		step++;
	}


}