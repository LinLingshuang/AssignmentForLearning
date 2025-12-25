/*题目背景
NOIP 2000 提高组 T4
题目描述
设有 N×N 的方格图 (N≤9)，我们将其中的某些方格中填入正整数，而其他的方格中则放入数字 0。如下图所示（见样例）:
某人从图的左上角的 A 点出发，可以向下行走，也可以向右走，直到到达右下角的 B 点。在走过的路上，他可以取走方格中的数（取走后的方格中将变为数字 0）。
此人从 A 点到 B 点共走两次，试找出 2 条这样的路径，使得取得的数之和为最大。
输入格式
输入的第一行为一个整数 N（表示 N×N 的方格图），接下来的每行有三个整数，前两个表示位置，第三个数为该位置上所放的数。一行单独的 0 表示输入结束。
输出格式
只需输出一个整数，表示 2 条路径上取得的最大的和。
输入输出样例
输入 #1复制
8
2 3 13
2 6  6
3 5  7
4 4 14
5 2 21
5 6  4
6 3 15
7 2 14
0 0  0
输出 #1复制

67
说明/提示
数据范围：1≤N≤9。*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
	int n;
	cin >> n;
	

	int x;
	int y;
	int num;
	map<int, int> numx;
	map<int, int>numy;
	
	do {
		cin >> x >> y >> num;
		numx[num] = x;
		numy[num] = y;

			
	} while (!(x == 0 && y == 0 && num == 0));

	


}
	/*int n;
	cin >> n;
	int matrix[20][20] = { 0 };
	int matrixval[20][20] = { 0 };

	vector<int>val(n * n);
	vector<int>x(n * n);
	vector<int>y(n * n);
	vector<int>num(n * n);
	int cintime = 0;
	do {
		cin >> x[cintime] >> y[cintime] >> num[cintime];
		val[cintime] = num[cintime] * (n - x[cintime]) * (n - y[cintime]);
		matrix[x[cintime] - 1][y[cintime] - 1] = num[cintime];
		matrixval[x[cintime] - 1][y[cintime] - 1] = val[cintime];
		cintime++;

	} while (!(x[cintime - 1] == 0 && y[cintime - 1] == 0 && num[cintime - 1] == 0));
	int sum = 0;
	int tempa = 0, tempb = 0;
	int time = 2;
	do {
		int a = 0, b = 0;
		while (1) {
			double maxval = 0;
			for (int i = a + 0; i < n; i++) {
				for (int j = b + 0; j < n; j++) {
					if (matrixval[i][j] > maxval) {
						maxval = matrixval[i][j];
						tempa = i; tempb = j;
					}
				}
			}
			a = tempa;
			b = tempb;
			sum += matrix[a][b];
			matrix[a][b] = 0;
			matrixval[a][b] = 0;
			if (maxval == 0)break;
		}
		time--;
	} while (time > 0);
	cout << sum;*/

	/*
	int a=0,b=0,range = 0,sum=0;
	int temp1 = 0, temp2 = 0;
	int max = 0;
	int time = 2;
	while(time>0){
		a = 0; b = 0;
		temp1 = 0; temp2 = 0;
		while (max == 0) {
			for (int i = 0; i < range; i++) {
				for (int j = 0; j < range; j++) {

					if (matrix[a + i][b + j] > max) {
						max = matrix[a + i][b + j];
						temp1 = i;
						temp2 = j;

					}
					if ((a + i == n - 1) && (b + j == n - 1)) {
						goto start;
					}
				}

			}
			if (max == 0) {
				range++;
			}
			else {
				a += temp1;
				b += temp2;
				temp1 = 0; temp2 = 0;
				matrix[a][b] = 0;
				range = 0;
				sum += max;
				max = 0;
			}
		}
		start:
		time--;
	}
	cout << sum;*/
