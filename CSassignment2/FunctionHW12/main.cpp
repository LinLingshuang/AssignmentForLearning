#include <iostream>
#include <vector>
using namespace std;

// 检查是否有5连子，并记录起始位置
bool checkWinning(const vector<vector<int>>& board, int& winningColor, int& startRow, int& startCol) {
    // 四个方向：水平、垂直、右下对角线、左下对角线
    int directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
    
    // 按从上到下、从左到右的顺序检查，确保找到的是第一个出现的5连子
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            int color = board[i][j];
            if (color == 0) continue; // 跳过空格子
            
            for (int d = 0; d < 4; d++) {
                int dr = directions[d][0];
                int dc = directions[d][1];
                bool hasFive = true;
                
                // 检查当前位置开始的连续5个棋子
                for (int k = 0; k < 5; k++) {
                    int r = i + k * dr;
                    int c = j + k * dc;
                    // 检查边界和颜色是否一致
                    if (r >= 19 || c >= 19 || c < 0 || board[r][c] != color) {
                        hasFive = false;
                        break;
                    }
                }
                
                if (hasFive) {
                    winningColor = color;
                    startRow = i + 1; // 转换为从1开始计数
                    startCol = j + 1;
                    return true;
                }
            }
        }
    }
    return false;
}

// 计算最长连子数
int findMaxLength(const vector<vector<int>>& board) {
    int directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
    int maxLength = 0;
    
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            int color = board[i][j];
            if (color == 0) continue;
            
            for (int d = 0; d < 4; d++) {
                int dr = directions[d][0];
                int dc = directions[d][1];
                int length = 1;
                int r = i + dr;
                int c = j + dc;
                
                // 向一个方向延伸
                while (r >= 0 && r < 19 && c >= 0 && c < 19 && board[r][c] == color) {
                    length++;
                    r += dr;
                    c += dc;
                }
                
                maxLength = max(maxLength, length);
            }
        }
    }
    return maxLength;
}

int main() {
    vector<vector<int>> board(19, vector<int>(19));
    
    // 读取19x19的棋盘
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> board[i][j];
        }
    }
    
    int winningColor = 0;
    int startRow = 0, startCol = 0;
    
    // 检查是否有获胜者
    if (checkWinning(board, winningColor, startRow, startCol)) {
        cout << winningColor << ":" << startRow << "," << startCol << endl;
    } else {
        // 计算最长连子数
        int maxLength = findMaxLength(board);
        cout << maxLength << endl;
    }
    
    return 0;
}