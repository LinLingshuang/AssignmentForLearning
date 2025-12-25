#include <iostream>
#include <vector>
using namespace std;

// 检查是否有一方即将获胜（连成4个子且至少一端为空）
bool checkWinning(const vector<vector<int>>& board, int row, int col, int color, int& startRow, int& startCol) {
    // 四个方向：水平、垂直、左上到右下、右上到左下
    int directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
    
    for (int d = 0; d < 4; d++) {
        int dr = directions[d][0];
        int dc = directions[d][1];
        int count = 1; // 当前位置已经有一个子
        
        // 向一个方向搜索
        int r = row + dr;
        int c = col + dc;
        while (r >= 0 && r < 19 && c >= 0 && c < 19 && board[r][c] == color) {
            count++;
            r += dr;
            c += dc;
        }
        bool hasEmptyEnd1 = (r >= 0 && r < 19 && c >= 0 && c < 19 && board[r][c] == 0);
        
        // 向相反方向搜索
        r = row - dr;
        c = col - dc;
        while (r >= 0 && r < 19 && c >= 0 && c < 19 && board[r][c] == color) {
            count++;
            r -= dr;
            c -= dc;
        }
        bool hasEmptyEnd2 = (r >= 0 && r < 19 && c >= 0 && c < 19 && board[r][c] == 0);
        
        // 找到连续4个子且至少一端为空
        if (count == 4 && (hasEmptyEnd1 || hasEmptyEnd2)) {
            // 确定起始位置（行最小，行相同时列最小）
            r = row;
            c = col;
            while (true) {
                int nr = r - dr;
                int nc = c - dc;
                if (nr >= 0 && nr < 19 && nc >= 0 && nc < 19 && board[nr][nc] == color) {
                    r = nr;
                    c = nc;
                } else {
                    break;
                }
            }
            startRow = r + 1; // 转换为从1开始计数
            startCol = c + 1;
            return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> board(19, vector<int>(19));
    
    // 读取输入
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> board[i][j];
        }
    }
    
    // 遍历棋盘，检查是否有即将获胜的情况
    bool found = false;
    int winningColor = 0;
    int startRow = 0, startCol = 0;
    
    for (int i = 0; i < 19 && !found; i++) {
        for (int j = 0; j < 19 && !found; j++) {
            if (board[i][j] == 1 || board[i][j] == 2) {
                int color = board[i][j];
                int sr, sc;
                if (checkWinning(board, i, j, color, sr, sc)) {
                    winningColor = color;
                    startRow = sr;
                    startCol = sc;
                    found = true;
                }
            }
        }
    }
    
    // 输出结果
    if (found) {
        cout << winningColor << ":" << startRow << "," << startCol << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}