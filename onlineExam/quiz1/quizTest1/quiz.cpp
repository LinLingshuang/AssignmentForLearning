//接雨水问题

//【问题描述】

//假设在二次元平面世界（只有高度和宽度）里，给定12个非负整数，每个整数代表一个宽度为 1 的柱子的高度，这些柱子按照给定的顺序排列，形成一个高度图。计算这个高度图在降雨后能够接住多少雨水（雨水只能滞留在柱子之间的空间）。

//例如，12个非负整数{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}，对应12根柱子（黑色块），如下图所示，能接住的最多的雨水（蓝色块）量为6.

//blob.png

//【输入形式】输入12个非负整数，之间以空格间隔。

//【输出形式】能接住的最大雨水数量值。

//【样例输入】0 1 0 2 1 0 1 3 2 1 2 1

//【样例输出】6

//【样例说明】一共5组测试用例。

//【评分标准】每组测试用例正确即给20 % 的分数。

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	vector<int>input(14);
	input[0] = 0;
	input[13] = 0;
	bool firstblock = false;
	int sum = 0;
	int proccess = 0;
	int max = input[0];
	for (int i = 1; i < 13; i++) {
		cin >> input[i];
	}
	for (int i = 0; i < 14; i++) {
		if (input[i] >= max)max = input[i];
	}
	while (max > 0) {
		for (int i = 0; i < 14; i++) {
			if (input[i] > 0 && !firstblock) {
				firstblock = true;
			}
			if (firstblock && input[i] <= 0) {
				proccess += 1;
			}
			if (firstblock && input[i] > 0) {
				sum += proccess;
				proccess = 0;
			}
			if (i == 13) {
				proccess = 0;
			}
		}
		firstblock = false;
		for (int i = 0; i < 14; i++) {
			input[i] -= 1;
		}
		max--;
	}
	cout << sum;
	return 0;
}
