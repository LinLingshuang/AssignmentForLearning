#ifndef ENCYCLOPEDIADATA_H
#define ENCYCLOPEDIADATA_H
#pragma once
#include <QString>
#include <QPixmap>
#include <QStringList>
#include <QVector>

// 怪物图鉴信息
struct MonsterEncyclopediaInfo {
    QString name;
    QString description;
    int health;
    int speed;
    int goldReward;
    int attackDamage;
    QStringList imagePaths;  // 改为QStringList以支持多帧图片
    QString specialAbility;
    int frameCount;          // 添加帧数
    int frameDelay;          // 添加帧延迟
};

// 炮塔图鉴信息
struct TowerEncyclopediaInfo {
    QString name;
    QString description;
    int health;
    int buildCost;
    int attackRange;
    int attackInterval;
    int bulletDamage;
    int bulletSpeed;
    QString imagePath;
    QString specialAbility;
    // 移除rotationAngle字段，因为不需要旋转
};

class EncyclopediaData {
public:
    static MonsterEncyclopediaInfo getMonsterInfo(int monsterType);
    static TowerEncyclopediaInfo getTowerInfo(int towerType);

    static QVector<MonsterEncyclopediaInfo> getAllMonsterInfos();
    static QVector<TowerEncyclopediaInfo> getAllTowerInfos();
};
#endif // ENCYCLOPEDIADATA_H
