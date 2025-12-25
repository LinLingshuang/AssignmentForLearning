/**
 * @file map.cpp
 * @brief Map类的实现文件
 * 
 * 该文件包含了Map类的所有成员函数的实现，包括地图初始化、
 * 坐标转换、格子状态管理、路径生成、移动判断、塔的放置和移除等功能。
 * 这是游戏地图系统的核心实现文件。
 */

#include "map.h"
#include <QString>
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QDebug>
#include <cmath>
#include "utils.h"
#include <fstream>


/**
 * @brief Map类构造函数
 * 
 * 初始化地图的基本参数，包括格子大小、地图尺寸、初始位置等
 * 并调用初始化函数加载地图资源和数据
 * 
 * @param tileSize 格子大小（像素），默认值为TILESIZE宏定义
 * @param width 地图宽度（像素），默认值为MAPWIDTH宏定义
 * @param height 地图高度（像素），默认值为MAPHEIGHT宏定义
 * @param showGrid 是否显示格子网格（调试用），默认值为false
 */
Map::Map(): tileSize(TILESIZE), width(MAPWIDTH), height(MAPHEIGHT), showGrid(false)
{
    // 初始化地图图片资源
    initpic();
    
    // 设置地图在场景中的初始位置
    setPos(0, 0);

    // 计算地图上的格子数量
    heightNum = height / tileSize;  // 计算高度方向上的格子数（1920 / 32 = 60）
    widthNum = width / tileSize;    // 计算宽度方向上的格子数（2880 / 32 = 90）

    // 设置地图在Z轴上的层次（确保地图在底层）
    setZValue(MAPZVALUE);
    
    // 初始化地图的格子数据
    initializeTileData();
}

/**
 * @brief 初始化地图格子数据
 * 
 * 从文件中加载地图的格子状态和层级数据，并初始化怪物移动路径
 * 该函数在地图构造时被调用，是地图初始化的核心函数之一
 */
