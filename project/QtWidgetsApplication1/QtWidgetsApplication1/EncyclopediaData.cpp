#include "EncyclopediaData.h"
#include "utils.h"
MonsterEncyclopediaInfo EncyclopediaData::getMonsterInfo(int monsterType) {
    MonsterEncyclopediaInfo info;

    switch(monsterType) {
    case 1: // MONSTER1
        info.name = "普通怪物";
        info.description = "基础怪物类型，移动速度中等，生命值较低";
        info.health = MONSTER1_HEALTH;
        info.speed = MONSTER1_SPEED;
        info.goldReward =MONSTER1_GOLD ;
        info.attackDamage = MONSTER1_DAMAGE;
        // 添加多帧图片路径
        info.imagePaths << ":/picture/monster1/(1).png"
                        << ":/picture/monster1/(2).png"
                        << ":/picture/monster1/(3).png";
        info.specialAbility = "无特殊能力";
        info.frameCount = 3;
        info.frameDelay = 200; // 200毫秒切换一帧
        break;

    case 2: // MONSTER2
        info.name = "快速怪物";
        info.description = "移动速度较快，但生命值较低";
        info.health = MONSTER2_HEALTH;
        info.speed =  MONSTER2_SPEED;
        info.goldReward = MONSTER2_GOLD;
        info.attackDamage = MONSTER2_DAMAGE;
        info.imagePaths << ":/picture/monster2/(1).png"
                        << ":/picture/monster2/(2).png"
                        << ":/picture/monster2/(3).png";
        info.specialAbility = "移动速度快";
        info.frameCount = 3;
        info.frameDelay = 150; // 更快的帧切换
        break;

    case 3: // MONSTER3
        info.name = "重型怪物";
        info.description = "生命值较高，但移动速度较慢";
        info.health =MONSTER3_HEALTH ;
        info.speed =MONSTER3_SPEED ;
        info.goldReward = MONSTER3_GOLD;
        info.attackDamage =MONSTER2_DAMAGE ;
        info.imagePaths << ":/picture/monster3/(1).png"
                        << ":/picture/monster3/(2).png"
                        << ":/picture/monster3/(3).png";
        info.specialAbility = "高生命值";
        info.frameCount = 3;
        info.frameDelay = 300; // 更慢的帧切换
        break;

    case 4: // MONSTER4
        info.name = "史莱姆";
        info.description = "具有魔法抗性的怪物，对魔法攻击有减免";
        info.health = SLIME_HEALTH;
        info.speed = SLIME_SPEED ;
        info.goldReward =SLIME_GOLD ;
        info.attackDamage =SLIME_GOLD ;
        info.imagePaths << ":/picture/slime/(1).png"
                        << ":/picture/slime/(2).png"
                        << ":/picture/slime/(3).png";
        info.specialAbility = "魔法抗性";
        info.frameCount = 3;
        info.frameDelay = 250;
        break;

    // 新增怪物5：飞行怪物
    case 5: // MONSTER5
        info.name = "紫蝙蝠";
        info.description = "能够在空中飞行的怪物，免疫地面攻击";
        info.health = BAT_HEALTH  ;
        info.speed = BAT_SPEED;
        info.goldReward = BAT_GOLD;
        info.attackDamage =BAT_DAMAGE ;
        info.imagePaths << ":/picture/bat/(1).png"
                        << ":/picture/bat/(2).png"
                        << ":/picture/bat/(3).png"
                        << ":/picture/bat/(4).png"; // 4帧飞行动画
        info.specialAbility = "飞行单位，对准玩家攻击";
        info.frameCount = 4;
        info.frameDelay = 100; // 快速扇动翅膀
        break;
    case 6: // MONSTER6
        info.name = "绿蝙蝠";
        info.description = "能够在空中飞行的怪物，免疫地面攻击";
        info.health = BAT_HEALTH  ;
        info.speed = BAT_SPEED;
        info.goldReward = BAT_GOLD;
        info.attackDamage =BAT_DAMAGE ;
        info.imagePaths << ":/picture/monster5/(13).png"
                        << ":/picture/monster5/(14).png"
                        << ":/picture/monster5/(15).png"
                        << ":/picture/monster5/(16).png"; // 4帧飞行动画
        info.specialAbility = "飞行单位，对准营地攻击";
        info.frameCount = 4;
        info.frameDelay = 100; // 快速扇动翅膀
        break;


    default:
        info.name = "未知怪物";
        info.description = "未知怪物类型";
        info.health = 0;
        info.speed = 0;
        info.goldReward = 0;
        info.attackDamage = 0;
        info.imagePaths.clear();
        info.specialAbility = "无";
        info.frameCount = 0;
        info.frameDelay = 0;
    }

    return info;
}

TowerEncyclopediaInfo EncyclopediaData::getTowerInfo(int towerType) {
    TowerEncyclopediaInfo info;

    switch(towerType) {
    case 1: // TOWER1
        info.name = "箭塔";
        info.description = "基础防御塔，攻击速度中等，伤害较低";
        info.health = 100;
        info.buildCost = 50;
        info.attackRange = 150;
        info.attackInterval = 1000;
        info.bulletDamage = 10;
        info.bulletSpeed = 8;
        info.imagePath = ":/picture/tower/preview_archer.png";
        info.specialAbility = "基础攻击";
        // 移除rotationAngle，不需要旋转
        break;

    case 2: // TOWER2
        info.name = "加农炮";
        info.description = "中级防御塔，攻击范围较大，伤害中等";
        info.health = 150;
        info.buildCost = 100;
        info.attackRange = 200;
        info.attackInterval = 1500;
        info.bulletDamage = 15;
        info.bulletSpeed = 10;
        info.imagePath = ":/picture/tower/preview_cannon.png";
        info.specialAbility = "魔法攻击";
        // 移除rotationAngle，不需要旋转
        break;

    case 3: // TOWER3
        info.name = "迫击炮";
        info.description = "高级防御塔，攻击力强，但攻击速度较慢";
        info.health = 200;
        info.buildCost = 200;
        info.attackRange = 180;
        info.attackInterval = 2000;
        info.bulletDamage = 20;
        info.bulletSpeed = 12;
        info.imagePath = ":/picture/tower/preview_mortar.png";
        info.specialAbility = "高伤害攻击";
        // 移除rotationAngle，不需要旋转
        break;

    default:
        info.name = "未知炮塔";
        info.description = "未知炮塔类型";
        info.health = 0;
        info.buildCost = 0;
        info.attackRange = 0;
        info.attackInterval = 0;
        info.bulletDamage = 0;
        info.bulletSpeed = 0;
        info.imagePath = "";
        info.specialAbility = "无";
    }

    return info;
}

QVector<MonsterEncyclopediaInfo> EncyclopediaData::getAllMonsterInfos() {
    QVector<MonsterEncyclopediaInfo> infos;
    for(int i = 1; i <= 6; i++) { // 修改为6，包含所有六种怪物
        infos.append(getMonsterInfo(i));
    }
    return infos;
}

QVector<TowerEncyclopediaInfo> EncyclopediaData::getAllTowerInfos() {
    QVector<TowerEncyclopediaInfo> infos;
    for(int i = 1; i <= 3; i++) {
        infos.append(getTowerInfo(i));
    }
    return infos;
}
