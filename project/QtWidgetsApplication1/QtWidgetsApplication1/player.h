/**
 * @file player.h
 * @brief 游戏玩家角色类头文件
 * 
 * 该文件定义了玩家角色的类结构，包括移动、动画、翻滚等核心功能。
 * Player类继承自QObject和QGraphicsPixmapItem，实现了游戏中的玩家角色
 * 控制逻辑和视觉表现，是玩家与游戏世界交互的核心组件。
 */
#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>  ///< Qt图形项基类，用于玩家图形显示
#include <QPixmap>              ///< Qt图像类，用于加载和存储玩家动画帧
#include <QTimer>               ///< Qt定时器类，用于动画和移动更新
#include <QTime>                ///< Qt时间类，用于计时和时间管理
#include <QDebug>               ///< Qt调试类，用于开发调试
#include <QPainter>             ///< Qt绘图类，用于自定义绘制
#include "utils.h"              ///< 游戏工具函数，提供辅助功能
#include "resource.h"
#include <QObject>                  ///< 包含Qt对象类

/**
 * @brief 玩家角色类
 * 
 * 处理玩家的移动、动画、翻滚等核心功能。
 * 该类是游戏中玩家角色的核心实现，负责接收玩家输入、更新角色状态、
 * 处理碰撞检测以及渲染玩家图形。
 */
class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    /**
     * @brief 玩家构造函数
     * 
     * 初始化玩家角色的属性、动画帧、定时器等。
     * 设置默认位置、速度、动画状态等初始值，并连接必要的信号和槽。
     */
    Player();

    /**
     * @brief 设置向上移动状态
     * 
     * 控制玩家是否向上移动
     * @param on true表示启用向上移动，false表示禁用
     */
    void setMoveUp(bool on);

    /**
     * @brief 设置向下移动状态
     * 
     * 控制玩家是否向下移动
     * @param on true表示启用向下移动，false表示禁用
     */
    void setMoveDown(bool on);

    /**
     * @brief 设置向左移动状态
     * 
     * 控制玩家是否向左移动
     * @param on true表示启用向左移动，false表示禁用
     */
    void setMoveLeft(bool on);

    /**
     * @brief 设置向右移动状态
     * 
     * 控制玩家是否向右移动
     * @param on true表示启用向右移动，false表示禁用
     */
    void setMoveRight(bool on);

    bool getWalkUp() { return walk_up; }
    bool getWalkDown() { return walk_down; }
    bool getWalkLeft() { return walk_left; }
    bool getWalkRight() { return walk_right; }

    PlayerState getState() { return state; }

    void setRollUp(bool on) { roll_up = on; }
    void setRollDown(bool on) { roll_down = on; }
    void setRollLeft(bool on) { roll_left = on; }
    void setRollRight(bool on) {roll_right = on; }

    void setCutLeft(bool on) { cut_left = on; }
    void setCutRight(bool on) { cut_right = on; }

    void setDigLeft(bool on) { dig_left = on; }
    void setDigRight(bool on) { dig_right = on; }

    void setState(PlayerState sta) { state = sta; }

    /**
     * @brief 更新玩家位置
     * 
     * 根据当前移动状态和时间间隔更新玩家的位置
     */
    void updatePosition();
    void updatePicture();
    void findNearbyResource();
    
    /**
     * @brief 检查玩家是否正在特定状态
     * 
     * @return bool 正在该状态返回true，否则返回false
     */
    bool isWalking() { return state == PlayerState::WALKING; }
    bool isRolling() { return state == PlayerState::ROLLING; }
    bool isCutting() { return state == PlayerState::CUTTING; }
    bool isDigging() { return state == PlayerState::DIGGING; }

    /**
     * @brief 获取玩家的检测范围
     * 
     * @return qreal 玩家的检测范围（像素）
     */
    qreal getRange() { return detectRange; }
    
    /**
     * @brief 获取玩家的中心位置
     * 
     * @return QPointF 玩家的中心位置坐标
     */
    QPointF getCenterPos() { return pos() + QPointF(TILESIZE / 2.0, TILESIZE / 2.0); }
    
    /**
     * @brief 检查指定网格是否在玩家的检测范围内
     * 
     * @param gridX 网格X坐标
     * @param gridY 网格Y坐标
     * @return bool 是否在检测范围内
     */
    bool isDetectable(int gridX, int gridY);
    
    /**
     * @brief 暂停玩家的所有活动
     * 
     * 暂停所有定时器和动画
     */
    void pause();
    
    /**
     * @brief 恢复玩家的所有活动
     * 
     * 恢复所有定时器和动画
     */
    void resume();

    Resource * getTarget() { return target; }

