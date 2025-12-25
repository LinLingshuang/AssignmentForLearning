#include <iostream>
#include <vector>
using namespace std;

// 检查横向（向右）是否有连续4个同色棋子，且两端至少一端为空
bool check_horizontal(int a[19][19], int i, int j) {
    // j>15时，j+3会超出19列（0-18），无法形成4连
    if (j > 15) return false;
    int color = a[i][j];
    if (color == 0) return false; // 空位置无需检查
    // 检查j到j+3是否都是同色
    if (a[i][j + 1] != color || a[i][j + 2] != color || a[i][j + 3] != color) {
        return false;
    }
    // 检查左端（j-1）或右端（j+4）是否为空
    bool left_empty = (j - 1 >= 0) && (a[i][j - 1] == 0);
    bool right_empty = (j + 4 < 19) && (a[i][j + 4] == 0);
    return left_empty || right_empty;
}

// 检查右下斜向（\）是否有连续4个同色棋子，且两端至少一端为空
bool check_diag_right_down(int a[19][19], int i, int j) {
    // i>15或j>15时，i+3/j+3超出边界
    if (i > 15 || j > 15) return false;
    int color = a[i][j];
    if (color == 0) return false;
    // 检查(i,j)、(i+1,j+1)、(i+2,j+2)、(i+3,j+3)是否同色
    if (a[i + 1][j + 1] != color || a[i + 2][j + 2] != color || a[i + 3][j + 3] != color) {
        return false;
    }
    // 检查左上（i-1,j-1）或右下（i+4,j+4）是否为空
    bool up_left_empty = (i - 1 >= 0 && j - 1 >= 0) && (a[i - 1][j - 1] == 0);
    bool down_right_empty = (i + 4 < 19 && j + 4 < 19) && (a[i + 4][j + 4] == 0);
    return up_left_empty || down_right_empty;
}

// 检查纵向（向下）是否有连续4个同色棋子，且两端至少一端为空
bool check_vertical(int a[19][19], int i, int j) {
    // i>15时，i+3超出19行（0-18）
    if (i > 15) return false;
    int color = a[i][j];
    if (color == 0) return false;
    // 检查i到i+3是否都是同色
    if (a[i + 1][j] != color || a[i + 2][j] != color || a[i + 3][j] != color) {
        return false;
    }
    // 检查上端（i-1）或下端（i+4）是否为空
    bool up_empty = (i - 1 >= 0) && (a[i - 1][j] == 0);
    bool down_empty = (i + 4 < 19) && (a[i + 4][j] == 0);
    return up_empty || down_empty;
}

// 检查左下斜向（/）是否有连续4个同色棋子，且两端至少一端为空
bool check_diag_left_down(int a[19][19], int i, int j) {
    // i>15（i+3超行）或j<3（j-3超列），无法形成4连
    if (i > 15 || j < 3) return false;
    int color = a[i][j];
    if (color == 0) return false;
    // 修正原代码的笔误：i+1,j-2 → i+2,j-2
    if (a[i + 1][j - 1] != color || a[i + 2][j - 2] != color || a[i + 3][j - 3] != color) {
        return false;
    }
    // 检查右上（i-1,j+1）或左下（i+4,j-4）是否为空
    bool up_right_empty = (i - 1 >= 0 && j + 1 < 19) && (a[i - 1][j + 1] == 0);
    bool down_left_empty = (i + 4 < 19 && j - 4 >= 0) && (a[i + 4][j - 4] == 0);
    return up_right_empty || down_left_empty;
}

int main() {
    int matrix[19][19];
    // 读取19×19棋盘
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> matrix[i][j];
        }
    }

    // 遍历每个位置，检查是否满足获胜条件
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (matrix[i][j] == 1) { // 白棋
                if (check_horizontal(matrix, i, j) ||
                    check_diag_right_down(matrix, i, j) ||
                    check_vertical(matrix, i, j) ||
                    check_diag_left_down(matrix, i, j)) {
                    // 行列从1开始计数
                    cout << "1:" << i + 1 << ',' << j + 1 << endl;
                    return 0; // 找到结果后直接退出，避免多余遍历
                }
            }
            else if (matrix[i][j] == 2) { // 黑棋
                if (check_horizontal(matrix, i, j) ||
                    check_diag_right_down(matrix, i, j) ||
                    check_vertical(matrix, i, j) ||
                    check_diag_left_down(matrix, i, j)) {
                    cout << "2:" << i + 1 << ',' << j + 1 << endl;
                    return 0;
                }
            }
        }
    }

    // 无满足条件的情况
    cout << "No" << endl;
    return 0;
}