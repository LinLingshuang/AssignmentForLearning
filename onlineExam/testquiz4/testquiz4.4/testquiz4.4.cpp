/*1. 二维数组转置并求主对角线之和
【问题描述】

 请补充完整下面空白的程序语句。

函数transposeAndSumDiagonal( )接收一个二维整型数组matrix[][]，将其行列转置后，并计算主对角线元素之和。

函数validateSize（）用于验证数组大小是否合理。

主函数main（）调用validateSize（）检测组数大小是否合理，调用函数transposeAndSumDiagonal（），输出转置后的数据元素和对角线之和的结果。

【输入形式】

无

【输出形式】

按行输出的转置后数组元素，和对角线之和的结果

【样例输入】

 程序中的矩阵二维数组为：matrix[3][3] = { {1, 2, 3},   {4, 5, 6},   {7, 8, 9}  };

【样例输出】

Transposed Matrix:

1 4 7

2 5 8

3 6 9

Diagonal Sum: 15

【样例说明】

按行输出了转置后的二维数组和对角线和。*/
#include <iostream>
using namespace std;

int transposeAndSumDiagonal(int matrix[][3], int result[][3], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {

            // 空1
            if (i == j)

                // 空2
        }

    // 空3
}

bool validateSize(int size) {
    if (size <= 0 || size > 10) {
        cout << "Invalid matrix size" << endl;

        // 空4
    }

    // 空5
}

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int transposed[3][3];
    if (!validateSize(3)) {
        return 1;
    }
    else {
        int diagSum = transposeAndSumDiagonal(matrix, transposed, 3);
        cout << "Transposed Matrix:" << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j)
                cout << transposed[i][j] << " ";
            cout << endl;
        }

        cout << "Diagonal Sum: " << diagSum << endl;  // 应输出 15
    }
    return 0;
}