void Map::initializeTileData()
{
    // 初始化怪物移动路径（硬编码的路径点） - 无论文件加载是否成功都要初始化
    monsterPath.resize(19);
    monsterPath = {QPointF(4, 6), QPointF(14, 6), QPointF(14, 21), QPointF(9, 21), QPointF(9, 32), QPointF(20, 32),
                   QPointF(20, 22), QPointF(27, 22), QPointF(27, 8), QPointF(23, 8), QPointF(23, 31), QPointF(31, 31),
                   QPointF(31, 40), QPointF(23, 40), QPointF(23, 46), QPointF(20, 46), QPointF(17, 46), QPointF(17, 47), QPointF(7, 47)};
    
    // 加载格子状态数据（从文件tileState.txt读取）
    std::ifstream ifs1("tileState.txt");
    if(!ifs1.is_open()) {
        qDebug() << "Failed to load tileState.txt! Using default values to initialize tileState.";
        // 初始化tileState为默认值
        tileState.resize(heightNum);
        for(int i = 0; i < heightNum; i++){
            tileState[i].resize(widthNum, TILE_ELSE); // 默认使用普通格子
        }
    }
    else {
        // 调整tileState二维数组的大小以匹配地图尺寸
        tileState.resize(heightNum);
        for(int i = 0; i < heightNum; i++){
            tileState[i].resize(widthNum);
        }
        
        // 读取每个格子的状态数据并转换为TileState枚举类型
        for(int i = 0; i < heightNum; i++){
            for(int j = 0; j < widthNum; j++){
                int tmp;
                ifs1 >> tmp;
                tileState[i][j] = static_cast<TileState>(tmp);
            }
        }
        ifs1.close();
    }

    // 加载格子层级数据（从文件tileLayer.txt读取）
    std::ifstream ifs2("tileLayer.txt");
    if(!ifs2.is_open()) {
        qDebug() << "Failed to load tileLayer.txt! Using default values to initialize tileLayer.";
        // 初始化tileLayer为默认值
        tileLayer.resize(heightNum);
        for(int i = 0; i < heightNum; i++){
            tileLayer[i].resize(widthNum, TILE_FIRST); // 默认使用第一层
        }
    }
    else {
        // 调整tileLayer二维数组的大小以匹配地图尺寸
        tileLayer.resize(heightNum);
        for(int i = 0; i < heightNum; i++){
            tileLayer[i].resize(widthNum);
        }
        
        // 读取每个格子的层级数据并转换为TileLayer枚举类型
        for(int i = 0; i < heightNum; i++){
            for(int j = 0; j < widthNum; j++){
                int tmp;
                ifs2 >> tmp;
                tileLayer[i][j] = static_cast<TileLayer>(tmp);
            }
        }
        ifs2.close();
    }
    monsterPath.resize(19);
    monsterPath = {QPointF(4, 6),
                   QPointF(14, 6),
                   QPointF(14, 21),
                   QPointF(9, 21),
                   QPointF(9, 32), // 5
                   QPointF(20, 32),
                   QPointF(20, 22),
                   QPointF(27, 22),
                   QPointF(27, 8),
                   QPointF(23, 8), //10
                   QPointF(23, 31),
                   QPointF(31, 31),
                   QPointF(31, 40),
                   QPointF(23, 40),
                   QPointF(23, 46), //15
                   QPointF(20, 46),
                   QPointF(17, 46),
                   QPointF(17, 47),
                   QPointF(7, 47)};

    monsterHome.resize(4);
    monsterHome = {QPoint(3, 5),
                   QPoint(5, 54),
                   QPoint(11, 76),
                   QPoint(54, 84)};

    playerHome.resize(1);
    playerHome = {QPoint(6, 47)};

    grassStone.resize(6);
    grassStone = {QPoint(7, 25),
                  QPoint(15, 21),
                  QPoint(19, 5),
                  QPoint(18, 39),
                  QPoint(18, 52),
                  QPoint(34, 29)};

    swampStone.resize(5);
    swampStone = {QPoint(38, 12),
                  QPoint(46, 8),
                  QPoint(38, 31),
                  QPoint(44, 23),
                  QPoint(55, 50)};

    snowStone.resize(4);
    snowStone = {QPoint(5, 60),
                 QPoint(6, 86),
                 QPoint(13, 70),
                 QPoint(21, 73)};

    grassTree.resize(26);
    grassTree = {QPoint(7, 3),
                 QPoint(9, 5),
                 QPoint(12, 3),
                 QPoint(19, 3),
                 QPoint(30, 3), // 5
                 QPoint(26, 5),
                 QPoint(30, 8),
                 QPoint(15, 10),
                 QPoint(32, 15),
                 QPoint(31, 17), // 10
                 QPoint(17, 19),
                 QPoint(18, 20),
                 QPoint(17, 22),
                 QPoint(3, 18),
                 QPoint(3, 28), // 15
                 QPoint(2, 32),
                 QPoint(21, 27),
                 QPoint(20, 29),
                 QPoint(23, 30),
                 QPoint(32, 29), // 20
                 QPoint(16, 33),
                 QPoint(7, 40),
                 QPoint(16, 38),
                 QPoint(20, 40),
                 QPoint(26, 39), // 25
                 QPoint(32, 38)};

    swampTree.resize(19);
    swampTree = {QPoint(37, 7),
                 QPoint(45, 1),
                 QPoint(50, 3),
                 QPoint(57, 2),
                 QPoint(41, 10), // 5
                 QPoint(54, 9),
                 QPoint(40, 16),
                 QPoint(47, 14),
                 QPoint(54, 16),
                 QPoint(57, 16), // 10
                 QPoint(46, 23),
                 QPoint(40, 30),
                 QPoint(54, 33),
                 QPoint(48, 38),
                 QPoint(37, 43), // 15
                 QPoint(42, 45),
                 QPoint(55, 46),
                 QPoint(44, 50),
                 QPoint(56, 55)};

}

/**
 * @brief 坐标转换：像素坐标 -> 格子坐标
 * 
 * 注意！！！
 * - 像素坐标系：原点为左上点，x轴从左到右，y轴从上到下
 * - 格子坐标系：原点为左上点，x轴从上到下（对应像素y轴），y轴从左到右（对应像素x轴）
 * 
 * 该函数将屏幕像素坐标转换为地图格子坐标，用于将游戏对象的位置
 * 映射到对应的地图格子上，以便进行碰撞检测、状态查询等操作。
 * 
 * @param pixelPos 像素坐标（浮点数精度）
 * @return 对应的格子坐标（整数）
 */
QPoint Map::pixelToGrid(const QPointF& pixelPos) const {
    // 注意坐标转换的特殊性：格子X对应像素Y，格子Y对应像素X
    int gridX = static_cast<int>(pixelPos.y()) / tileSize;
    int gridY = static_cast<int>(pixelPos.x()) / tileSize;

    // 确保坐标在有效范围内（防止越界访问）
    gridX = qMax(0, qMin(gridX, heightNum - 1));
    gridY = qMax(0, qMin(gridY, widthNum - 1));

    return QPoint(gridX, gridY);
}

/**
 * @brief 坐标转换：格子坐标 -> 像素坐标(格子中心)
 * 
 * 重载版本，接受QPoint类型的格子坐标
 * 
 * @param gridPos 格子坐标
 * @return 对应的像素坐标（格子中心点）
 */
