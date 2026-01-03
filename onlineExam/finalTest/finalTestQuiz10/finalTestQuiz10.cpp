/*10. 能耗计算之矩阵
【问题描述】
你是一家智能家居能源管理公司的软件工程师。公司最近推出了一款新产品，用于监控家庭设备的能耗。
系统中有两个核心的
4
×
4
4×4 数据矩阵：
设备功率矩阵(Matrix1)：记录了家中 4 种主要电器（空调、热水器、冰箱、洗衣机）在一天中 4 个不同时段（清晨、上午、下午、晚上）的功率（千瓦）。
运行时长矩阵(Matrix2)：记录了这 4 种电器在上述 4 个时段内实际的运行时长（小时）。
为了计算出“时段 vs 电器”的综合能耗数据，你需要编写核心算法模块。这个模块需要将功率与时长进行特殊的矩阵运算（矩阵乘法），从而得出最终的能耗结果矩阵。
matrixMul函数：
void matrixMul(const double matrix1[][4], const double matrix2[][4], double result[][4])
1）matrix1、matrix2、result均表示4x4的矩阵
printMatrix函数：
void printMatrix(const double matrix[][4])
1）matrix、nRow、nCol表示矩阵及其行、列数
2）同一行的元素，输出时以单个空格为分隔
【输入形式】
1）输入矩阵1的所有数值
2）输入矩阵2的所有数值
【输出形式】
输出4x4的结果矩阵，同一行的数字以单个空格分隔
【样例输入】
1 1 1 1
2 2 2 2
3 3 3 3
4 4 4 4
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
【样例输出】
4 8 12 16
8 16 24 32
12 24 36 48
16 32 48 64
【样例说明】
输入的前4行为设备功率矩阵，后四行为运行时长矩阵
【评分标准】
2个测试用例
*/
#include<iostream>
using namespace std;

void matrixMul(const double matrix1[][4], const double matrix2[][4], double result[][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result[i][j] = 0;
			for (int k = 0; k < 4; k++) {

				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}


		}
	}

}

void printMatrix(const double matrix[][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	double matrix1[4][4];
	double matrix2[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> matrix1[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> matrix2[i][j];
		}
	}
	double result[4][4];

	matrixMul(matrix1, matrix2, result);

	printMatrix(result);
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
