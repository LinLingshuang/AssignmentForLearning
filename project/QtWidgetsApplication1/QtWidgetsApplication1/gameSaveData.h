#ifndef GAMESAVEDATA_H
#define GAMESAVEDATA_H

#include <QPointF>
#include <QPoint>
#include <QVector>
#include <QString>
#include <QDataStream>

// 前置声明
class Tower;
class Player;
class Game;
class PlayerUI;

/**
 * @brief 炮塔数据结构
 * 保存单个炮塔的信息
 */
struct TowerData {
    int towerType;       // 炮塔类型
    QPoint gridPosition; // 炮塔在网格中的位置
    int level;           // 炮塔等级
    int health;          // 炮塔生命值
    int attackRange;     // 攻击范围
    
    // 默认构造函数
    TowerData() : towerType(0), level(1), health(100), attackRange(100) {}
    
    // 从Tower对象构造
    TowerData(const Tower* tower);
};

/**
 * @brief 玩家数据结构
 * 保存玩家的信息
 */
struct PlayerData {
    QPointF position;    // 玩家位置
    int health;          // 玩家生命值
    int wood;            // 木材资源
    int stone;           // 石材资源
    int gold;            // 金币资源
    
    // 默认构造函数
    PlayerData() : health(100), wood(0), stone(0), gold(0) {}
    
    // 从Player对象构造
    PlayerData(const Player* player);
    
    // 从Player和PlayerUI对象构造
    PlayerData(const Player* player, const PlayerUI* playerUI);
};

/**
 * @brief 游戏状态数据结构
 * 保存完整的游戏状态信息
 */
struct GameSaveData {
    QString saveName;    // 存档名称
    int totalGameTime;   // 游戏总时长（秒）
    int currentWave;     // 当前怪物波数
    int campHealth;      // 帐篷（玩家基地）血量
    PlayerData player;   // 玩家数据
    QVector<TowerData> towers; // 所有炮塔数据
    
    // 默认构造函数
    GameSaveData() : totalGameTime(0), currentWave(0), campHealth(100) {}
    
    // 从游戏当前状态构造
    GameSaveData(const QString& name, const Game* game);
};

// QDataStream 序列化和反序列化函数
QDataStream& operator<<(QDataStream& out, const TowerData& towerData);
QDataStream& operator>>(QDataStream& in, TowerData& towerData);

QDataStream& operator<<(QDataStream& out, const PlayerData& playerData);
QDataStream& operator>>(QDataStream& in, PlayerData& playerData);

QDataStream& operator<<(QDataStream& out, const GameSaveData& gameData);
QDataStream& operator>>(QDataStream& in, GameSaveData& gameData);

#endif // GAMESAVEDATA_H