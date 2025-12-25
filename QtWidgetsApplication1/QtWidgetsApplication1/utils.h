#ifndef UTILS_H
#define UTILS_H

/**
 * @file utils.h
 * @brief 游戏全局常量定义文件
 * 该文件定义了游戏中使用的所有全局常量，包括界面尺寸、地图参数、UI元素、玩家属性、怪物属性等
 */

// ===========================================
// 游戏界面常量
// ===========================================
#define WIDTH 1152       ///< 游戏主窗口宽度
#define HEIGHT 648       ///< 游戏主窗口高度

// ===========================================
// 地图常量
// ===========================================
#define TILESIZE 32      ///< 地图瓦片大小（像素）
#define WIDTHNUM 33      ///< 地图横向瓦片数量
#define HEIGHTNUM 16     ///< 地图纵向瓦片数量
#define MAPWIDTH 2880    ///< 地图总宽度（像素）
#define MAPHEIGHT 1920   ///< 地图总高度（像素）

// ===========================================
// 按钮常量
// ===========================================
#define BTNWIDTH 107     ///< 按钮宽度（像素）
#define BTNHEIGHT 107    ///< 按钮高度（像素）

// ===========================================
// UI常量 - 初始值
// ===========================================
#define INITCAMPHEALTH 80   ///< 初始营地生命值
#define INITPLAYERHEALTH 20 ///< 初始玩家生命值
#define INITWAVE 0          ///< 初始波数
#define INITWOOD 25           ///< 初始木材数量
#define INITSTONE 25          ///< 初始石头数量
#define INITBRONZE 10         ///< 初始青铜数量
#define INITSILVER 10         ///< 初始白银数量
#define INITGOLD 10           ///< 初始黄金数量
#define INITRESIN 0





// ===========================================
// UI常量 - 状态条尺寸
// ===========================================
#define UIWIDTH (6 * TILESIZE + BTNHEIGHT) ///< 状态条宽度
#define UIHEIGHT (8 * TILESIZE)            ///< 状态条高度
#define DIGIT 2                             ///< 数字位数
#define BARNUM 8                            ///< 状态条数量

// ===========================================
// UI常量 - 数值和状态图标尺寸
// ===========================================
#define NUMWIDTH 27    ///< 数字宽度（像素）
#define NUMHEIGHT 46   ///< 数字高度（像素）
#define STATUWIDTH 48  ///< 状态图标宽度（像素）
#define STATUHEIGHT 48 ///< 状态图标高度（像素）

// ===========================================
// UI常量 - 位置偏移
// ===========================================
#define STATUX 24    ///< 状态图标X坐标偏移
#define STATUY 16    ///< 状态图标Y坐标偏移
#define GAPY 54      ///< 状态条之间的垂直间距

#define NUMX 90      ///< 数字X坐标偏移
#define NUMY 20      ///< 数字Y坐标偏移
#define NUMGAPX 31   ///< 数字之间的水平间距

// ===========================================
// 图层Z轴值（用于决定绘制顺序）
// ===========================================
#define MAPZVALUE -10    ///< 地图图层Z值
#define TOWERZVALUE 10   ///< 炮塔图层Z值
#define BULLETZVALUE 10  ///< 子弹图层Z值
#define MONSTERZVALUE 5  ///< 怪物图层Z值
#define PLAYERZVALUE 5   ///< 玩家图层Z值
#define RESOURCEZVALUE -5 ///< 资源图层Z值
#define MARKERZVALUE 0
#define PREVIEWTOWERZVALUE 1000

// ===========================================
// 玩家常量
// ===========================================
#define PLAYERWIDTH TILESIZE   ///< 玩家宽度（像素）
#define PLAYERHEIGHT TILESIZE  ///< 玩家高度（像素）
#define WALKSPEED 150.0      ///< 玩家移动速度（降低，原150.0）
#define ROLLSPEED 200.0        ///< 玩家翻滚速度（降低，原200.0）

