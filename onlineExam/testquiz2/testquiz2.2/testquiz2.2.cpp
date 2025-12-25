/*【问题描述】
给定一个数组，输入一个整数N，计算该数组中最小的N个数的和。
【输入形式】
第一行两个整数M和N，空格隔开，M代表数组中元素的个数，N代表需要计算的元素个数。
【输出形式】
一个整数
【样例输入】
10 2
1 2 3 5 0 5 6 7 8 8
【样例输出】
1
【样例说明】
最小的两个数是1和0,和是1
【评分标准】*/

#include<iostream>
#include<vector>



using namespace std;

int main() {
	int m, n;
	cin >> m >> n;

	vector<int>a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];



	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;


			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}

	cout << sum;
}

