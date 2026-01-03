// game.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>
#include <random>
#include <ctime>

// 定义迷宫格子类型
enum class CellType {
    WALL,
    EMPTY,
    PLAYER,
    ENEMY,
    ITEM,
    EXIT
};

// 定义位置结构体
struct Position {
    int x, y;
    Position(int x = 0, int y = 0) : x(x), y(y) {}
};

// 定义方向枚举
enum class Direction {
    UP, DOWN, LEFT, RIGHT
};

// 迷宫类
class Maze {
private:
    int width, height;
    std::vector<std::vector<CellType>> grid;
    Position playerPos;
    Position exitPos;
    
    // 检查位置是否有效
    bool isValid(int x, int y) {
        return x > 0 && x < width - 1 && y > 0 && y < height - 1 && grid[y][x] == CellType::WALL;
    }
    
    // 随机打乱方向
    std::vector<Direction> getRandomDirections() {
        std::vector<Direction> directions = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(directions.begin(), directions.end(), g);
        return directions;
    }
    
public:
    Maze(int w, int h) : width(w), height(h) {
        // 初始化迷宫，全部为墙
        grid.resize(height, std::vector<CellType>(width, CellType::WALL));
        generateMaze();
    }
    
    // 使用深度优先搜索生成迷宫
    void generateMaze() {
        std::stack<Position> stack;
        
        // 从左上角开始（跳过边界）
        Position start(1, 1);
        grid[start.y][start.x] = CellType::EMPTY;
        stack.push(start);
        
        while (!stack.empty()) {
            Position current = stack.top();
            
            // 获取随机方向
            std::vector<Direction> directions = getRandomDirections();
            bool hasValidNeighbor = false;
            
            for (Direction dir : directions) {
                int nx = current.x;
                int ny = current.y;
                
                // 移动两步
                switch (dir) {
                    case Direction::UP: ny -= 2; break;
                    case Direction::DOWN: ny += 2; break;
                    case Direction::LEFT: nx -= 2; break;
                    case Direction::RIGHT: nx += 2; break;
                }
                
                if (isValid(nx, ny)) {
                    // 打通墙
                    grid[ny][nx] = CellType::EMPTY;
                    grid[(current.y + ny) / 2][(current.x + nx) / 2] = CellType::EMPTY;
                    
                    stack.push(Position(nx, ny));
                    hasValidNeighbor = true;
                    break;
                }
            }
            
            if (!hasValidNeighbor) {
                stack.pop();
            }
        }
        
        // 设置玩家位置和出口位置
        playerPos = Position(1, 1);
        exitPos = Position(width - 2, height - 2);
        grid[playerPos.y][playerPos.x] = CellType::PLAYER;
        grid[exitPos.y][exitPos.x] = CellType::EXIT;
    }
    
    // 绘制迷宫
    void draw() {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                switch (grid[y][x]) {
                    case CellType::WALL: std::cout << "#"; break;
                    case CellType::EMPTY: std::cout << "."; break;
                    case CellType::PLAYER: std::cout << "@"; break;
                    case CellType::ENEMY: std::cout << "E"; break;
                    case CellType::ITEM: std::cout << "I"; break;
                    case CellType::EXIT: std::cout << "X"; break;
                }
            }
            std::cout << std::endl;
        }
    }
    
    // 获取玩家位置
    Position getPlayerPos() const { return playerPos; }
    
    // 移动玩家
    bool movePlayer(Direction dir) {
        int nx = playerPos.x;
        int ny = playerPos.y;
        
        switch (dir) {
            case Direction::UP: ny--; break;
            case Direction::DOWN: ny++; break;
            case Direction::LEFT: nx--; break;
            case Direction::RIGHT: nx++; break;
        }
        
        if (nx >= 0 && nx < width && ny >= 0 && ny < height && 
            (grid[ny][nx] == CellType::EMPTY || grid[ny][nx] == CellType::EXIT)) {
            
            // 更新玩家位置
            grid[playerPos.y][playerPos.x] = CellType::EMPTY;
            playerPos.x = nx;
            playerPos.y = ny;
            grid[ny][nx] = CellType::PLAYER;
            
            return true;
        }
        
        return false;
    }
    
    // 检查是否到达出口
    bool isExit() const {
        return grid[playerPos.y][playerPos.x] == CellType::EXIT;
    }
};

