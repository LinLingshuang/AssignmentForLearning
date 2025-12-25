#ifndef MAP_H
#define MAP_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QTime>
#include <vector>
#include <QPainter>
#include <QDebug>
#include "utils.h"

/**
 * @file map.h
 * @brief 游戏地图系统的核心头文件
 * 
 * 该文件定义了地图系统的核心数据结构和类，包括格子状态、图层管理、
 * 坐标转换、路径生成、碰撞检测等功能。地图类是游戏世界的基础，
 * 负责管理游戏场景中的地形、障碍物、可建造区域等信息。
 */


/**
 * @class Map
 * @brief 游戏地图类，负责管理游戏世界的地形、路径和交互区域
 * 
 * Map类继承自QGraphicsPixmapItem，是游戏场景中的核心组件。它管理着：
 * - 地图的像素尺寸和格子布局
 * - 每个格子的状态（可通过、可建造等）
 * - 地形高度层级
 * - 怪物移动路径的生成
 * - 塔的放置和移除
 * - 坐标转换（像素↔格子）
 * 
 * Map类是游戏世界的基础，为玩家、怪物、塔和子弹提供了交互的环境。
 */
class Map : public QGraphicsPixmapItem
{
public:
    /**
     * @brief 构造函数
     * 
     * 初始化地图的基本参数，加载地图资源，设置初始状态
     */
    Map();
    
    /**
     * @brief 析构函数
     * 
     * 清理地图资源，释放内存
     */
    ~Map();

    // ==================== 基础信息获取 ====================
    /**
     * @brief 获取地图宽度（像素）
     * @return 地图宽度（像素）
     */
    int getWidth() { return width; }
    
    /**
     * @brief 获取地图高度（像素）
     * @return 地图高度（像素）
     */
    int getHeight() { return height; }
    
    /**
     * @brief 获取单个格子的边长（像素）
     * @return 格子边长（像素）
     */
    int gettileSize() { return tileSize; }
    
    /**
     * @brief 获取地图宽度方向上的格子数量
     * @return 宽度方向格子数
     */
    int getWidthNum() { return widthNum; }
    
    /**
     * @brief 获取地图高度方向上的格子数量
     * @return 高度方向格子数
     */
    int getHeightNum() { return heightNum; }

    // ==================== 坐标转换 ====================
    /**
     * @brief 将像素坐标转换为格子坐标
     * @param pixelPos 像素坐标（浮点数精度）
     * @return 对应的格子坐标（整数）
     */
    QPoint pixelToGrid(const QPointF& pixelPos) const;
    
    /**
     * @brief 将格子坐标转换为像素坐标
     * @param gridPos 格子坐标
     * @return 对应的像素坐标（格子中心点）
     */
    QPointF gridToPixel(const QPoint& gridPos) const;
    
    /**
     * @brief 将格子坐标转换为像素坐标（重载版本）
     * @param gridX 格子X坐标
     * @param gridY 格子Y坐标
     * @return 对应的像素坐标（格子中心点）
     */
    QPointF gridToPixel(int gridX, int gridY) const;

    // ==================== 格子状态查询 ====================
    /**
     * @brief 检查指定格子是否可建造
     * @param gridX 格子X坐标
     * @param gridY 格子Y坐标
     * @return 可建造返回true，否则返回false
     */
    bool isBuildable(int gridX, int gridY) const;
    
    /**
     * @brief 检查指定格子是否是障碍物
     * @param gridX 格子X坐标
     * @param gridY 格子Y坐标
     * @return 是障碍物返回true，否则返回false
     */
    bool isBlocked(int gridX, int gridY) const;
    
    /**
     * @brief 检查指定格子是否是梯子/台阶
     * @param gridX 格子X坐标
     * @param gridY 格子Y坐标
     * @return 是梯子返回true，否则返回false
     */
    bool isLadder(int gridX, int gridY) const;
    
    /**
     * @brief 获取指定格子的状态
     * @param gridX 格子X坐标
     * @param gridY 格子Y坐标
     * @return 格子的状态枚举值
     */
    TileState getTileState(int gridX, int gridY) const;
    
    /**
     * @brief 获取指定格子的高度层级
     * @param gridX 格子X坐标
     * @param gridY 格子Y坐标
     * @return 格子的层级枚举值
     */
    TileLayer getTileLayer(int gridX, int gridY) const;
    
    /**
     * @brief 设置指定格子的状态
     * @param gridX 格子X坐标
     * @param gridY 格子Y坐标
     * @param state 要设置的格子状态
     */
    void setTileState(int gridX, int gridY, TileState state);

