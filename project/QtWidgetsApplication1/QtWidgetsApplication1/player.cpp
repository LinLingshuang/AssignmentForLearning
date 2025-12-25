/**
 * @file player.cpp
 * @brief 游戏玩家角色类实现文件
 * 
 * 该文件包含了Player类的所有成员函数的实现，包括玩家的移动控制、
 * 动画管理、翻滚动作、碰撞检测和渲染等核心功能。
 * 这是游戏中玩家角色的核心实现文件，负责处理玩家输入和游戏世界的交互。
 */
#include "player.h"
#include <QString>         ///< Qt字符串类，用于资源路径构建
#include <QPainter>        ///< Qt绘图类，用于玩家图形绘制
#include <QTransform>      ///< Qt变换类，用于图片镜像处理
#include "utils.h"         ///< 游戏工具函数，提供辅助功能
#include "global.h"        ///< 游戏全局变量，用于访问地图等全局对象
#include "resource.h"
#include "resourcemanager.h"

/**
 * @brief 玩家构造函数
 * 
 * 初始化玩家角色的属性、动画资源和定时器。
 * 设置默认位置、速度、动画状态等初始值，并连接必要的信号和槽。
 */
Player::Player()
{
    initpic();                   // 初始化玩家图片资源（加载动画帧）
    setZValue(PLAYERZVALUE);     // 设置玩家在场景中的层级（确保显示在地图上方）

    setPos(47*32, 7*32);  // 将玩家初始位置设置在帐篷处


    /*
    // 初始化移动状态标志
    walk_up = false;
    walk_down = false;
    walk_left = false;
    walk_right = false;
    rollingCount = 0;            // 初始化翻滚计数为0（重要：防止随机值导致isRolling()返回true）
    nowIndex = 0;                // 初始化动画帧索引
    isGoingLeft = false;         // 初始化朝向标志
    */
    /*
    // 初始化行走动画定时器
    walkTimer.setInterval(WAKEDELTA);  // 设置动画切换间隔（毫秒）
    connect(&walkTimer, &QTimer::timeout, this, [this](){
        // 只有在移动时才更新动画帧
        if(walk_up || walk_down || walk_left || walk_right)
        {
            // 根据移动方向设置朝向标志
            if(walk_left)
            {
                isGoingLeft = true;
            }
            if(walk_right)
            {
                isGoingLeft = false;
            }
            nowIndex = (nowIndex + 1) % 4;  // 循环更新动画帧索引（0-3）
            update();  // 触发重绘，更新玩家图形
        }
        else
        {
            // 停止移动时重置动画帧索引（回到第一帧）
            nowIndex = 0;
            update();  // 触发重绘，更新玩家图形
        }
    });
    walkTimer.start();  // 启动行走动画定时器

    // 初始化移动定时器
    moveTimer.setInterval(SPEEDDELTA);  // 设置移动更新间隔（毫秒）
    connect(&moveTimer, &QTimer::timeout, this, [&](){
        updatePosition(me_speed, SPEEDDELTA);  // 使用基础速度更新玩家位置
    });
    moveTimer.start();  // 启动移动定时器

    // 初始化翻滚定时器
    rollTimer.setInterval(ROLLDELTA);  // 设置翻滚动画间隔（毫秒）
    connect(this, &Player::rolling, this, [&](){
        // 只有在移动时才能触发翻滚动作
        if(!walk_up && !walk_down && !walk_left && !walk_right) return;
        
        walkTimer.stop();  // 停止行走动画
        moveTimer.stop();  // 停止普通移动
        rollTimer.start(); // 启动翻滚动画和移动
    });

    connect(&rollTimer, &QTimer::timeout, this, [&](){
        ++rollingCount;  // 增加翻滚计数（用于控制翻滚动画和状态）
        update();  // 更新动画，绘制当前翻滚帧
        updatePosition(ROLLSPEED, ROLLDELTA);  // 以翻滚速度（更快）更新位置
        
        // 翻滚结束条件：达到指定的翻滚次数（4帧/次 × 翻滚次数）
        if(rollingCount >= 4 * ROLLTIMES)
        {
            rollingCount = 0;  // 重置翻滚计数
            walkTimer.start(); // 恢复行走动画
            moveTimer.start(); // 恢复普通移动
            rollTimer.stop();  // 停止翻滚
        }
    });
}
    */
    //处理人物行走图片帧变化 
    picTimer.setInterval(PICTURE_DELTA);
    connect(&picTimer, &QTimer::timeout, this, [&](){
        updatePicture();
    });
    picTimer.start();

    //处理玩家移动速度
    moveTimer.setInterval(POSITION_DELTA);
    connect(&moveTimer, &QTimer::timeout, this, [&](){
        updatePosition();
    });
    moveTimer.start();

    //资源寻找
    findTimer.setInterval(FIND_TARGET_INTERVAL);
    connect(&findTimer, &QTimer::timeout, this, [&](){
        findNearbyResource();
    });
    findTimer.start();
}

