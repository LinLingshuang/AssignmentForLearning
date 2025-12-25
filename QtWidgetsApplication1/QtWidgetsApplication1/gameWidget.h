/**
 * @file gameWidght.h
 * @brief 游戏主界面类头文件
 * 定义了游戏的主界面类Game，包含游戏的核心逻辑和界面管理
 */
#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "towerButton.h"
#include "playerUI.h"
#include "settingsWidget.h"  // 包含设置结构体
#include "explorationmarker.h"  // 包含探索标记类
#include "pausedialog.h"  // 包含暂停对话框类
#include "global.h"
#include "playerbase.h"
#include "gameOverDialog.h"
#include <vector>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QTime>
#include "audiomanager.h"
namespace Ui {
    class Game;
}

/**
 * @brief 游戏主界面类
 * 负责管理游戏的核心逻辑、界面显示和用户交互
 */
class Game : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief 构造函数
     * 创建游戏主界面实例
     *
     * @param settings 游戏设置参数
     * @param parent 父窗口指针
     */
    explicit Game(const GameSettings& settings = GameSettings(), QWidget* parent = nullptr);

    /**
     * @brief 从存档文件加载游戏的构造函数
     * 根据存档文件创建并恢复游戏状态
     *
     * @param saveFileName 存档文件路径
     * @param settings 游戏设置参数
     * @param parent 父窗口指针
     */
    explicit Game(const QString& saveFileName, const GameSettings& settings, QWidget* parent = nullptr);

    /**
     * @brief 析构函数
     * 释放游戏资源
     */
    ~Game();

    /**
     * @brief 加载游戏状态
     * 从存档文件读取游戏状态并恢复
     *
     * @param saveFileName 存档文件路径
     * @return bool 如果加载成功返回true，否则返回false
     */
    bool loadGame(const QString& saveFileName);

    /**
     * @brief 键盘按键按下事件处理
     *
     * @param ev 键盘事件对象
     */
    void keyPressEvent(QKeyEvent* ev) override;

    /**
     * @brief 键盘按键释放事件处理
     *
     * @param ev 键盘事件对象
     */
    void keyReleaseEvent(QKeyEvent* ev) override;

    /**
     * @brief 事件过滤器
     * 用于拦截QGraphicsView的键盘事件并转发给Game widget
     *
     * @param obj 事件目标对象
     * @param event 事件对象
     * @return 如果事件已处理返回true，否则返回false
     */
    bool eventFilter(QObject* obj, QEvent* event) override;

    /**
     * @brief 获取游戏总时长
     *
     * @return 游戏总时长（秒）
     */
    int getTotalGameTime() const { return totalGameTime; }

    /**
     * @brief 获取怪物生成器
     *
     * @return 怪物生成器指针
     */
    MonsterSpawnerTower* getMonsterSpawner() const { return monsterSpawner; }

    /**
     * @brief 获取玩家对象
     *
     * @return 玩家对象指针
     */
    Player* getPlayer() const { return me; }

    /**
     * @brief 获取玩家UI对象
     *
     * @return 玩家UI对象指针
     */
    PlayerUI* getPlayerUI() const { return myUI; }

    /**
     * @brief 获取游戏场景
     *
     * @return 游戏场景指针
     */
    QGraphicsScene* getScene() const { return scene; }


private slots:
    /**
     * @brief 处理基地被攻击的槽函数
     * 当基地受到伤害时调用
     */
    void handleCampAttacked(int damage);

    /**
     * @brief 处理帐篷被摧毁的槽函数
     * 当帐篷被摧毁时调用，触发游戏失败
     */
    void handleTentDestroyed();

    /**
     * @brief 暂停按钮点击事件处理
     * 当用户点击暂停按钮时调用，暂停或继续游戏
     */
    void on_pauseButton_clicked();

    /**
     * @brief 保存按钮点击事件处理
     * 当用户点击保存按钮时调用，保存游戏进度
     */
    void on_saveButton_clicked();

    /**
     * @brief 处理保存并退出信号
     * 当用户在暂停对话框中点击保存并退出按钮时调用
     */
    void handleSaveAndExit();

    /**
     * @brief 处理继续游戏信号
     * 当用户在暂停对话框中点击继续按钮时调用
     */
    void handleContinueGame();

    /**
     * @brief 处理返回主菜单信号
     * 当用户在失败对话框中点击返回主菜单按钮时调用
     */
    void handleReturnToMenu();

    /**
     * @brief 处理退出游戏信号
     * 当用户在失败对话框中点击退出游戏按钮时调用
     */
    void handleExitGame();

private:
    Ui::Game* ui;                 // UI界面指针
    QGraphicsView* view;          // 游戏视图
    QGraphicsScene* scene;        // 游戏场景
    PauseDialog* pauseDialog;     // 暂停对话框指针
    QPushButton* pauseButton;     // 暂停按钮

    int width;                    // 游戏宽度
    int height;                   // 游戏高度

    int towerNum;                 // 炮塔种类数
    std::vector<TowerButton*> tower;   // 炮塔按钮列表
    PlayerUI* myUI;               // 玩家UI界面
    void updateBtn();

    PlayerBase* playerBase;

    bool handleMouseMove(QMouseEvent* event);
    bool handleMousePress(QMouseEvent* event);
    bool handleMouseDoubleClick(QMouseEvent* event);
    void handleTowerUpgrade(Tower* tower);

    void clearTowerSelection();
    void selectTower(Tower* tower);

    QTimer* viewTimer;           // 视图更新定时器
    bool uiVisible;               // UI是否可见
    bool buttonVisible;           // 按钮是否可见
    bool isPaused;                // 游戏是否暂停

    GameSettings gameSettings;    // 游戏设置参数

    ExplorationMarker* explorationmarker;  // 探索标记
    PlayerBase* tent;                   // 玩家帐篷
    GameOverDialog* gameOverDialog; // 游戏失败对话框
  

    QTime gameStartTime;          // 游戏开始时间
    int totalGameTime;            // 游戏总时长（秒）

    AudioPlayer* m_gameAudioPlayer;

    /**
     * @brief 应用游戏设置
     * 将游戏设置应用到游戏中
     */
    void applySettings();
};

#endif // GAMEWIDGET_H
