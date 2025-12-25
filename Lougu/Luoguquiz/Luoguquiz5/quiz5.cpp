/*对于一个五位数  
?
 可将其拆分为三个子数：

例如，五位数 20207 可以拆分成
sub ?1=202
sub 2 =020 (=20)
sub 3=207
现在给定一个正整数 K，要求你编程求出 10000 到 30000 之间所有满足下述条件的五位数，条件是这些五位数的三个子数 ?
  都可被 K 整除。

输入格式
一个正整数 K。
输出格式
每一行为一个满足条件的五位数，要求从小到大输出。不得重复输出或遗漏。如果无解，则输出 No。
输入输出样例
输入 #1复制
15
输出 #1复制

22555
25555
28555
30000
说明/提示
0<K<1000*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main() {
	int K;
	int num = 10000;
	string strnum;
	string sub1,sub2,sub3;
	int num1, num2,num3;
	bool output = false;
	cin >> K;
	for (int i = 0; i < 20001; i++) {
		strnum = to_string(num + i);
		sub1 = strnum[0, 1, 2];
		sub2 = strnum[1, 2, 3];
		sub3 = strnum[2, 3, 4];
		num1 = (strnum[0] - '0') * 100 + (strnum[1] - '0') * 10 + (strnum[2] - '0');
		num2 = (strnum[1] - '0') * 100 + (strnum[2] - '0') * 10 + (strnum[3] - '0');
		num3 = (strnum[2] - '0') * 100 + (strnum[3] - '0') * 10 + (strnum[4] - '0');
		if (num1 % K == 0 && num2 % K == 0 && num3 % K == 0) {
			cout << strnum << endl;
			output = true;
		}
	}
	if (!output) {
		cout << "No";
	}


}