QPointF Map::gridToPixel(const QPoint& gridPos) const {
    return gridToPixel(gridPos.x(), gridPos.y());
}

/**
 * @brief 坐标转换：格子坐标 -> 像素坐标(格子中心)
 * 
 * 将地图格子坐标转换为屏幕像素坐标（格子中心点），用于将
 * 地图格子的位置映射到屏幕上，以便正确放置游戏对象。
 * 
 * @param gridX 格子X坐标
 * @param gridY 格子Y坐标
 * @return 对应的像素坐标（格子中心点）
 */
QPointF Map::gridToPixel(int gridX, int gridY) const {
    // 注意坐标转换的特殊性：像素X对应格子Y，像素Y对应格子X
    float pixelX = gridY * tileSize + tileSize / 2.0f;  // 计算格子中心X坐标
    float pixelY = gridX * tileSize + tileSize / 2.0f;  // 计算格子中心Y坐标
    return QPointF(pixelX, pixelY);
}

/**
 * @brief 设置指定格子的状态
 * 
 * 直接修改指定格子的状态，用于动态改变地图的可通行性、可建造性等
 * 例如：放置塔后将格子状态改为障碍物，移除塔后改回可建造
 * 
 * @param gridX 格子X坐标
 * @param gridY 格子Y坐标
 * @param state 要设置的格子状态
 */
void Map::setTileState(int gridX, int gridY, TileState state)
{
    tileState[gridX][gridY] = state;
}


/**
 * @brief 检查格子坐标是否在有效范围内
 * 
 * 确保格子坐标不会超出地图的边界，防止数组越界访问
 * 
 * @param gridX 格子X坐标
 * @param gridY 格子Y坐标
 * @return 坐标在有效范围内返回true，否则返回false
 */
bool Map::isGridInsideMap(int gridX, int gridY) const {
    return gridX >= 0 && gridX < heightNum && gridY >= 0 && gridY < widthNum;
}

/**
 * @brief 检查像素坐标是否在地图范围内
 * 
 * 确保像素坐标不会超出地图的边界，用于限制游戏对象的移动范围
 * 
 * @param pixelPos 像素坐标
 * @return 坐标在地图内返回true，否则返回false
 */
bool Map::isInsideMap(const QPointF& pixelPos) const {
    return pixelPos.x() >= 0 && pixelPos.x() < width &&
           pixelPos.y() >= 0 && pixelPos.y() < height;
}


/**
 * @brief 获取指定格子的状态
 * 
 * 安全地获取指定格子的状态，如果坐标越界则返回默认值TILE_BLOCKED
 * 
 * @param gridX 格子X坐标
 * @param gridY 格子Y坐标
 * @return 格子的状态枚举值，如果越界则返回TILE_BLOCKED
 */
TileState Map::getTileState(int gridX, int gridY) const {
    if (!isGridInsideMap(gridX, gridY)) {
        return TILE_BLOCKED;  // 越界视为障碍物，防止访问无效内存
    }
    return static_cast<TileState>(tileState[gridX][gridY]);
}

/**
 * @brief 获取指定格子的高度层级
 * 
 * 安全地获取指定格子的高度层级，如果坐标越界则返回默认值TILE_FIRST
 * 
 * @param gridX 格子X坐标
 * @param gridY 格子Y坐标
 * @return 格子的层级枚举值，如果越界则返回TILE_FIRST
 */
TileLayer Map::getTileLayer(int gridX, int gridY) const {
    if (!isGridInsideMap(gridX, gridY)) {
        return TILE_FIRST;  // 越界视为最高层，防止访问无效内存
    }
    return static_cast<TileLayer>(tileLayer[gridX][gridY]);
}

// ==================== 状态判断的便捷函数 ====================

/**
 * @brief 检查指定格子是否可建造
 * 
 * 便捷函数，判断指定格子是否可以建造塔
 * 
 * @param gridX 格子X坐标
 * @param gridY 格子Y坐标
 * @return 可建造返回true，否则返回false
 */
bool Map::isBuildable(int gridX, int gridY) const {
    TileState state = getTileState(gridX, gridY);
    return state == TILE_BUILDABLE;
}

/**
 * @brief 检查指定格子是否是障碍物
 * 
 * 便捷函数，判断指定格子是否是障碍物（不可通行）
 * 
 * @param gridX 格子X坐标
 * @param gridY 格子Y坐标
 * @return 是障碍物返回true，否则返回false
 */
bool Map::isBlocked(int gridX, int gridY) const {
    return getTileState(gridX, gridY) == TILE_BLOCKED;
}

