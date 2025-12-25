/**
 * @file global.h
 * @brief 全局变量声明
 * 定义了游戏中需要在多个文件中共享的全局变量
 */
#ifndef GLOBALS_H
#define GLOBALS_H

#include "map.h"       // 地图类头文件
#include "monsterSpawner.h" // 怪物生成器头文件
#include "monster.h"   // 怪物类头文件
#include "player.h"    // 玩家类头文件
#include "resourcemanager.h" // 资源管理器头文件
#include "buildmanager.h"
#include "explorationmarker.h" // 探索标记头文件
#include "audiomanager.h"

/**
 * @brief 全局地图指针
 * 指向游戏中的主地图实例，用于在多个文件中访问地图信息
 */
extern Map* gMap;   

/**
 * @brief 怪物生成器指针
 * 指向游戏中的怪物生成器实例，用于控制怪物的生成
 */
extern MonsterSpawnerTower* monsterSpawner; 

/**
 * @brief 资源管理器指针
 * 指向游戏中的资源管理器实例，用于管理游戏中的资源
 */
extern ResourceManager* resourceManager;

/**
 * @brief 玩家指针
 * 指向游戏中的玩家实例，用于控制玩家角色和访问玩家状态
 */
extern Player * me;

extern BuildManager* buildManager;
extern ExplorationMarker* explorationmarker;  // 探索标记指针
extern AudioPlayer* m_audioPlayer;
#endif