/**
 * @brief 设置向上移动状态
 * 
 * 控制玩家是否向上移动
 * @param on true表示启用向上移动，false表示禁用
 */
void Player::setMoveUp(bool on)    { walk_up = on; }

/**
 * @brief 设置向下移动状态
 * 
 * 控制玩家是否向下移动
 * @param on true表示启用向下移动，false表示禁用
 */
void Player::setMoveDown(bool on)  { walk_down = on; }

/**
 * @brief 设置向左移动状态
 * 
 * 控制玩家是否向左移动
 * @param on true表示启用向左移动，false表示禁用
 */
void Player::setMoveLeft(bool on)  { walk_left = on; }

/**
 * @brief 设置向右移动状态
 * 
 * 控制玩家是否向右移动
 * @param on true表示启用向右移动，false表示禁用
 */
void Player::setMoveRight(bool on) { walk_right = on; }

/**
 * @brief 更新玩家位置
 * 
 * 根据当前移动状态、速度和时间间隔计算新位置，并处理碰撞检测
 * 
 * @param speed 移动速度（像素/秒）
 * @param delta 时间间隔（毫秒）
 */
void Player::updatePosition()
{
    // 如果没有移动标志，直接返回
    if (!walk_up && !walk_down && !walk_left && !walk_right) {
        return;
    }
    
    // 检查地图是否已初始化
    if (!gMap) {
        qDebug() << "Warning: Map not initialized, player cannot move";
        return;
    }
    
    // 使用实际的moveTimer间隔（POSITION_DELTA）
    // 这确保了速度计算的准确性
    qreal delta = POSITION_DELTA;
    qreal speed = 0.0;
    bool m_up = false;
    bool m_down = false;
    bool m_left = false;
    bool m_right = false;
    switch(state)
    {
    case PlayerState::WALKING:
        speed = WALKSPEED;
        m_up = walk_up;
        m_down = walk_down;
        m_left = walk_left;
        m_right = walk_right;
        break;
    case PlayerState::ROLLING:
        speed = ROLLSPEED;
        m_up = roll_up;
        m_down = roll_down;
        m_left = roll_left;
        m_right = roll_right;
        break;
    case PlayerState::CUTTING:
        return;
    case PlayerState::DIGGING:
        return;
    }

    QPointF vel(0, 0);  // 初始化速度向量（x和y方向的移动分量）
    
    // 根据移动标志更新速度向量
    if (m_up)    vel.ry() -= 1;  // 向上移动（y轴负方向）
    if (m_down)  vel.ry() += 1;  // 向下移动（y轴正方向）
    if (m_left)  vel.rx() -= 1;  // 向左移动（x轴负方向）
    if (m_right) vel.rx() += 1;  // 向右移动（x轴正方向）

    // 归一化速度向量，确保对角线移动速度与轴向移动速度一致
    // （避免对角线移动比直线移动更快的问题）
    if (!qFuzzyIsNull(vel.x()) || !qFuzzyIsNull(vel.y()))
    {
        qreal len = qSqrt(vel.x()*vel.x() + vel.y()*vel.y());  // 计算向量长度
        if (len > 0) {
            vel /= len;  // 归一化向量
        }
    }

    // 计算移动距离（基于速度和时间间隔）
    qreal dt = delta / 1000.0;  // 将毫秒转换为秒（时间步长）
    QPointF center = QPointF(pos().x() + TILESIZE/ 2, pos().y() + TILESIZE / 2);
    QPointF newPos = pos() + vel * (speed * dt); // 计算新位置
    QPointF newCenter = QPointF(newPos.x() + TILESIZE/ 2, newPos.y() + TILESIZE / 2);
    QPointF currentPos = pos();

    // 边界检查：确保新位置在地图范围内
    if (newPos.x() < 0) newPos.setX(0);
    if (newPos.y() < 0) newPos.setY(0);
    if (newPos.x() + TILESIZE > gMap->getWidth()) newPos.setX(gMap->getWidth() - TILESIZE);
    if (newPos.y() + TILESIZE > gMap->getHeight()) newPos.setY(gMap->getHeight() - TILESIZE);

    // 获取当前和新位置对应的网格坐标
    QPointF grid = gMap->pixelToGrid(center);
    QPointF currentCenter = QPointF(currentPos.x() + TILESIZE / 2.0, currentPos.y() + TILESIZE / 2.0);
    QPoint newGrid = gMap->pixelToGrid(newCenter);
    
    // 玩家移动检测：使用地图的canMoveTo函数检查移动合法性
    // canMoveTo会检查：
    // 1. 目标格子是否在地图范围内
    // 2. 目标格子是否被阻塞
    // 3. 如果不同层，需要检查是否有梯子支持（当前位置或目标位置有梯子）
    bool canMove = gMap->canMoveTo(grid.x(), grid.y(), newGrid.x(), newGrid.y());
    
    if (canMove) {
        setPos(newPos);  // 如果可以移动，更新玩家位置
        emit moved();    // 发射移动信号，用于播放移动音效
    } else {
        // 可选：添加调试信息，帮助理解为什么移动被阻止
        // TileLayer fromLayer = gMap->getTileLayer(currentGrid.x(), currentGrid.y());
        // TileLayer toLayer = gMap->getTileLayer(newGrid.x(), newGrid.y());
        // if (fromLayer != toLayer) {
        //     qDebug() << "Movement blocked: Different layers require ladder. From layer:" << fromLayer << "To layer:" << toLayer;
        // }
    }
}

