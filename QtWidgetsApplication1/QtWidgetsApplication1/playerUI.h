/**
 * @file playerUI.h
 * @brief 玩家UI类头文件
 * 定义了PlayerUI类，用于显示玩家的各项状态信息
 */
#ifndef PLAYERUI_H
#define PLAYERUI_H

#include <QWidget>
#include <vector>
#include <qlabel.h>
#include <qpixmap.h>
#include "resource.h"
#include <QObject>                  ///< 包含Qt对象类
#include "utils.h"


/**
 * @brief 玩家UI类
 * 继承自QWidget，用于显示玩家的各项状态信息，如金钱、生命值、资源等
 */
class PlayerUI : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief 构造函数
     * 创建玩家UI实例
     * 
     * @param parent 父窗口指针
     */
    explicit PlayerUI(QWidget *parent = nullptr);
    
    /**
     * @brief 获取UI宽度
     * 
     * @return UI的宽度
     */
    int getWidth()  {return width;}
    
    /**
     * @brief 获取UI高度
     * 
     * @return UI的高度
     */
    int getHeight()  {return height;}
    
    /**
     * @brief 获取当前波数
     * 
     * @return 当前波数
     */
    int getWave() const {return wave;}
    
    /**
     * @brief 获取木材资源数量
     * 
     * @return 木材资源数量
     */
    int getWood() const {return wood;}
    
    /**
     * @brief 获取石材资源数量
     * 
     * @return 石材资源数量
     */
    int getStone() const {return stone;}
    
    /**
     * @brief 获取金币资源数量
     * 
     * @return 金币资源数量
     */
    int getGold() const {return gold;}
    
    /**
     * @brief 获取帐篷（玩家基地）血量
     * 
     * @return 帐篷血量
     */
    int getCampHealth() const {return campHealth;}
    
    /**
     * @brief 设置木材资源数量
     * 
     * @param wood 木材资源数量
     */
    void setWood(int wood);
    
    /**
     * @brief 设置石材资源数量
     * 
     * @param stone 石材资源数量
     */
    void setStone(int stone);
    
    /**
     * @brief 设置金币资源数量
     * 
     * @param gold 金币资源数量
     */
    void setGold(int gold);
    
    /**
     * @brief 设置帐篷（玩家基地）血量
     * 
     * @param campHealth 帐篷血量
     */
    void setCampHealth(int campHealth);
    
    /**
     * @brief 获取指定资源的数量
     * 
     * @param resource 资源类型
     * @return 资源数量
     */
    int getNum(UiResource resource);
    
    /**
     * @brief 将整数转换为数字向量
     * 
     * @param value 要转换的整数
     * @return 数字向量，每个元素是整数的一位数字
     */
    std::vector<int> itov(int value);
    
    /**
     * @brief 将数字向量转换为整数
     * 
     * @param out 数字向量
     * @return 转换后的整数
     */
    int vtoi(const std::vector<int> out);
    
    /**
     * @brief 增加指定状态的值
     * 
     * @param value 要增加的值
     * @param index 状态的索引
     */
     void add(int value, UiResource index);
    
    /**
     * @brief 减少指定状态的值
     * 
     * @param value 要减少的值
     * @param index 状态的索引
     * @return 是否减少成功（资源是否足够）
     */
    bool sub(int value, UiResource index);
    
    /**
     * @brief 初始化状态栏
     * 
     * @param numWid 数字图片宽度
     * @param numHei 数字图片高度
     * @param statuWid 状态栏头宽度
     * @param statuHei 状态栏头高度
     */
    void initStatusBar(int numWid, int numHei, int statuWid, int statuHei);
    
    /**
     * @brief 加载状态栏图片
     */
    void loadStatuTextures();
    
    /**
     * @brief 加载数字图片
     */
    void loadNumTextures();
    
    /**
     * @brief 更新单个状态栏
     * 
     * @param index 状态栏的索引
     */
    void updateSglBar(UiResource index );

    /**
     * @brief 更新整个UI界面
     */
    void updateUI();
    
    /**
     * @brief 加载UI边框
     */
    void loadFrame();

public slots:
    /**
     * @brief 收集资源
     * 当玩家收集资源时调用，根据资源类型随机给予奖励
     * @param type 资源类型
     */
    void collectResource(ResourceType type);

private:
    int statuBarNum;  // 状态栏数目

    int campHealth;   // 基地生命
    int playerHealth; // 玩家生命
    int wave;         // 波次
    int wood;         // 木材资源
    int stone;        // 石材资源
    int bronze;       // 青铜资源
    int silver;       // 银资源
    int gold;         // 金资源
    int resin;        //树脂数量

    int width;        // UI宽度
    int height;       // UI高度

    int maxDig;       // 存储最高位数
    int maxNum;       // 存储最大数值

    std::vector<std::vector<QLabel*>> statusBar; // 存储状态栏标签
    QPixmap picFrame;  // 存储边框图
    QLabel* frame;     // 存储边框标签
    int numWidth;      // 数字图片宽度
    int numHeight;     // 数字图片高度
    int statuWidth;    // 状态栏头宽度
    int statuHeight;   // 状态栏头高度
    std::vector<QPixmap> numTextures;   // 存储数字图片
    std::vector<QPixmap> statuTextures; // 存储状态栏头图片

    signals:
        /**
         * @brief 游戏结束信号
         * 当玩家或基地生命值为0时发出
         */
        void gameOver();
        
        /**
         * @brief 基地受伤信号
         * 当基地受到伤害时发出
         */
        void campHurted();
        
        /**
         * @brief 玩家受伤信号
         * 当玩家受到伤害时发出
         */
        void playerHurted();
};

#endif // PLAYERUI_H