/**
 * @brief 检查指定格子是否是梯子/台阶
 * 
 * 便捷函数，判断指定格子是否是梯子或台阶（允许不同层之间移动）
 * 
 * @param gridX 格子X坐标
 * @param gridY 格子Y坐标
 * @return 是梯子返回true，否则返回false
 */
bool Map::isLadder(int gridX, int gridY) const {
    return getTileState(gridX, gridY) == TILE_LADDER;
}

/**
 * @brief 检查是否可以从一个格子移动到另一个格子
 * 
 * 该函数实现了游戏中的移动规则判断，考虑了以下因素：
 * 1. 目标格子是否在地图范围内
 * 2. 目标格子是否可通行（排除障碍物）
 * 3. 不同高度层级之间的移动是否有梯子支持
 * 
 * 这是游戏角色移动、怪物寻路等功能的基础。
 * 
 * @param fromX 起始格子X坐标
 * @param fromY 起始格子Y坐标
 * @param toX 目标格子X坐标
 * @param toY 目标格子Y坐标
 * @return 可以移动返回true，否则返回false
 */
bool Map::canMoveTo(int fromX, int fromY, int toX, int toY) const {
    // 1. 检查目标格子是否在地图范围内
    if (!isGridInsideMap(toX, toY)) {
        return false;
    }

    // 2. 获取起始格子和目标格子的高度层级
    TileLayer toLayer = getTileLayer(toX, toY);
    TileLayer fromLayer = getTileLayer(fromX, fromY);

    // 3. 获取起始格子和目标格子的状态
    TileState toState = getTileState(toX, toY);
    TileState fromState = getTileState(fromX, fromY);

    // 4. 检查目标格子是否可通行（排除障碍物）
    if (toState == TILE_BLOCKED) {
        return false;
    }

    // 5. 如果不同层，需要检查是否有梯子支持
    if (toLayer != fromLayer) {
        // 检查当前位置或目标位置是否有梯子
        bool hasLadder = (fromState == TILE_LADDER) || (toState == TILE_LADDER);
        if (!hasLadder) {
            return false;  // 没有梯子，不同层之间不能直接移动
        }
    }
    
    // 所有条件都满足，可以移动
    return true;
}

/**
 * @brief 设置怪物起始点
 * 
 * 设置怪物的起始位置，并将对应格子的状态标记为起点。
 * 怪物将从这个点开始沿着预设路径移动。
 * 
 * @param gridX 格子X坐标
 * @param gridY 格子Y坐标
 */
void Map::setStartPoint(int gridX, int gridY) {
    if (isGridInsideMap(gridX, gridY)) {
        startPoint = QPoint(gridX, gridY);
        setTileState(gridX, gridY, TILE_START);
    }
}

/**
 * @brief 设置怪物终点
 * 
 * 设置怪物的目标位置，并将对应格子的状态标记为终点。
 * 当怪物到达这个点时，游戏会损失生命值。
 * 
 * @param gridX 格子X坐标
 * @param gridY 格子Y坐标
 */
void Map::setEndPoint(int gridX, int gridY) {
    if (isGridInsideMap(gridX, gridY)) {
        endPoint = QPoint(gridX, gridY);
        setTileState(gridX, gridY, TILE_END);
    }
}

/**
 * @brief 初始化地图图片资源
 * 
 * 加载地图的背景图片资源，该图片将作为游戏地图的视觉表现。
 * 图片资源路径为":/picture/map/map.png"，位于Qt资源文件中。
 */
void Map::initpic()
{
    background.load(QString(":/picture/map/map.png"));
}

/**
 * @brief 获取地图的边界矩形
 * 
 * 重写QGraphicsItem的boundingRect()函数，返回地图的边界矩形。
 * 该函数用于Qt图形系统的碰撞检测和绘制优化。
 * 
 * @return 地图的边界矩形
 */
QRectF Map::boundingRect() const
{
    return QRectF(0, 0, width, height);
}

/**
 * @brief 绘制地图
 * 
 * 重写QGraphicsItem的paint()函数，负责地图的视觉渲染。
 * 主要功能包括：
 * 1. 绘制地图背景图片
 * 2. （可选）绘制格子网格和类型标识（用于调试）
 * 
 * @param p 绘图设备
 * @param option 绘图选项（未使用）
 * @param widget 父部件（未使用）
 */