void Player::findNearbyResource()
{
    if (state != PlayerState::WALKING) return;
    QPointF center = pos() + QPointF(PLAYERWIDTH / 2, PLAYERHEIGHT / 2);
    QPoint grid = gMap->pixelToGrid(center);

    static const QPoint dirs[] = {
        {0, 0}, {0, 1}, {0, -1}
    };

    Resource* r;
    for (const QPoint& d : dirs)
    {
        QPoint checkGrid = grid + d;
        // 添加空指针检查，防止段错误
        if (resourceManager)
        {
            r = resourceManager->checkResource(checkGrid);
            if (r && !r->isDead())
            {
                if(target != nullptr && target != r)
                {
                    target->setSelected(false);
                    target->update();
                }
                target = r;
                target->setSelected(true);
                target->update();
                return;
            }
        }
    }
    if(target != nullptr)
    {
        target->setSelected(false);
        target->update();
    }
    target = nullptr;
}

/**
 * @brief 获取玩家的碰撞边界
 * 
 * 重写QGraphicsItem的boundingRect函数，定义玩家的碰撞检测区域。
 * 碰撞边界用于Qt的碰撞检测系统，确保玩家与游戏世界的正确交互。
 * 
 * @return QRectF 玩家的碰撞边界矩形
 */
QRectF Player::boundingRect() const
{
    return QRectF(0, 0, PLAYERWIDTH, PLAYERHEIGHT);  // 返回玩家的碰撞边界（基于玩家尺寸）
}

//更新图像函数
void Player::updatePicture()
{
    if(state == PlayerState::WALKING)
    {
        if(walk_left)  isWalkingLeft = true;
        if(walk_right)  isWalkingLeft = false;
        if(!walk_up && !walk_down && !walk_left && !walk_right)
        {
            walkIndex = 0;
            update();
            return;
        }
        walkFrameCounter += PICTURE_DELTA;
        if(walkFrameCounter >= WALK_FRAME_INTERVAL)
        {
            walkFrameCounter = 0;
            walkIndex = (walkIndex + 1) % 4;
            update();
        }
    }
    else if(state == PlayerState::ROLLING)
    {
        if(roll_left)  isRollingLeft = true;
        if(roll_right)  isRollingLeft = false;
        if(!roll_up && !roll_down && !roll_left && !roll_right)
        {
            rollIndex = 0;
            state = PlayerState::WALKING;
            update();
            return;
        }
        rollFrameCounter += PICTURE_DELTA;
        if(rollFrameCounter >= ROLL_FRAME_INTERVAL)
        {
            rollFrameCounter = 0;
            ++rollIndex;
            update();
            if(rollIndex >= 4 * ROLLTIMES)
            {
                rollIndex = -1;
                state = PlayerState::WALKING;
                // 重置移动标志，防止翻滚结束后继续移动
                walk_up = false;
                walk_down = false;
                walk_left = false;
                walk_right = false;
                // 重置翻滚方向标志
                roll_up = false;
                roll_down = false;
                roll_left = false;
                roll_right = false;
            }
        }
    }
    else if(target != nullptr && state == PlayerState::CUTTING)
    {
        if(cut_left)  isCuttingLeft = true;
        if(cut_right)  isCuttingLeft = false;
        if(!cut_left && !cut_right)
        {
            cutIndex = 0;
            state = PlayerState::WALKING;
            update();
            return;
        }
        cutFrameCounter += PICTURE_DELTA;
        if(cutFrameCounter >= CUT_FRAME_INTERVAL)
        {
            cutFrameCounter = 0;
            cutIndex = (cutIndex + 1) % 4;
            update();
            if(cutIndex >= 3)
            {
                cutIndex = -1;
                target->takeDamage();
                state = PlayerState::WALKING;
            }
        }
    }
    else if(target != nullptr && state == PlayerState::DIGGING)
    {
        if(dig_left)  isDiggingLeft = true;
        if(dig_right)  isDiggingLeft = false;
        if(!dig_left && !dig_right)
        {
            digIndex = 0;
            state = PlayerState::WALKING;
            update();
            return;
        }
        digFrameCounter += PICTURE_DELTA;
        if(digFrameCounter >= DIG_FRAME_INTERVAL)
        {
            digFrameCounter = 0;
            digIndex = (digIndex + 1) % 4;
            update();
            if(digIndex >= 3)
            {
                digIndex = -1;
                target->takeDamage();
                state = PlayerState::WALKING;
            }
        }
    }
}

