/*问题描述】
 使用动态内存分配生成动态数组，从键盘输入一个n*n矩阵，每次输入一行，使用指针实现函数的功能。
【输入形式】
 先输入n的值，再输入矩阵的第一行、第二行......
【输出形式】
 分别显示转置前和转置后的矩阵。
【样例输入
 3
 1 2 3
 4 5 6
 7 8 9
【样例输出】
 1 2 3
 4 5 6
 7 8 9
 1 4 7
 2 5 8
 3 6 9
【样例说明】
元素之间用空格隔开
【评分标准】*/

#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int arr1[100][100] = { 0 };
	int arr2[100][100] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr1[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout<< arr1[i][j]<<' ';
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr2[i][j] = arr1[j][i];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr2[i][j]<<' ';
		}
		cout << endl;
	}

}





