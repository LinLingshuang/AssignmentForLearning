/**
 * @file global.cpp
 * @brief 全局变量定义文件
 * 包含了游戏中所有全局变量的实际定义和初始化
 */

#include "global.h"
#include "monster.h"

/**
 * @brief 全局地图指针定义
 * 指向游戏中的主地图实例，用于在多个文件中访问地图信息
 * 初始值为nullptr，将在游戏初始化时分配内存并赋值
 */
Map* gMap = nullptr;   // 全局地图指针，初始化为空指针

/**
 * @brief 怪物生成器指针定义
 * 指向游戏中的怪物生成器实例，用于控制怪物的生成、波次管理等
 * 初始值为nullptr，将在游戏初始化时分配内存并赋值
 */
MonsterSpawnerTower* monsterSpawner = nullptr; // 怪物生成器指针，初始化为空指针

/**
 * @brief 资源管理器指针定义
 * 指向游戏中的资源管理器实例，用于管理游戏中的资源
 * 初始值为nullptr，将在游戏初始化时分配内存并赋值
 */
ResourceManager* resourceManager = nullptr; // 资源管理器指针，初始化为空指针

/**
 * @brief 玩家指针定义
 * 指向游戏中的玩家实例，用于控制玩家角色和访问玩家状态
 * 初始值为nullptr，将在游戏初始化时分配内存并赋值
 */
Player * me = nullptr; // 玩家指针，初始化为空指针


BuildManager* buildManager;
ExplorationMarker* explorationmarker = nullptr; // 探索标记指针，初始化为空指针

AudioPlayer* m_audioPlayer;