// ===========================================
// 怪物常量
// ===========================================
#define MONSTER_ATTACK_INTERVAL 3000 ///< 怪物攻击间隔（毫秒），增加到3000ms，减慢攻击速度

// monster1 常量
#define MONSTER1_HEALTH 100.0 ///< 怪物1生命值
#define MONSTER1_SPEED 100.0  ///< 怪物1移动速度（降低，原150.0）
#define MONSTER1_GOLD 10      ///< 击败怪物1获得的金钱
#define MONSTER1_DAMAGE 1     ///< 怪物1攻击力

// monster2 常量
#define MONSTER2_HEALTH 200.0 ///< 怪物2生命值
#define MONSTER2_SPEED 30.0   ///< 怪物2移动速度（降低，原40.0）
#define MONSTER2_GOLD 20      ///< 击败怪物2获得的金钱
#define MONSTER2_DAMAGE 2     ///< 怪物2攻击力

// monster3 常量
#define MONSTER3_HEALTH 400.0 ///< 怪物3生命值
#define MONSTER3_SPEED 15.0   ///< 怪物3移动速度（降低，原20.0）
#define MONSTER3_GOLD 40      ///< 击败怪物3获得的金钱
#define MONSTER3_DAMAGE 3     ///< 怪物3攻击力

// slime
#define SLIME_HEALTH 800.0
#define SLIME_SPEED 10.0  ///< 史莱姆移动速度（降低，原15.0）
#define SLIME_GOLD 60
#define SLIME_DAMAGE 3

//bat
#define BAT_HEALTH 400.0
#define BAT_SPEED 35.0  ///< 蝙蝠移动速度（降低，原50.0）
#define BAT_GOLD 40
#define BAT_DAMAGE 3



// ===========================================
// 怪物管理器常量
// ===========================================
#define SPAWNINTERVAL 3.0   ///< 怪物生成间隔（秒）
#define WAVEINTERVAL 30.0   ///< 波次间隔（秒）

// ===========================================
// 炮塔常量
// ===========================================

// tower1 常量
#define TOWER1_MAHEALTH 100         ///< 炮塔1最大生命值
#define TOWER1_BUILCOST 50          ///< 炮塔1建造成本
#define TOWER1_ATTACKRANGE 150      ///< 炮塔1攻击范围
#define TOWER1_ATTACKINTERVAL 500   ///< 炮塔1攻击间隔（毫秒）
#define TOWER1_BULLET_DAMAGE 8
#define TOWER1_BULLET_SPEED 15
#define TOWER1_BUILD_WOOD 3
#define TOWER1_BUILD_STONE 3


// tower2 常量
#define TOWER2_MAHEALTH 100         ///< 炮塔2最大生命值
#define TOWER2_BUILCOST 50          ///< 炮塔2建造成本
#define TOWER2_ATTACKRANGE 150      ///< 炮塔2攻击范围
#define TOWER2_ATTACKINTERVAL 1500   ///< 炮塔2攻击间隔（毫秒）
#define TOWER2_BULLET_DAMAGE 12
#define TOWER2_BULLET_SPEED 10
#define TOWER2_BUILD_WOOD 5
#define TOWER2_BUILD_STONE 5


// tower3 常量
#define TOWER3_MAHEALTH 100         ///< 炮塔3最大生命值
#define TOWER3_BUILCOST 50          ///< 炮塔3建造成本
#define TOWER3_ATTACKRANGE 300      ///< 炮塔3攻击范围
#define TOWER3_ATTACKINTERVAL 3000   ///< 炮塔3攻击间隔（毫秒）
#define TOWER3_BULLET_DAMAGE 30
#define TOWER3_BULLET_SPEED 5
#define OUTER_DIVIDE_INNER 3
#define TOWER3_BUILD_WOOD 8
#define TOWER3_BUILD_STONE 8


// 计时器——炮塔
#define TRACK_TIMER_INTERVAL 30
#define FRAME_TIMER_INTERVAL 100


// ---------------------------
// 子弹配置 (Bullet Configuration)
// ---------------------------

