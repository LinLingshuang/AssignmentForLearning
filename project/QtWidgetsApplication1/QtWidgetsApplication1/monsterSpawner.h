/**
 * @file monsterSpawner.h
 * @brief 怪物生成器类头文件
 * 定义了MonsterSpawnerTower类，负责游戏中怪物的生成、波次管理和怪物状态更新
 */
#ifndef MONSTERSPAWNER_H
#define MONSTERSPAWNER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <vector>
#include "utils.h"

// 前向声明
class Monster;

/**
 * @brief 怪物生成器类
 * 继承自QObject和QGraphicsPixmapItem，负责游戏中怪物的生成、波次管理和怪物状态更新
 * 该类是游戏中怪物系统的核心，控制怪物的生成节奏、波次难度和怪物行为
 */
class MonsterSpawnerTower : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    /**
     * @brief 构造函数
     * 创建怪物生成器实例
     * 
     * @param parent 父图形项，默认为nullptr
     */
    MonsterSpawnerTower(QGraphicsItem* parent = nullptr);
    
    /**
     * @brief 析构函数
     * 清理怪物生成器占用的资源
     */
    ~MonsterSpawnerTower();

    /**
     * @brief 开始生成怪物
     * 启动生成计时器，开始按照当前波次配置生成怪物
     */
    void startSpawning();      
    
    /**
     * @brief 停止生成怪物
     * 停止生成计时器，不再生成新怪物
     */
    void stopSpawning();       
    
    /**
     * @brief 暂停所有怪物相关定时器
     * 暂停怪物生成、移动、动画和攻击的所有定时器
     */
    void pause();
    
    /**
     * @brief 恢复所有怪物相关定时器
     * 恢复怪物生成、移动、动画和攻击的所有定时器
     */
    void resume();

    /**
     * @brief 获取当前波数
     * 
     * @return 当前波数
     */
    int getCurrentWave() const { return currentWave; }
    
    /**
     * @brief 设置当前波数
     * 用于从存档中恢复游戏状态
     * 
     * @param wave 要设置的波数
     */
    void setCurrentWave(int wave);
    
    /**
     * @brief 清理死亡怪物
     * 删除所有生命值为0的怪物，释放资源并从容器中移除
     */
    //void cleanupMonsters();      
    

    // 全部怪物（真正保存的容器）
    std::vector<Monster*> monsters;                    ///< 所有活跃怪物的列表
    // 网格：先 X 再 Y，下标范围 [0, MAPWIDTH/TILESIZE) × [0, MAPHEIGHT/TILESIZE)
    std::vector<Monster*> grid[MAPWIDTH / TILESIZE][MAPHEIGHT / TILESIZE];

signals:
    /**
     * @brief 怪物被生成信号
     * 当新怪物生成时发出，用于在Game类中将怪物添加到场景
     * 
     * @param monster 新生成的怪物指针
     */
    void monsterSpawned(Monster* monster);
    
    /**
     * @brief 波数更新信号
     * 当波数变化时发出，用于更新UI显示
     * 
     * @param wave 新的波数
     */
    void waveChanged(int wave);

   

private slots:
    /**
     * @brief 生成单个怪物槽函数
     * 按照当前波次配置生成一个怪物，并添加到怪物列表和格子中
     */
    void spawnMonster();       
    
    /**
     * @brief 更新波数和难度槽函数
     * 当一波怪物生成完成后，更新波数并增加游戏难度
     */
    void updateWave();         
    
    /**
     * @brief 更新所有怪物位置槽函数
     * 每帧调用，更新所有怪物的位置和移动逻辑
     */
    void updateAllMonstersPosition();     
    
    /**
     * @brief 更新所有怪物动画帧槽函数
     * 定期调用，更新所有怪物的动画帧
     */
    void updateAllAnimationFrame();
    
    /**
     * @brief 执行所有怪物攻击槽函数
     * 定期调用，检查并执行所有怪物的攻击逻辑
     */
    void performAllAttack();

    void onMonsterDied(MonsterType type);//不知道为什么待整合项目里这个函数被注释了，需要ai检查一下

private:
    /**
     * @brief 初始化生成器
     * 设置初始波数、生成间隔等参数
     */
    void initialize();         
    
    /**
     * @brief 将怪物添加到格子中
     * 根据怪物位置将其添加到对应的格子中，用于优化碰撞检测
     * 
     * @param m 要添加的怪物指针
     */
    void addMonsterToGrid(Monster* m);
    
    /**
     * @brief 从格子中移除怪物
     * 当怪物移动或死亡时，将其从格子中移除
     * 
     * @param m 要移除的怪物指针
     */
    void removeMonsterFromGrid(Monster* m);
    
    /**
     * @brief 初始化计时器
     * 设置所有需要的计时器及其间隔
     */
    void initializeTimers();

    // 生成器属性
    int currentWave;           ///< 当前波数
    int monstersInCurrentWave; ///< 当前波已生成的怪物数
    int totalMonstersInWave;   ///< 当前波总怪物数

    // 待删除怪物列表
    std::vector<Monster*> toDeleteMonsters; // 等待删除的怪物列表

    // 难度参数
    float spawnInterval;       ///< 生成间隔（秒）
    float waveInterval;        ///< 波间隔（秒）

    // 计时器
    QTimer* spawnTimer;        ///< 生成计时器，控制怪物生成节奏
    QTimer* waveTimer;         ///< 波更新计时器，控制波数变化
    QTimer* animationTimer;    ///< 动画更新计时器，控制怪物动画帧切换
    QTimer* moveTimer;         ///< 位置移动计时器，控制怪物位置更新
    QTimer* attackTimer;       ///< 攻击计时器，控制怪物攻击频率
};

#endif // MONSTERSPAWNER_H

