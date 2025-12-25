#include "areadamagebullet.h"
#include "monster.h"
#include "global.h"
#include "structVector.h" 
#include <cmath>
#include <QGraphicsPixmapItem>      ///< 包含Qt图形像素图项类
#include <QObject>                  ///< 包含Qt对象类
// 修正构造函数实现
AreaDamageBullet::AreaDamageBullet(const Vector2& startPos, 
                                   Monster* target, 
                                   TowerType towerType,
                                   int towerLevel, 
                                   float speed, 
                                   float damage,
                                   float radius, 
                                   QGraphicsItem* parent)
    : Bullet(startPos, target, towerType, towerLevel, speed, damage, parent), areaRadius_(radius)
{}

void AreaDamageBullet::takeDamage()
{   
    if (!target) {
        destroySelf();
        return;
    }

    const Vector2 explosionCenter = position_;
    const QVector<Monster*> monsters = findMonstersInArea(explosionCenter, areaRadius_);

    for (Monster* monster : monsters) {
        if (!monster || monster->isDead()) continue;

        float dist = explosionCenter.distanceTo(monster->getPosition());
        if (dist > areaRadius_) continue;

        float factor = 1.0f - dist / areaRadius_;
        factor = std::max(0.1f, factor);   // 最低 10%

        monster->takeDamage(damage_ * factor);
    }

    emit hit(damage_);
    destroySelf();
}

QVector<Monster*> AreaDamageBullet::findMonstersInArea(const Vector2& center, float radius)
{
    QVector<Monster*> result;
    if (!monsterSpawner || !gMap) return result;

    // 为了避免访问可能已悬空的 grid 单元，改为遍历 monsterSpawner->monsters 的副本
    std::vector<Monster*> all = monsterSpawner->monsters;
    for (Monster* m : all) {
        if (!m) continue;
        QPointer<Monster> safeM(m);
        if (!safeM) continue;
        if (safeM->isDead() || safeM->isDying()) continue;

        if (center.distanceTo(safeM->getPosition()) <= radius) {
            result.push_back(safeM);
        }
    }

    return result;
}
