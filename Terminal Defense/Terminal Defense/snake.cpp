#include<iostream>
#include<conio.h>
#include<windows.h>
#include<vector>
#include<random>
using namespace std;

// 定义颜色常量
const int WHITE = 7;
const int RED = 12;
const int GREEN = 10;
const int CYAN = 11;

// 游戏设置
const int WIDTH = 40;
const int HEIGHT = 20;

// 方向枚举
enum Direction {
    STOP = 0,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

// 设置控制台文本颜色
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// 设置光标位置
void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hConsole, coord);
}

// 隐藏光标
void hideCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

// 获取随机数
int getRandomNumber(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

class SnakeGame {
private:
    vector<pair<int, int>> snake; // 蛇的身体部分
    pair<int, int> food;          // 食物位置
    Direction dir;               // 当前方向
    int score;                   // 分数
    bool gameOver;               // 游戏是否结束
    bool paused;                 // 游戏是否暂停

public:
    SnakeGame() {
        resetGame();
    }

    void resetGame() {
        // 重置蛇的位置（初始在中间）
        snake.clear();
        snake.push_back({ WIDTH / 2, HEIGHT / 2 });
        snake.push_back({ WIDTH / 2 - 1, HEIGHT / 2 });
        snake.push_back({ WIDTH / 2 - 2, HEIGHT / 2 });

        // 生成初始食物
        generateFood();

        // 初始化游戏状态
        dir = STOP;
        score = 0;
        gameOver = false;
        paused = false;
    }

    void generateFood() {
        // 确保食物不会生成在蛇身上
        do {
            food.first = getRandomNumber(1, WIDTH - 2);
            food.second = getRandomNumber(1, HEIGHT - 2);
        } while (isSnakeBody(food.first, food.second));
    }

    bool isSnakeBody(int x, int y) {
        for (auto& part : snake) {
            if (part.first == x && part.second == y) {
                return true;
            }
        }
        return false;
    }

    void handleInput() {
        if (_kbhit()) {
            switch (_getch()) {
            case 'w':
            case 'W':
            case 72: // 上箭头键
                if (dir != DOWN) dir = UP;
                break;
            case 's':
            case 'S':
            case 80: // 下箭头键
                if (dir != UP) dir = DOWN;
                break;
            case 'a':
            case 'A':
            case 75: // 左箭头键
                if (dir != RIGHT) dir = LEFT;
                break;
            case 'd':
            case 'D':
            case 77: // 右箭头键
                if (dir != LEFT) dir = RIGHT;
                break;
            case 'p':
            case 'P':
                paused = !paused;
                break;
            case 'r':
            case 'R':
                resetGame();
                break;
            case 'e':
            case 'E':
            case 27: // ESC键
                gameOver = true;
                break;
            }
        }
    }

    void update() {
        if (paused || dir == STOP) return;

        // 获取蛇头位置
        int headX = snake[0].first;
        int headY = snake[0].second;

        // 更新蛇头位置
        switch (dir) {
        case UP:
            headY--;
            break;
        case DOWN:
            headY++;
            break;
        case LEFT:
            headX--;
            break;
        case RIGHT:
            headX++;
            break;
        }

        // 检查碰撞
        if (headX <= 0 || headX >= WIDTH - 1 || headY <= 0 || headY >= HEIGHT - 1) {
            gameOver = true;
            return;
        }

        // 检查是否碰到自己
        if (isSnakeBody(headX, headY)) {
            gameOver = true;
            return;
        }

        // 移动蛇（添加新的头部）
        snake.insert(snake.begin(), { headX, headY });

        // 检查是否吃到食物
        if (headX == food.first && headY == food.second) {
            score += 10;
            generateFood();
        } else {
            // 如果没吃到食物，移除尾部
            snake.pop_back();
        }
    }

    void draw() {
        // 清屏
        system("cls");

        // 绘制顶部边界
        setColor(CYAN);
        for (int i = 0; i < WIDTH; i++) cout << "■";
        cout << endl;

        // 绘制游戏区域
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                if (x == 0 || x == WIDTH - 1) {
                    // 绘制左右边界
                    setColor(CYAN);
                    cout << "■";
                } else if (x == snake[0].first && y == snake[0].second) {
                    // 绘制蛇头
                    setColor(GREEN);
                    cout << "●";
                } else if (x == food.first && y == food.second) {
                    // 绘制食物
                    setColor(RED);
                    cout << "★";
                } else {
                    // 检查是否是蛇身
                    bool isSnake = false;
                    for (size_t i = 1; i < snake.size(); i++) {
                        if (snake[i].first == x && snake[i].second == y) {
                            setColor(GREEN);
                            cout << "○";
                            isSnake = true;
                            break;
                        }
                    }
                    if (!isSnake) {
                        cout << " ";
                    }
                }
            }
            cout << endl;
        }

        // 绘制底部边界
        setColor(CYAN);
        for (int i = 0; i < WIDTH; i++) cout << "■";
        cout << endl;

        // 重置颜色
        setColor(WHITE);

        // 显示分数和操作说明
        cout << "得分: " << score << endl;
        cout << "操作说明: W/S/A/D 或 方向键移动, P 暂停, R 重置, E 退出" << endl;

        // 显示暂停信息
        if (paused) {
            setCursorPosition(WIDTH / 2 - 5, HEIGHT / 2);
            setColor(RED);
            cout << "游戏暂停" << endl;
        }

        // 重置光标位置
        setCursorPosition(0, HEIGHT + 3);
    }

    bool isGameOver() {
        return gameOver;
    }

    void showGameOver() {
        setCursorPosition(WIDTH / 2 - 10, HEIGHT / 2);
        setColor(RED);
        cout << "游戏结束! 最终得分: " << score << endl;
        setCursorPosition(WIDTH / 2 - 15, HEIGHT / 2 + 1);
        cout << "按 R 重新开始, E 退出" << endl;
        setColor(WHITE);
    }
};

int main() {
    // 设置控制台
    system("mode con cols=42 lines=27"); // 设置窗口大小
    hideCursor();

    SnakeGame game;

    // 主游戏循环
    while (!game.isGameOver()) {
        game.draw();
        game.handleInput();
        game.update();
        Sleep(100); // 控制游戏速度
    }

    // 显示游戏结束画面
    game.showGameOver();
    _getch(); // 等待用户按键

    return 0;
}