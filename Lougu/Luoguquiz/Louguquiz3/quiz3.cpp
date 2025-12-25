/*题目描述
火车从始发站（称为第 1 站）开出，在始发站上车的人数为 a，然后到达第 2 站，在第 2 站有人上、下车，但上、下车的人数相同，
因此在第 2 站开出时（即在到达第 3 站之前）车上的人数保持为 a 人。从第 3 站起（包括第 3 站）上、下车的人数有一定规律：
上车的人数都是前两站上车人数之和，而下车人数等于上一站上车人数，一直到终点站的前一站（第 n−1 站），都满足此规律。
现给出的条件是：共有 n 个车站，始发站上车的人数为 a，最后一站下车的人数是 m（全部下车）。试问 x 站开出时车上的人数是多少？

输入格式
输入只有一行四个整数，分别表示始发站上车人数 a，车站数 n，终点站下车人数 m 和所求的站点编号 x。

输出格式
输出一行一个整数表示答案：从 x 站开出时车上的人数。

输入输出样例
输入 #1复制

5 7 32 4
输出 #1复制

13
*/


#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	int firstup;
	int stationnum;
	int enddown;
	int xup;
	cin >> firstup >> stationnum >> enddown >> xup;
	int sum=0;
	vector<int>up(stationnum);
	vector<int>down(stationnum);
	bool current = false;
	int testnum = 0;
	while (!current) {
		down[1] = testnum;
		testnum++;
		for (int i = 0; i < stationnum; i++) {
			
			if (i == 0) {
				up[i] = firstup;
				down[i] = 0;
				sum += up[i] - down[i];
			}
			else if (i == 1) {
				up[i] = down[i];
				sum += up[i] - down[i];
			}
			else if (i < stationnum - 1) {
				up[i] = up[i - 1] + up[i - 2];
				down[i] = up[i - 1];
				sum += up[i] - down[i];
			}
			else {
				up[i] = 0;
				sum += up[i];
			}
		}
		if (sum == enddown) {
			current = true;
		}
		else {
			sum = 0;
		}
	}
	if (current) {
		sum = 0;
		down[1] = testnum-1;
		for (int i = 0; i < xup; i++) {
			if (i == 0) {
				up[i] = firstup;
				down[i] = 0;
				sum += up[i] - down[i];
			}
			else if (i == 1) {
				up[i] = down[i];
				sum += up[i] - down[i];
			}
			else if (i < stationnum - 1) {
				up[i] = up[i - 1] + up[i - 2];
				down[i] = up[i - 1];
				sum += up[i] - down[i];
			}
			else {
				up[i] = 0;
				sum += up[i];
			}
		}
		cout << sum;

	}

}