/**
 * @brief 绘制玩家图形
 * 
 * 重写QGraphicsItem的paint函数，根据当前状态绘制玩家图形。
 * 根据移动方向和是否翻滚选择对应的动画帧进行绘制。
 * 
 * @param p 绘图设备指针，用于绘制玩家图形
 * @param option 绘图选项（未使用）
 * @param widget 父部件（未使用）
 */
void Player::paint(QPainter *p, const QStyleOptionGraphicsItem*, QWidget*)
{
    // 根据朝向和是否翻滚选择对应的动画帧
    if(isWalking())
    {
        if(isWalkingLeft)  p->drawPixmap(0, 0, leftWalking[walkIndex]);
        else  p->drawPixmap(0, 0, rightWalking[walkIndex]);
    }
    else if(isRolling())
    {
        if(isRollingLeft)  p->drawPixmap(0, 0, leftRolling[rollIndex % 4]);
        else  p->drawPixmap(0, 0, rightRolling[rollIndex % 4]);
    }
    else if(isCutting())
    {
        if(isCuttingLeft)  p->drawPixmap(0, 0, leftCutting[cutIndex]);
        else  p->drawPixmap(0, 0, rightCutting[cutIndex]);
    }
    else if(isDigging())
    {
        if(isDiggingLeft)  p->drawPixmap(0, 0, leftDigging[digIndex]);
        else  p->drawPixmap(0, 0, rightDigging[digIndex]);
    }
}

/**
 * @brief 初始化玩家图片资源
 *
 * 从资源文件中加载玩家的行走和翻滚动画帧。
 * 加载向左方向的动画帧，然后通过镜像处理生成向右方向的动画帧。
 */

void Player::initpic()
{
    for(int i = 0; i < 4; i++)
    {
        leftWalking[i].load(QString(":/picture/player/walking/%1.png").arg(i + 1));
        rightWalking[i] = leftWalking[i].transformed(QTransform().scale(-1, 1));
    }
    for(int i = 0; i < 4; i++)
    {
        leftRolling[i].load(QString(":/picture/player/rolling/%1.png").arg(i + 1));
        rightRolling[i] = leftRolling[i].transformed(QTransform().scale(-1, 1));
    }
    for(int i = 0; i < 4; i++)
    {
        leftCutting[i].load(QString(":/picture/player/cutting/%1.png").arg(i + 1));
        rightCutting[i] = leftCutting[i].transformed(QTransform().scale(-1, 1));
    }
    for(int i = 0; i < 4; i++)
    {
        leftDigging[i].load(QString(":/picture/player/digging/%1.png").arg(i + 1));
        rightDigging[i] = leftDigging[i].transformed(QTransform().scale(-1, 1));
    }
}


bool Player::isDetectable(int gridX, int gridY)
{
    QPointF gridcenter = gMap->gridToPixel(gridX, gridY);
	QPointF playercenter = getCenterPos();
	int dx = gridcenter.x() - playercenter.x();
	int dy = gridcenter.y() - playercenter.y();
	double distance = qSqrt(dx * dx + dy * dy);
    return distance <= detectRange;
}

// 暂停玩家的所有活动
void Player::pause()
{
    // 暂停所有定时器
    moveTimer.stop();
    picTimer.stop();
    findTimer.stop();
    // 不需要停止rollTimer，因为它只在翻滚时运行，状态会保持
}

// 恢复玩家的所有活动
void Player::resume()
{
    // 恢复所有定时器
    moveTimer.start(POSITION_DELTA);
    picTimer.start(PICTURE_DELTA);
    findTimer.start(FIND_TARGET_INTERVAL);
    // rollTimer会在需要时自动启动
}