    // ==================== 边界检查 ====================
    /**
     * @brief 检查像素点是否在地图范围内
     * @param pixelPos 像素坐标
     * @return 在地图内返回true，否则返回false
     */
    bool isInsideMap(const QPointF& pixelPos) const;
    
    /**
     * @brief 检查格子坐标是否在地图范围内
     * @param gridX 格子X坐标
     * @param gridY 格子Y坐标
     * @return 在地图内返回true，否则返回false
     */
    bool isGridInsideMap(int gridX, int gridY) const;

    // ==================== 路径相关 ====================
    /**
     * @brief 初始化地图格子数据
     * 
     * 设置地图每个格子的初始状态和层级
     */
    void initializeTileData();
    
    /**
     * @brief 设置怪物起点
     * @param gridX 起点格子X坐标
     * @param gridY 起点格子Y坐标
     */
    void setStartPoint(int gridX, int gridY);
    
    /**
     * @brief 设置怪物终点
     * @param gridX 终点格子X坐标
     * @param gridY 终点格子Y坐标
     */
    void setEndPoint(int gridX, int gridY);
    
    /**
     * @brief 生成怪物移动路径
     * 
     * 根据起点和终点，使用路径算法生成怪物移动的路径
     */
    void generateMonsterPath();

    /**
     * @brief 检查是否可以从一个格子移动到另一个格子
     * 
     * 考虑格子状态、层级差异和移动规则
     * @param fromX 起始格子X坐标
     * @param fromY 起始格子Y坐标
     * @param toX 目标格子X坐标
     * @param toY 目标格子Y坐标
     * @return 可以移动返回true，否则返回false
     */
    bool canMoveTo(int fromX, int fromY, int toX, int toY) const;
    
    // ==================== 塔相关 ====================
    /**
     * @brief 检查指定位置是否可以放置塔
     * @param pixelPos 像素坐标
     * @return 可以放置返回true，否则返回false
     */
    bool canPlaceTower(const QPoint& gridPos) const;
    
    /**
     * @brief 在指定位置放置塔
     * @param pixelPos 像素坐标
     * @return 放置成功返回true，否则返回false
     */
    bool placeTower(const QPointF& pixelPos);
    
    /**
     * @brief 移除指定位置的塔
     * @param pixelPos 像素坐标
     * @return 移除成功返回true，否则返回false
     */
    bool removeTower(const QPointF& pixelPos);

    // ==================== 绘制相关 ====================
    /**
     * @brief 设置是否显示格子网格（用于调试）
     * @param show true表示显示网格，false表示隐藏
     */
    void setShowGrid(bool show);

    // ==================== 公共成员变量 ====================
    std::vector<QPointF> monsterPath;  ///< 生成的怪物移动路径（像素坐标）
    std::vector<QPointF> monsterHome;
    std::vector<QPoint> playerHome;
    std::vector<std::vector<TileState>> tileState; ///< 二维数组：每个格子的状态
    std::vector<std::vector<TileLayer>> tileLayer; ///< 二维数组：每个格子的高度层级
    
    // 资源位置（用于资源收集系统）
    std::vector<QPoint> grassStone;   ///< 草地石头资源位置
    std::vector<QPoint> swampStone;   ///< 沼泽石头资源位置
    std::vector<QPoint> snowStone;    ///< 雪地石头资源位置
    std::vector<QPoint> grassTree;   ///< 草地树木资源位置
    std::vector<QPoint> swampTree;    ///< 沼泽树木资源位置

protected:
    /**
     * @brief 初始化地图图片资源
     * 
     * 加载地图背景图片和其他相关资源
     */
    void initpic();
    
    /**
     * @brief 获取地图的边界矩形
     * 
     * 重写自QGraphicsItem，用于Qt图形系统的碰撞检测和绘制
     * @return 地图的边界矩形
     */
    QRectF boundingRect() const override;
    
    /**
     * @brief 绘制地图
     * 
     * 重写自QGraphicsItem，负责将地图绘制到屏幕上
     * @param p 绘图设备
     * @param option 样式选项
     * @param widget 父部件
     */
    void paint(QPainter *p, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

private:
    // ==================== 私有成员变量 ====================
    int tileSize;       ///< 单个正方形格子的边长（像素）
    QPixmap background; ///< 地图背景图片
    int width;          ///< 地图总宽度（像素）
    int height;         ///< 地图总高度（像素）
    int widthNum;       ///< 地图宽度方向上的格子数量
    int heightNum;      ///< 地图高度方向上的格子数量

    // 路径相关
    QPoint startPoint;  ///< 怪物起点（格子坐标）
    QPoint endPoint;    ///< 怪物终点（格子坐标）

    // 绘制选项
    bool showGrid;      ///< 是否显示格子网格（用于调试）
};

#endif // MAP_H
