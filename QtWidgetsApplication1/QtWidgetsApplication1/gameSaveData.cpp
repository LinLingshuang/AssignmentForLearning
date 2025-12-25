#include "gameSaveData.h"
#include "tower.h"
#include "gameWidget.h"
#include "player.h"
#include "playerUI.h"
#include <QDataStream>

/**
 * @brief 从Tower对象构造TowerData
 * 
 * @param tower 指向Tower对象的指针
 */
TowerData::TowerData(const Tower* tower) {
    if (!tower) {
        return;
    }
    
    towerType = static_cast<int>(tower->getTowerType());
    // 获取炮塔在网格中的位置
    Vector2 pos = tower->getGridPosition();
    gridPosition = QPoint(pos.x, pos.y);
    level = tower->getLevel();
    health = tower->getHealth();
    attackRange = 100; // 默认攻击范围，需要根据实际情况调整
}

/**
 * @brief 从Player对象构造PlayerData
 * 
 * @param player 指向Player对象的指针
 */
PlayerData::PlayerData(const Player* player) {
    if (!player) {
        return;
    }
    
    position = player->pos();
    health = 100; // 默认玩家生命值，需要根据实际情况调整
    // 注意：资源信息实际上存储在PlayerUI类中
    wood = 0; // 初始化为0，后续会从PlayerUI中获取
    stone = 0;
    gold = 0;
}

/**
 * @brief 从Player和PlayerUI对象构造PlayerData
 * 
 * @param player 指向Player对象的指针
 * @param playerUI 指向PlayerUI对象的指针
 */
PlayerData::PlayerData(const Player* player, const PlayerUI* playerUI) {
    if (!player) {
        return;
    }
    
    position = player->pos();
    health = 100; // 默认玩家生命值，需要根据实际情况调整
    
    if (playerUI) {
        wood = playerUI->getWood();
        stone = playerUI->getStone();
        gold = playerUI->getGold();
    } else {
        wood = 0;
        stone = 0;
        gold = 0;
    }
}

/**
 * @brief 从游戏对象构造GameSaveData
 * 
 * @param name 存档名称
 * @param game 指向Game对象的指针
 */
GameSaveData::GameSaveData(const QString& name, const Game* game) {
    if (!game) {
        return;
    }
    
    saveName = name;
    totalGameTime = game->getTotalGameTime();
    
    // 获取当前波数
    if (game->getMonsterSpawner()) {
        currentWave = game->getMonsterSpawner()->getCurrentWave();
    }
    
    // 获取帐篷血量
    if (game->getPlayerUI()) {
        campHealth = game->getPlayerUI()->getCampHealth();
    }
    
    // 获取玩家数据
    if (game->getPlayer() && game->getPlayerUI()) {
        player = PlayerData(game->getPlayer(), game->getPlayerUI());
    }
    
    // 获取所有炮塔数据
    towers.clear();
    if (game->getScene()) {
        QList<QGraphicsItem*> items = game->getScene()->items();
        for (QGraphicsItem* item : items) {
            Tower* tower = dynamic_cast<Tower*>(item);
            if (tower) {
                towers.append(TowerData(tower));
            }
        }
    }
}

// QDataStream 序列化和反序列化函数实现

QDataStream& operator<<(QDataStream& out, const TowerData& towerData) {
    out << towerData.towerType;
    out << towerData.gridPosition;
    out << towerData.level;
    out << towerData.health;
    out << towerData.attackRange;
    return out;
}

QDataStream& operator>>(QDataStream& in, TowerData& towerData) {
    in >> towerData.towerType;
    in >> towerData.gridPosition;
    in >> towerData.level;
    in >> towerData.health;
    in >> towerData.attackRange;
    return in;
}

QDataStream& operator<<(QDataStream& out, const PlayerData& playerData) {
    out << playerData.position;
    out << playerData.health;
    out << playerData.wood;
    out << playerData.stone;
    out << playerData.gold;
    return out;
}

QDataStream& operator>>(QDataStream& in, PlayerData& playerData) {
    in >> playerData.position;
    in >> playerData.health;
    in >> playerData.wood;
    in >> playerData.stone;
    in >> playerData.gold;
    return in;
}

QDataStream& operator<<(QDataStream& out, const GameSaveData& gameData) {
    out << gameData.saveName;
    out << gameData.totalGameTime;
    out << gameData.currentWave;
    out << gameData.campHealth;
    out << gameData.player;
    out << gameData.towers;
    return out;
}

QDataStream& operator>>(QDataStream& in, GameSaveData& gameData) {
    in >> gameData.saveName;
    in >> gameData.totalGameTime;
    in >> gameData.currentWave;
    in >> gameData.campHealth;
    in >> gameData.player;
    in >> gameData.towers;
    return in;
}