// 玩家类
class Player {
private:
    int health;
    int damage;
    int gold;
    
public:
    Player() : health(100), damage(20), gold(0) {}
    
    void takeDamage(int dmg) {
        health -= dmg;
        if (health < 0) health = 0;
    }
    
    int getHealth() const { return health; }
    int getDamage() const { return damage; }
    int getGold() const { return gold; }
    
    void addGold(int amount) { gold += amount; }
    void heal(int amount) { health += amount; }
};

// 敌人类
class Enemy {
private:
    int health;
    int damage;
    Position pos;
    
public:
    Enemy(int x, int y) : health(50), damage(10), pos(x, y) {}
    
    void takeDamage(int dmg) {
        health -= dmg;
    }
    
    bool isAlive() const { return health > 0; }
    int getDamage() const { return damage; }
    Position getPos() const { return pos; }
};

// 游戏类
class Game {
private:
    Maze* maze;
    Player player;
    std::vector<Enemy> enemies;
    bool isRunning;
    
public:
    Game(int mazeWidth, int mazeHeight) {
        maze = new Maze(mazeWidth, mazeHeight);
        isRunning = true;
        
        // 添加一些敌人
        enemies.emplace_back(3, 3);
        enemies.emplace_back(5, 7);
        enemies.emplace_back(9, 5);
    }
    
    ~Game() {
        delete maze;
    }
    
    // 游戏主循环
    void run() {
        while (isRunning) {
            system("cls"); // 清屏
            
            // 显示玩家状态
            std::cout << "健康值: " << player.getHealth() << " | 攻击力: " << player.getDamage() << " | 金币: " << player.getGold() << std::endl;
            std::cout << "使用 WASD 移动，Q 退出游戏\n\n";
            
            // 绘制迷宫
            maze->draw();
            
            // 检查是否到达出口
            if (maze->isExit()) {
                std::cout << "\n恭喜你到达了出口！游戏胜利！\n";
                isRunning = false;
                break;
            }
            
            // 获取玩家输入
            char input;
            std::cin >> input;
            
            Direction dir;
            bool moved = false;
            
            switch (tolower(input)) {
                case 'w': dir = Direction::UP; moved = maze->movePlayer(dir); break;
                case 's': dir = Direction::DOWN; moved = maze->movePlayer(dir); break;
                case 'a': dir = Direction::LEFT; moved = maze->movePlayer(dir); break;
                case 'd': dir = Direction::RIGHT; moved = maze->movePlayer(dir); break;
                case 'q': isRunning = false; break;
                default: break;
            }
            
            if (moved) {
                // 简单的敌人移动逻辑（这里只是演示，实际可以更复杂）
                // 检查是否与敌人相遇
                Position playerPos = maze->getPlayerPos();
                for (auto& enemy : enemies) {
                    if (enemy.getPos().x == playerPos.x && enemy.getPos().y == playerPos.y) {
                        // 战斗逻辑
                        std::cout << "你遇到了敌人！\n";
                        std::cout << "敌人攻击了你，造成 " << enemy.getDamage() << " 点伤害！\n";
                        player.takeDamage(enemy.getDamage());
                        
                        if (player.getHealth() <= 0) {
                            std::cout << "你被敌人击败了！游戏结束！\n";
                            isRunning = false;
                            break;
                        }
                        
                        std::cout << "你攻击了敌人，造成 " << player.getDamage() << " 点伤害！\n";
                        enemy.takeDamage(player.getDamage());
                        
                        if (!enemy.isAlive()) {
                            std::cout << "你击败了敌人！\n";
                            player.addGold(10);
                        }
                        
                        system("pause");
                        break;
                    }
                }
            }
        }
    }
};

int main() {
    // 设置随机种子
    srand(time(nullptr));
    
    // 创建游戏实例，迷宫大小为21x21（奇数大小保证边界完整）
    Game game(21, 21);
    
    // 运行游戏
    game.run();
    
    return 0;
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