protected:
    /**
     * @brief 获取玩家的碰撞边界
     * 
     * 重写QGraphicsItem的boundingRect函数，返回玩家的碰撞检测边界
     * @return QRectF 玩家的碰撞边界矩形
     */
    QRectF boundingRect() const override;

    /**
     * @brief 绘制玩家图形
     * 
     * 重写QGraphicsItem的paint函数，根据当前状态绘制玩家图形
     * @param p 绘图设备指针，用于绘制玩家
     * @param option 绘图选项，提供绘制上下文信息
     * @param widget 绘图窗口，通常为nullptr
     */
    void paint(QPainter *p, const QStyleOptionGraphicsItem*, QWidget*) override;

    /**
     * @brief 初始化玩家图片资源
     * 
     * 加载玩家的所有动画帧资源，包括行走、翻滚等不同动作的图片
     */
    void initpic();

private:
    int width;                 ///< 玩家宽度（像素）
    int height;                ///< 玩家高度（像素）
    QPixmap leftWalking[4];    ///< 向左行走的4个动画帧
    QPixmap rightWalking[4];   ///< 向右行走的4个动画帧
    QPixmap leftRolling[4];    ///< 向左翻滚的4个动画帧
    QPixmap rightRolling[4];   ///< 向右翻滚的4个动画帧
    bool isGoingLeft;          ///< 移动方向标志，true表示向左，false表示向右

    bool isWalkingLeft = false;
    bool isRollingLeft = false;
    bool isCuttingLeft = false;
    bool isDiggingLeft = false;

    QPixmap leftCutting[4];
    QPixmap rightCutting[4];

    QPixmap leftDigging[4];
    QPixmap rightDigging[4];


    QTimer moveTimer;          ///< 移动更新定时器
    QTimer rollTimer;          ///< 翻滚状态定时器
    QTimer picTimer;           ///< 控制图片切换
    QTimer findTimer;

    bool walk_up= false;       ///< 向上移动标志，true表示正在向上移动
    bool walk_down= false;     ///< 向下移动标志，true表示正在向下移动
    bool walk_left= false;     ///< 向左移动标志，true表示正在向左移动
    bool walk_right= false;    ///< 向右移动标志，true表示正在向右移动

    bool roll_up = false;
    bool roll_down = false;
    bool roll_left = false;
    bool roll_right = false;

    bool cut_left = false;
    bool cut_right = false;

    bool dig_left = false;
    bool dig_right = false;

    int walkIndex = 0;
    int rollIndex = -1;
    int cutIndex = -1;
    int digIndex = -1;

    int walkFrameCounter = 0;
    int rollFrameCounter = 0;
    int cutFrameCounter = 0;
    int digFrameCounter = 0;

    qreal walk_speed = WALKSPEED;   //单位：像素/秒
    qreal roll_speed = ROLLSPEED;

    PlayerState state = PlayerState::WALKING;

    Resource * target = nullptr;
    qreal detectRange = 100.0;
signals:
    /**
     * @brief 翻滚信号
     * 
     * 当玩家执行翻滚动作时发出此信号，可用于触发相关的游戏逻辑，
     * 如无敌状态、音效播放等。
     */
    void rolling();
    
    /**
     * @brief 移动信号
     * 
     * 当玩家移动时发出此信号，可用于触发移动音效等。
     */
    void moved();
};

#endif // PLAYER_H