void Map::paint(QPainter *p, const QStyleOptionGraphicsItem* , QWidget* )
{
    // 绘制背景
    p->drawPixmap(0, 0, background);

    // 如果开启网格显示，绘制格子边界和类型（这个超级棒在gameWidght.cpp里 47行 map[0]->setShowGrid(true);)
    if (showGrid) {
        p->setPen(QPen(Qt::gray, 1));

        // 绘制格子边界
        for (int y = 0; y <= heightNum; ++y) {
            p->drawLine(0, y * tileSize, width, y * tileSize);
        }
        for (int x = 0; x <= widthNum; ++x) {
            p->drawLine(x * tileSize, 0, x * tileSize, height);
        }

        // 绘制格子类型（颜色标识）
        for (int y = 0; y < heightNum; ++y) {
            for (int x = 0; x < widthNum; ++x) {
                TileState state = getTileState(y, x);
                QColor color;

                switch (state) {
                case TILE_BLOCKED:  // 1
                    color = QColor(255, 0, 0, 100);      // 红色（障碍）
                    break;

                case TILE_BUILDABLE: // 3
                    color = QColor(34, 139, 34, 50);     // 绿色（可建造）
                    break;

                case TILE_LADDER: // 4
                    color = QColor(255, 255, 0, 150);    // 黄色（梯子/台阶）
                    break;

                case TILE_START: // 5
                    color = QColor(0, 255, 0, 150);      // 亮绿色（起点）
                    break;

                case TILE_END: // 6
                    color = QColor(255, 0, 0, 150);      // 亮红色（终点）
                    break;

                default: // 普通格子 = 0
                    color = QColor(200, 200, 200, 50);   // 灰色
                    break;
                }

                p->fillRect(x * tileSize, y * tileSize, tileSize, tileSize, color);

                // 为特殊格子添加文字标识
                if (state == TILE_START) {
                    p->setPen(QPen(Qt::white, 2));
                    p->drawText(x * tileSize, y * tileSize, tileSize, tileSize,
                                Qt::AlignCenter, "S");
                } else if (state == TILE_END) {
                    p->setPen(QPen(Qt::white, 2));
                    p->drawText(x * tileSize, y * tileSize, tileSize, tileSize,
                                Qt::AlignCenter, "E");
                } else if (state == TILE_LADDER) {
                    p->setPen(QPen(Qt::black, 2));
                    p->drawText(x * tileSize, y * tileSize, tileSize, tileSize,
                                Qt::AlignCenter, "L");
                }
            }
        }
    }
}

/**
 * @brief 设置是否显示网格
 * 
 * 控制是否在地图上显示格子网格和类型标识，用于调试和开发。
 * 当show为true时，地图会显示格子边界和不同类型格子的颜色标识。
 * 
 * @param show 是否显示网格
 */
void Map::setShowGrid(bool show) {
    showGrid = show;
    update();  // 请求重绘
}

/**
 * @brief 检查是否可以在指定位置放置塔
 * 
 * 根据像素坐标检查对应位置是否可以放置塔，塔只能放在可建造的格子上。
 * 
 * @param pixelPos 像素坐标
 * @return 可以放置返回true，否则返回false
 */

bool Map::canPlaceTower(const QPoint& gridPos) const {
    return isBuildable(gridPos.x(), gridPos.y());
}
/**
 * @brief 放置塔
 * 
 * 在指定像素位置放置塔，并将对应格子的状态设置为障碍物。
 * 
 * @param pixelPos 像素坐标
 * @return 放置成功返回true，否则返回false
 */
bool Map::placeTower(const QPointF& pixelPos) {
    QPoint gridPos = pixelToGrid(pixelPos);
    if (isBuildable(gridPos.x(), gridPos.y())) {
        setTileState(gridPos.x(), gridPos.y(), TILE_BLOCKED);
        return true;
    }
    return false;
}

/**
 * @brief 移除塔
 * 
 * 移除指定像素位置的塔，并将对应格子的状态恢复为可建造。
 * 
 * @param pixelPos 像素坐标
 * @return 移除成功返回true，否则返回false
 */
bool Map::removeTower(const QPointF& pixelPos) {
    QPoint gridPos = pixelToGrid(pixelPos);
    if (getTileState(gridPos.x(), gridPos.y()) == TILE_BLOCKED) {
        setTileState(gridPos.x(), gridPos.y(), TILE_BUILDABLE);
        return true;
    }
    return false;
}


/**
 * @brief Map类析构函数
 * 
 * 清理地图资源，释放动态分配的内存。
 * 主要功能包括：
 * 1. 清理格子状态数据
 * 2. 清理格子层级数据
 */
Map::~Map() {
    // 清理tileData
    for (auto& row : tileState) {
        row.clear();
    }
    tileState.clear();

    for (auto& row : tileLayer) {
        row.clear();
    }
    tileLayer.clear();
}