// 子弹
#define BULLET_TOLERANCE 5.0
#define BULLET_SPEED_DEFAULT 8.0f
#define BULLET_DAMAGE_DEFAULT 5.0f

#define BULLET_PICTURE_WIDTH 25
#define BULLET_PICTURE_HEIGHT 20

// 计时器——子弹
#define UPDATE_INTERVAL_MS 16
#define BULLET_FRAME_DELAY 25



// ===========================================
// 计时器常量 - 玩家相关
// ===========================================
#define POSITION_DELTA 10   //玩家位置更新间隔 10 单位：ms（减慢位置更新，原8）
#define PICTURE_DELTA 8    //玩家动画更新间隔 8 单位：ms（加快动画更新，原10）
#define WALK_FRAME_INTERVAL 60  // 行走60ms 一帧（加快移动动作变化，原80）
#define ROLL_FRAME_INTERVAL 40   // 滑行40ms 一帧（加快翻滚动作变化，原50）
#define CUT_FRAME_INTERVAL 150  //砍树150ms 一帧（减慢采集动作，原100）
#define DIG_FRAME_INTERVAL 150  //采石150ms 一帧（减慢采集动作，原100）
#define ROLLTIMES 1.5f  //每次按shift键人物翻滚效果圈数,可以控制滑行时间1.5
#define FIND_TARGET_INTERVAL 100

// ===========================================
// 计时器常量 - 怪物相关
// ===========================================
#define MONSTERDELTA 200  ///< 怪物状态更新间隔（毫秒）200（减慢怪物动画变化，原150）
#define MONSTERMOVE 25    ///< 怪物移动更新间隔（毫秒）25（减慢怪物移动更新，原20）
#define ATTACKDELAY 2500  ///< 攻击延迟（毫秒）2500（增加攻击延迟，原2000）
#define ATTACKDELTA 150   ///< 攻击动画更新间隔（毫秒）150（减慢攻击动画，原100）

// ===========================================
// 资源系统常量
// ===========================================
#define BIG_STONE_TIME 60  ///< 大石头重生时间（秒）
#define TREE_TIME 40       ///< 树木重生时间（秒）

// ---------------------------
// 枚举定义 (Enum Definitions)
// ---------------------------

// 格子状态枚举
enum TileState {    // 描述格子的特殊性质
    TILE_ELSE = 0,
    TILE_BLOCKED = 1,   // 障碍物
    TILE_BUILDABLE = 2, // 可建造
    TILE_LADDER = 3,    // 梯子或台阶
    TILE_START = 4,     // 怪物起点
    TILE_END = 5        // 怪物终点
};

// 图层枚举
enum TileLayer {
    TILE_FIRST = 3,     // 第一高，雪山 山
    TILE_SECOND = 2,    // 第二高，草地 沙漠 苔原
    TILE_THIRD = 1,     // 第三高，沼泽 水池
    TILE_FUORTH = 0,    // 第四高，酸液
};

enum StartPoint {
    GRASS,
    SWAMP,
    SNOW,
    SDESERT
};

enum class MonsterType {
    MONSTER1,   ///< 怪物类型1
    MONSTER2,   ///< 怪物类型2
    MONSTER3,   ///< 怪物类型3
    SLIME,
    BAT_TO_PLAYER,
    BAT_TO_CAMP
};

enum class MonsterState {
    MOVING,
    ATTACKING,
    DYING,
    DEAD
};

enum class PlayerState
{
    WALKING,
    ROLLING,
    CUTTING,
    DIGGING
};

enum UiResource
{
    CAMPHEALTH = 0,
    PLAYERHEALTH = 1,
    WAVE = 2,
    WOOD = 3,
    BRONZE = 4,
    SILVER = 5,
    GOLD = 6,
    STONE = 7,
};

enum class ResourceType
{
    GRASS_STONE,
    SNOW_STONE,
    SWAMP_STONE,
    GRASS_TREE,
    SWAMP_TREE
};

enum class TowerType {
    TOWER1,
    TOWER2,
    TOWER3,
    TOWER_NONE,
};

#endif // UTILS_H
