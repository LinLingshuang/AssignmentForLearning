#include <QGraphicsView>
#include <QString>
#include <QKeyEvent>
#include <QFileDialog>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>
#include "gameWidget.h"
#include "ui_gameWidget.h"
#include "towerButton.h"
#include "global.h"
#include "utils.h"
#include "tower.h"
#include "bulletmanager.h"
#include "buildmanager.h"
#include "gameSaveData.h"
#include <QDebug>
#include "audiomanager.h"
#include <QRandomGenerator>


/**
 * @brief 从存档文件加载游戏的构造函数
 * 根据存档文件创建并恢复游戏状态
 *
 * @param saveFileName 存档文件路径
 * @param settings 游戏设置参数
 * @param parent 父窗口指针
 */
Game::Game(const QString& saveFileName, const GameSettings& settings, QWidget* parent)
    : Game(settings, parent)  // 委托构造，先调用基础构造函数
{
    // 加载游戏状态
    if (!loadGame(saveFileName)) {
        qDebug() << "警告：无法加载存档文件" << saveFileName;
        // 这里可以添加错误处理逻辑，比如显示错误提示
    }
}

/**
 * @brief 游戏构造函数
 * 初始化游戏界面和核心游戏逻辑
 *
 * @param settings 游戏设置参数，包括音效、音乐、难度等
 * @param parent 父窗口指针
 */
Game::Game(const GameSettings& settings, QWidget* parent)
    : QWidget(parent),
    ui(new Ui::Game),
    width(WIDTH),
    height(HEIGHT),
    m_gameAudioPlayer(new AudioPlayer(this)),
    gameSettings(settings),
    isPaused(false),
    totalGameTime(0
{
    // 设置音频音量
    m_gameAudioPlayer->setSoundEffectVolume(static_cast<float>(gameSettings.soundEffectVolume) / 100.0f);
    m_gameAudioPlayer->setMusicVolume(static_cast<float>(gameSettings.musicVolume) / 100.0f);
    m_gameAudioPlayer->setVolume(1.0f); // 总音量保持最大，使用音效和音乐音量进行单独控制

    // 预加载所有音效资源
    m_gameAudioPlayer->loadSoundEffect("game_bgm", ":/sounds/music/bgm-new.wav");
    m_gameAudioPlayer->loadSoundEffect("player_walk", ":/sounds/music/walk-new.wav");
    m_gameAudioPlayer->loadSoundEffect("player_roll", ":/sounds/music/zi-new.wav");
    m_gameAudioPlayer->loadSoundEffect("player_chop", ":/sounds/music/chop-new.wav");
    m_gameAudioPlayer->loadSoundEffect("player_mining", ":/sounds/music/mining-new.wav");
    m_gameAudioPlayer->loadSoundEffect("monster_death", ":/sounds/music/monster_death-new.wav");
    m_gameAudioPlayer->loadSoundEffect("monster_attack", ":/sounds/music/monster-new.wav");
    m_gameAudioPlayer->loadSoundEffect("tower_shoot", ":/sounds/music/shoot-new.wav");
    m_gameAudioPlayer->loadSoundEffect("tower_upgrade", ":/sounds/music/upgrade-new.wav");
    m_gameAudioPlayer->loadSoundEffect("area_damage", ":/sounds/music/break-new.wav");
    m_gameAudioPlayer->loadSoundEffect("warning", ":/sounds/music/di-new.wav");
    m_gameAudioPlayer->loadSoundEffect("bullet_impact", ":/sounds/music/di.2-new.wav");
    m_gameAudioPlayer->loadSoundEffect("resource_obtain", ":/sounds/music/obtain-new.wav");

    // 播放游戏BGM
    m_gameAudioPlayer->playBgm(":/sounds/music/bgm-new.wav", 60000);
    //qDebug() << "游戏界面BGM开始播放，路径：qrc:/sounds/music/bgm-new.wav";


    ui->setupUi(this);
    setFixedSize(width, height);
    setFocusPolicy(Qt::StrongFocus);
    setFocus();

    // 记录游戏开始时间
    gameStartTime = QTime::currentTime();

    // 应用游戏设置
    applySettings();

    // 1. 创建场景
    scene = new QGraphicsScene(this);

    // 2. 创建视图
    view = new QGraphicsView(scene, this);
    view->setRenderHint(QPainter::Antialiasing);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(width, height);  // 配合地图大小
    view->setFocusPolicy(Qt::NoFocus);  // 防止视图抢夺键盘焦点
    view->setAttribute(Qt::WA_TransparentForMouseEvents, false);  // Allow mouse events but not keyboard
    view->installEventFilter(this);  // Install event filter to catch keyboard events

    // 3. 取消滚动区域边距（重要）
    view->setFrameStyle(QFrame::NoFrame);

    //开启鼠标追踪
    setMouseTracking(true);
    view->setMouseTracking(true);
    view->viewport()->setMouseTracking(true);

    //安装事件过滤器
    view->installEventFilter(this);
    view->viewport()->installEventFilter(this);

    // 初始化地图
    gMap = new Map;
    scene->addItem(gMap);
    scene->setSceneRect(0, 0, gMap->getWidth(), gMap->getHeight());

    // 应用网格显示设置
    gMap->setShowGrid(gameSettings.showGrid);
    // 初始化怪物生成塔
    monsterSpawner = new MonsterSpawnerTower();
    scene->addItem(monsterSpawner);

    // 创建帐篷
    tent = new PlayerBase();
    scene->addItem(tent);

    connect(monsterSpawner, &MonsterSpawnerTower::monsterSpawned, this, [this](Monster* monster) {
        scene->addItem(monster);
        // 连接怪物攻击信号
        connect(monster, &Monster::attackedCamp, this, &Game::handleCampAttacked);

        // 连接怪物开始攻击信号
        connect(monster, &Monster::attackedCamp, this, [this](int damage) {
            //playerBase->takeDamage(damage);
            myUI->sub(damage, CAMPHEALTH);
            });

        connect(monster, &Monster::attackedPlayer, this, [this](int damage) {
            myUI->sub(damage, PLAYERHEALTH);
            });

        // 连接怪物死亡信号
        connect(monster, &Monster::died, this, [this](MonsterType type) {
            // 播放怪物死亡音效
            m_gameAudioPlayer->playSoundEffect("monster_death");
            
            QRandomGenerator* random = QRandomGenerator::global();
            int rewardType = random->bounded(100);
            switch (type)
            {
            case MonsterType::MONSTER1:
                if (rewardType >= 0 && rewardType < 2) {
                    myUI->add(1, BRONZE);
                }
                else if (rewardType >= 2 && rewardType < 4) {
                    myUI->add(1, SILVER);
                }
                else if (rewardType >= 4 && rewardType < 6) {
                    myUI->add(1, GOLD);
                }
                break;
            case MonsterType::MONSTER2:
                if (rewardType >= 0 && rewardType < 3) {
                    myUI->add(1, BRONZE);
                }
                else if (rewardType >= 3 && rewardType < 6) {
                    myUI->add(1, SILVER);
                }
                else if (rewardType >= 6 && rewardType < 9) {
                    myUI->add(1, GOLD);
                }
                break;
            case MonsterType::MONSTER3:
                if (rewardType >= 0 && rewardType < 5) {
                    myUI->add(1, BRONZE);
                }
                else if (rewardType >= 5 && rewardType < 10) {
                    myUI->add(1, SILVER);
                }
                else if (rewardType >= 10 && rewardType < 15) {
                    myUI->add(1, GOLD);
                }
                break;
            case MonsterType::SLIME:
                if (rewardType >= 0 && rewardType < 8) {
                    myUI->add(1, BRONZE);
                }
                else if (rewardType >= 8 && rewardType < 16) {
                    myUI->add(1, SILVER);
                }
                else if (rewardType >= 16 && rewardType < 24) {
                    myUI->add(1, GOLD);
                }
                break;
            default:
                if (rewardType >= 0 && rewardType < 10) {
                    myUI->add(1, BRONZE);
                }
                else if (rewardType >= 10 && rewardType < 20) {
                    myUI->add(1, SILVER);
                }
                else if (rewardType >= 20 && rewardType < 30) {
                    myUI->add(1, GOLD);
                }
                break;
            }
            });

        // 开始攻击营地时播放攻击音效
        connect(monster, &Monster::startedAttackingCamp, this, [this]() {
            m_gameAudioPlayer->playSoundEffect("monster_attack");
        });

        // 连接怪物到达终点信号
        connect(monster, &Monster::reachedDestination, this, []() {
            qDebug() << "怪物到达终点！";
            });
        });

    // 连接波数更新信号
    connect(monsterSpawner, &MonsterSpawnerTower::waveChanged, this, [](int wave) {
        qDebug() << "当前波数：" << wave;
        });

    // 连接帐篷信号
    connect(tent, &PlayerBase::tentDestroyed, this, &Game::handleTentDestroyed);
    connect(tent, &PlayerBase::healthChanged, this, [this](int newHealth) {
        if (myUI) {
            myUI->setCampHealth(newHealth);
            myUI->updateUI();
        }
    });

    // 初始化游戏失败对话框
    gameOverDialog = new GameOverDialog(this);
    connect(gameOverDialog, &GameOverDialog::returnToMenu, this, &Game::handleReturnToMenu);
    connect(gameOverDialog, &GameOverDialog::exitGame, this, &Game::handleExitGame);
    
   
   
    // 连接波数更新信号
    connect(monsterSpawner, &MonsterSpawnerTower::waveChanged, this, [this](int newWave) {
        qDebug() << "Current wave:" << newWave;
        // 更新UI：更新波数显示
        if (myUI) {
            // 设置波数（直接设置，而不是增量）
            // 先获取当前值，然后计算差值
            int currentWave = myUI->getWave();
            if (newWave != currentWave) {
                int diff = newWave - currentWave;
                myUI->add(diff, WAVE);
            }
        }
        });

    // 延迟1秒后开始生成怪物
    QTimer::singleShot(1000, this, []() {
        monsterSpawner->startSpawning();
        });

    // 初始化资源管理器
    resourceManager = new ResourceManager(this);
    connect(resourceManager, &ResourceManager::resourceAdded, this, [this](Resource* r) {
        scene->addItem(r);
        });
    resourceManager->initPicture();

    // 初始化炮塔按钮
    towerNum = 0;
    tower.push_back(new TowerButton("archer", TowerType::TOWER1, this));
    towerNum++;
    tower.push_back(new TowerButton("cannon", TowerType::TOWER2, this));
    towerNum++;
    tower.push_back(new TowerButton("mortar", TowerType::TOWER3, this));
    towerNum++;

    // 隐藏炮塔按钮
    for (int i = 0; i < towerNum; i++)
    {
        tower[i]->move(width - BTNWIDTH, height - (towerNum - i) * BTNHEIGHT);
    }
    for (int i = 0; i < towerNum; i++)
    {
        tower[i]->hide();
    }
    buttonVisible = false;

    // 初始化UI界面
    myUI = new PlayerUI(this);

    // 初始化UI显示（确保初始值正确显示）
    myUI->updateUI();

    // 连接资源收集信号（必须在myUI初始化之后）
    for (int i = 0; i < resourceManager->getResourcesNum(); i++)
    {
        Resource* res = resourceManager->getResources(i);
        connect(res, &Resource::resourceDepleted, myUI, [this, res]() {
            myUI->collectResource(res->getType());
            updateBtn();
            });
    }

    updateBtn();

    buildManager = new BuildManager;
    for (int i = 0; i < towerNum; i++)
    {
        connect(tower[i], &QPushButton::clicked, this, [i,this]() {
            switch (i)
            {
            case 0:
                if (tower[0]->enoughOrNot())
                    buildManager->startBuild(TowerType::TOWER1);
                break;
            case 1:
                if (tower[1]->enoughOrNot())
                    buildManager->startBuild(TowerType::TOWER2);
                break;
            case 2:
                if (tower[2]->enoughOrNot())
                    buildManager->startBuild(TowerType::TOWER3);
                break;
            }
            });
    }

    setMouseTracking(true);
    view->setMouseTracking(true);

    connect(buildManager, &BuildManager::previewCreated,
        this, [this](PreviewTower* preview) {
            scene->addItem(preview);

            QPoint viewPos = view->mapFromGlobal(QCursor::pos());
            QPointF worldPos = view->mapToScene(viewPos);
            QPoint grid = gMap->pixelToGrid(worldPos);

            bool canPlace = gMap->canPlaceTower(grid);
            preview->setGridPos(grid);
            preview->setValid(canPlace);
        });

    connect(buildManager, &BuildManager::previewRemoved,
        this, [this](PreviewTower* preview) {
            scene->removeItem(preview);
        });

    explorationmarker = new ExplorationMarker(scene);
    connect(me, &Player::moved, explorationmarker, &ExplorationMarker::refreshMarkers);

    playerBase = new PlayerBase();
    scene->addItem(playerBase);
    QPoint gridPos = gMap->playerHome[0];
    //playerBase->setPos(gridPos.y()* TILESIZE, gridPos.x()* TILESIZE);

    // 隐藏UI界面
    myUI->move(width - myUI->getWidth(), 0);
    myUI->hide();
    uiVisible = false;

    // 初始化玩家
    me = new Player();  // 将地图指针传递给Player

    // 显示玩家
    scene->addItem(me);

    // 玩家设置为视角中心
    viewTimer = new QTimer(this);
    connect(viewTimer, &QTimer::timeout, this, [&]() {
        view->centerOn(me);
        // 移除强制设置焦点的逻辑，避免干扰按钮点击事件
        });
    // 调整为16ms（约60fps）以减少性能消耗
    viewTimer->start(16);

    // 确保初始焦点在Game widget上
    setFocus();


    // 添加探索标记
    explorationmarker = new ExplorationMarker(scene);
    connect(me, &Player::moved, explorationmarker, &ExplorationMarker::refreshMarkers);
    // 连接玩家移动信号到音效播放
    connect(me, &Player::moved, this, [this]() {
        m_gameAudioPlayer->playSoundEffect("player_walk");
    });
    // 连接玩家翻滚信号到音效播放
    connect(me, &Player::rolling, this, [this]() {
        m_gameAudioPlayer->playSoundEffect("player_roll");
    });

    // 初始化暂停对话框
    pauseDialog = new PauseDialog(this);

    // 连接暂停对话框信号
    connect(pauseDialog, &PauseDialog::saveAndExit, this, &Game::handleSaveAndExit);
    connect(pauseDialog, &PauseDialog::continueGame, this, &Game::handleContinueGame);

    // 创建暂停按钮
    pauseButton = new QPushButton(this);
    pauseButton->setFixedSize(80, 30);
    pauseButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #4CAF50;"
        "    color: white;"
        "    border-radius: 5px;"
        "    font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "    background-color: #45a049;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #3e8e41;"
        "}"
    );
    pauseButton->setText("暂停");
    pauseButton->move(10, 10); // 左上角位置
    // 设置按钮不接收焦点，解决空格键触发暂停的问题
    pauseButton->setFocusPolicy(Qt::NoFocus);
    pauseButton->show();
    pauseButton->raise(); // 确保按钮在最上层
    
    // 连接按钮点击事件
    connect(pauseButton, &QPushButton::clicked, this, &Game::on_pauseButton_clicked);
   
}
/**
 * @brief 游戏析构函数
 * 释放游戏资源，包括怪物生成器、地图和UI
 */
Game::~Game()
{
    monsterSpawner->stopSpawning();
    delete monsterSpawner;
    delete gMap;
    if (gMap != nullptr) {
        delete gMap;
        gMap = nullptr;
    }
    delete pauseDialog;
    delete ui;
}

/**
 * @brief 应用游戏设置
 * 根据传入的游戏设置参数配置游戏环境
 */
void Game::applySettings()
{
    // 应用网格显示设置
    // 注意：这里需要在地图初始化后调用，所以在构造函数中applySettings需要在地图初始化之前调用
    // 实际的网格设置会在地图初始化时应用

    // 应用难度设置
    // 根据难度调整游戏参数
    switch (gameSettings.difficulty) {
    case 1: // 简单难度
        // 调整怪物生命值、速度等参数
        break;
    case 2: // 普通难度
        // 默认设置
        break;
    case 3: // 困难难度
        // 增加怪物生命值、速度等参数
        break;
    }

    // 应用音效和音乐音量设置
    m_gameAudioPlayer->setSoundEffectVolume(static_cast<float>(gameSettings.soundEffectVolume) / 100.0f);
    m_gameAudioPlayer->setMusicVolume(static_cast<float>(gameSettings.musicVolume) / 100.0f);
    m_gameAudioPlayer->setVolume(1.0f); // 总音量保持最大，使用音效和音乐音量进行单独控制
    
    // 应用帧率设置
    if (viewTimer) {
        int interval = 1000 / gameSettings.frameRate;
        viewTimer->setInterval(interval);
    }

    qDebug() << "Applied game settings: " <<
        "Difficulty: " << gameSettings.difficulty <<
        "Sound Volume: " << gameSettings.soundEffectVolume <<
        "Music Volume: " << gameSettings.musicVolume <<
        "Show Grid: " << gameSettings.showGrid <<
        "Invert Y Axis: " << gameSettings.invertYAxis <<
        "Frame Rate: " << gameSettings.frameRate << "FPS";
}

/**
 * @brief 键盘按键按下事件处理
 * 处理玩家的移动和特殊动作
 *
 * @param ev 键盘事件对象
 */
void Game::keyPressEvent(QKeyEvent* ev)
{
    // Debug: Always log that keyPressEvent was called
  //  qDebug() << "keyPressEvent called, key code:" << ev->key() << "text:" << ev->text();

    if (!me) {
       // qDebug() << "Player object not initialized";
        QWidget::keyPressEvent(ev);
        return;
    }

    bool isRolling = me->isRolling();
    //qDebug() << "Player rolling status:" << isRolling;

    if (isRolling) {
       // qDebug() << "Player is rolling, ignoring movement keys";
        QWidget::keyPressEvent(ev);
        return;
    }

    // 使用自定义按键绑定
    // 确保按键绑定已初始化（如果未设置，使用默认值）
    int keyUp = (gameSettings.keyMoveUp > 0) ? gameSettings.keyMoveUp : Qt::Key_W;
    int keyDown = (gameSettings.keyMoveDown > 0) ? gameSettings.keyMoveDown : Qt::Key_S;
    int keyLeft = (gameSettings.keyMoveLeft > 0) ? gameSettings.keyMoveLeft : Qt::Key_A;
    int keyRight = (gameSettings.keyMoveRight > 0) ? gameSettings.keyMoveRight : Qt::Key_D;
    int keyRoll = (gameSettings.keyRoll > 0) ? gameSettings.keyRoll : Qt::Key_Shift;
    int keyCollect = (gameSettings.keyCollect > 0) ? gameSettings.keyCollect : Qt::Key_Space;
    /*
    // Debug: Log key bindings (this should always print if we get here)
    qDebug() << "=== Key matching section reached ===";
    qDebug() << "Key bindings - Up:" << keyUp << "(W=" << Qt::Key_W << ") Down:" << keyDown << "(S=" << Qt::Key_S << ") Left:" << keyLeft << "(A=" << Qt::Key_A << ") Right:" << keyRight << "(D=" << Qt::Key_D << ") Roll:" << keyRoll;
    qDebug() << "Pressed key:" << ev->key() << "Settings values - Up:" << gameSettings.keyMoveUp << "Down:" << gameSettings.keyMoveDown << "Left:" << gameSettings.keyMoveLeft << "Right:" << gameSettings.keyMoveRight;
    */
    bool keyHandled = false;

    if (ev->key() == keyUp) {
        me->setMoveUp(true);
        keyHandled = true;
       // qDebug() << "Move up key pressed - movement flag set";
    }
    if (ev->key() == keyDown) {
        me->setMoveDown(true);
        keyHandled = true;
       // qDebug() << "Move down key pressed - movement flag set";
    }
    if (ev->key() == keyLeft) {
        me->setMoveLeft(true);
        keyHandled = true;
      // qDebug() << "Move left key pressed - movement flag set";
    }
    if (ev->key() == keyRight) {
        me->setMoveRight(true);
        keyHandled = true;
      //  qDebug() << "Move right key pressed - movement flag set";
    }

    if (ev->key() == keyRoll && me->isWalking()) {
        // 设置翻滚状态和方向
        me->setState(PlayerState::ROLLING);
        me->setRollUp(me->getWalkUp());
        me->setRollDown(me->getWalkDown());
        me->setRollLeft(me->getWalkLeft());
        me->setRollRight(me->getWalkRight());
        keyHandled = true;
       // qDebug() << "Roll key pressed";
    }

    /*
    if(ev->key() == Qt::Key_Shift){
       me->setState(PlayerState::ROLLING);
       me->setRollUp(me->getWalkUp());
       me->setRollDown(me->getWalkDown());
       me->setRollLeft(me->getWalkLeft());
       me->setRollRight(me->getWalkRight());
    }
   */
    if (me->getState() == PlayerState::WALKING && ev->key() == keyCollect)
    {
        Resource* r = me->getTarget();
        if (r != nullptr)
        {
            if (r->getType() == ResourceType::GRASS_TREE || r->getType() == ResourceType::SWAMP_TREE)
            {
                me->setState(PlayerState::CUTTING);
                if (r->getCenterPixal().x() < me->pos().x())
                {
                    me->setCutLeft(true);
                    me->setCutRight(false);
                }
                else
                {
                    me->setCutLeft(false);
                    me->setCutRight(true);
                }
                return;
            }

            else
            {
                me->setState(PlayerState::DIGGING);
                if (r->getCenterPixal().x() < me->pos().x())
                {
                    me->setDigLeft(true);
                    me->setDigRight(false);
                }
                else
                {
                    me->setDigLeft(false);
                    me->setDigRight(true);
                }
                return;
            }
        }
    }

    if (!keyHandled) {
        qDebug() << "Key not matched to any movement key";
    }

    if (keyHandled) {
        ev->accept();
    }
    else {
        QWidget::keyPressEvent(ev);
    }



}

/**
 * @brief 键盘按键释放事件处理
 * 处理玩家移动的停止和UI/按钮的显示隐藏
 *
 * @param ev 键盘事件对象
 */
void Game::keyReleaseEvent(QKeyEvent* ev)
{
    int keyTowerPanel = (gameSettings.keyTowerPanel > 0) ? gameSettings.keyTowerPanel : Qt::Key_Tab;
    if (ev->key() == keyTowerPanel)
    {
        uiVisible = !uiVisible;
        if (uiVisible)
        {
            myUI->show();
            myUI->raise();
        }
        else myUI->hide();
        return;  // 处理完就退出，避免影响后面逻辑
    }

    int keyResourcePanel = (gameSettings.keyResourcePanel > 0) ? gameSettings.keyResourcePanel : Qt::Key_Q;
    if (ev->key() == keyResourcePanel)
    {
        buttonVisible = !buttonVisible;
        if (buttonVisible)
        {
            for (int i = 0; i < towerNum; i++)
            {
                tower[i]->show();
                tower[i]->raise();
            }
            explorationmarker->setMarked(true);
        }
        else
        {
            for (int i = 0; i < towerNum; i++)
            {
                tower[i]->hide();
            }
            explorationmarker->setMarked(false);
        }
    }

    if (!me) return;
    if (me->isRolling()) return;

    // 使用自定义按键绑定（确保按键绑定已初始化）
    int keyUp = (gameSettings.keyMoveUp > 0) ? gameSettings.keyMoveUp : Qt::Key_W;
    int keyDown = (gameSettings.keyMoveDown > 0) ? gameSettings.keyMoveDown : Qt::Key_S;
    int keyLeft = (gameSettings.keyMoveLeft > 0) ? gameSettings.keyMoveLeft : Qt::Key_A;
    int keyRight = (gameSettings.keyMoveRight > 0) ? gameSettings.keyMoveRight : Qt::Key_D;

    if (ev->key() == keyUp) {
        me->setMoveUp(false);
    }
    if (ev->key() == keyDown) {
        me->setMoveDown(false);
    }
    if (ev->key() == keyLeft) {
        me->setMoveLeft(false);
    }
    if (ev->key() == keyRight) {
        me->setMoveRight(false);
    }
    QWidget::keyReleaseEvent(ev);
}

/**
 * @brief 处理保存并退出信号
 * 当用户在暂停对话框中点击保存并退出按钮时调用
 */
void Game::handleSaveAndExit()
{
    qDebug() << "用户点击了保存并退出";

    // 显示保存文件对话框，让用户选择保存位置和文件名
    QString fileName = QFileDialog::getSaveFileName(this, tr("保存游戏存档"), QDir::currentPath(), tr("存档文件 (*.sav);;所有文件 (*.*)"));
    if (!fileName.isEmpty()) {
        // 创建游戏存档数据
        GameSaveData saveData(fileName, this);

        // 打开文件进行写入
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly)) {
            QDataStream out(&file);
            out.setVersion(QDataStream::Qt_5_15);

            // 使用序列化函数写入整个存档数据
            out << saveData;

            file.close();
            qDebug() << "游戏存档保存成功：" << fileName;
        }
        else {
            qDebug() << "无法打开文件进行保存：" << fileName;
        }
    }
    
    // 保存完成后退出游戏
    qDebug() << "退出游戏";
    // 关闭当前窗口
    close();
    // 退出应用程序
    QApplication::quit();
}

/**
 * @brief 处理基地被攻击的槽函数
 * 当基地受到伤害时调用
 */
void Game::handleCampAttacked(int damage)
{
    qDebug() << "基地受到攻击，伤害值：" << damage;
    if (tent) {
        tent->takeDamage(damage);
    }
    // 如果没有帐篷，直接更新UI
    if (myUI) {
        int currentHealth = myUI->getCampHealth();
        myUI->setCampHealth(currentHealth - damage);
        myUI->updateUI();
    }
}

/**
 * @brief 处理帐篷被摧毁的槽函数
 * 当帐篷被摧毁时调用，触发游戏失败
 */
void Game::handleTentDestroyed()
{
    qDebug() << "帐篷被摧毁，游戏失败！";
    
    // 暂停游戏主逻辑
    isPaused = true;
    
    // 停止视图更新定时器
    if (viewTimer) {
        viewTimer->stop();
    }
    
    // 暂停怪物生成器（会暂停所有怪物相关定时器）
    monsterSpawner->pause();
    
    // 暂停所有游戏元素
    if (scene) {
        QList<QGraphicsItem*> items = scene->items();
        for (QGraphicsItem* item : items) {
            
            // 暂停炮塔
            Tower* tower = dynamic_cast<Tower*>(item);
            if (tower) {
                tower->pause();
                // 暂停炮塔的子弹管理器
                BulletManager* bulletManager = tower->getManager();
                if (bulletManager) {
                    bulletManager->pauseAllBullets();
                }
            }
        }
    }
    
    // 显示游戏失败对话框
    gameOverDialog->show();
    gameOverDialog->raise();
    gameOverDialog->activateWindow();
}

/**
 * @brief 处理返回主菜单信号
 * 当用户在失败对话框中点击返回主菜单按钮时调用
 */
void Game::handleReturnToMenu()
{
    qDebug() << "返回主菜单";
    // 关闭当前游戏窗口，返回主菜单
    this->close();
}

/**
 * @brief 处理退出游戏信号
 * 当用户在失败对话框中点击退出游戏按钮时调用
 */
void Game::handleExitGame()
{
    qDebug() << "退出游戏";
    // 关闭所有窗口，退出应用程序
    QApplication::quit();
}


/**
 * @brief 处理继续游戏信号
 * 当用户在暂停对话框中点击继续按钮时调用
 */
void Game::handleContinueGame()
{
    qDebug() << "用户点击了继续游戏";
    // 继续游戏逻辑
    isPaused = false;
    if (viewTimer) {
        viewTimer->start(16);
    }
    if (monsterSpawner) {
        monsterSpawner->resume();
    }
    
    // 恢复所有游戏元素
    if (scene) {
        QList<QGraphicsItem*> items = scene->items();
        for (QGraphicsItem* item : items) {
            if (!item) continue;
            // 恢复炮塔
            Tower* tower = dynamic_cast<Tower*>(item);
            if (tower) {
                tower->resume();
                // 恢复炮塔的子弹管理器
                BulletManager* bulletManager = tower->getManager();
                if (bulletManager) {
                    bulletManager->resumeAllBullets();
                }
            }
            // 恢复怪物
            Monster* monster = dynamic_cast<Monster*>(item);
            if (monster) {
                monster->resume();
            }
        }
    }
    
    // 恢复玩家
    if (me) {
        me->resume();
    }
    
    gameStartTime = QTime::currentTime();
    qDebug() << "游戏已继续";
}
/*
bool Game::eventFilter(QObject* watched, QEvent* event)
{
    // ---------------------------------------------------------
    // 1. 处理鼠标移动 (预览塔跟随)
    // ---------------------------------------------------------w

    if (event->type() == QEvent::MouseMove)
    {
        // 如果不在建造模式，不拦截，交给 View 默认处理
        if (!buildManager->isBuilding())
            return false;

        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);

        // 【关键】因为监听的是 View，所以 pos 直接就是 View 坐标
        QPoint viewPos = mouseEvent->pos();
        QPointF worldPos = view->mapToScene(viewPos);
        QPoint grid = gMap->pixelToGrid(worldPos);

        bool canPlace = gMap->canPlaceTower(grid);
        bool canDetect = me->isDetectable(grid.x(), grid.y());
        PreviewTower* preview = buildManager->getPreviewTower();
        if (preview)
        {
            preview->setGridPos(grid);
            preview->setValid(canPlace && canDetect);
        }
        // 这里返回 false，让 view 也能收到移动信号（不影响功能，比较保险）
        return false;
    }

    // ---------------------------------------------------------
    // 2. 处理鼠标按下 (放置塔 / 取消)
    // ---------------------------------------------------------



    if (event->type() == QEvent::MouseButtonPress)
    {
        // 如果不在建造模式，就不管，让 View 自己处理（比如点击选中其他塔）
        if (!buildManager->isBuilding())
            return false;

        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);

        // 同样：坐标直接就是 View 坐标
        QPoint viewPos = mouseEvent->pos();
        QPointF worldPos = view->mapToScene(viewPos);
        QPoint grid = gMap->pixelToGrid(worldPos);

        // --- 左键：放置 ---
        if (mouseEvent->button() == Qt::LeftButton)
        {
            if (gMap->canPlaceTower(grid) && me->isDetectable(grid.x(), grid.y()))
            {
                // 创建真塔
                Tower* tower = new Tower(buildManager->getPreviewTower()->getTowerType());

                // 这里需要你的 Tower 类有对应的添加到场景的逻辑
                tower->put(grid.x(), grid.y());
                scene->addItem(tower);
                
                // 连接炮塔射击信号到音效播放
                connect(tower, &Tower::fired, this, [this]() {
                    m_gameAudioPlayer->playSoundEffect("tower_shoot");
                });
                
                // 放置成功后，取消建造模式
                connect(tower->getManager(), &BulletManager::bulletCreated, this, [this](Bullet* bullet) {
                    scene->addItem(bullet);
                    });
                gMap->placeTower(worldPos);
                buildManager->cancelBuild();
            }
            // 返回 true，表示“这事我处理完了”，View 就不要再瞎掺和了
            return true;
        }

        // --- 右键：取消 ---        
        else if (mouseEvent->button() == Qt::RightButton)
        {
            buildManager->cancelBuild();
            return true; // 拦截事件，防止弹出默认菜单等
        }
    }
    
    // 处理右键点击炮塔的情况（不在建造模式时）
    if (event->type() == QEvent::MouseButtonPress) {
        if (!buildManager->isBuilding()) {
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
            if (mouseEvent->button() == Qt::RightButton) {
                // 获取点击位置
                QPoint viewPos = mouseEvent->pos();
                QPointF worldPos = view->mapToScene(viewPos);
                QPoint grid = gMap->pixelToGrid(worldPos);
                
                // 检查玩家是否在放置范围内
                if (me->isDetectable(grid.x(), grid.y())) {
                    // 查找点击位置的炮塔
                    QList<QGraphicsItem*> items = scene->items(worldPos);
                    for (QGraphicsItem* item : items) {
                        Tower* tower = dynamic_cast<Tower*>(item);
                        if (tower) {
                            // 如果已有对话框，先关闭
                            if (towerOperationDialog) {
                                towerOperationDialog->close();
                                delete towerOperationDialog;
                                towerOperationDialog = nullptr;
                            }
                            
                            // 创建新的操作对话框
                            towerOperationDialog = new TowerOperationDialog(tower, this);
                            connect(towerOperationDialog, &TowerOperationDialog::upgradeTower, this, [this](Tower* tower) {
                                // 升级炮塔逻辑
                                qDebug() << "升级炮塔";
                                
                                // 检查并消耗资源
                                bool canUpgrade = false;
                                int towerType = static_cast<int>(tower->getTowerType());
                                
                                switch (towerType) {
                                case 0: // TOWER1
                                    if (myUI->sub(5, UiResource::STONE)) {
                                        canUpgrade = true;
                                    }
                                    break;
                                case 1: // TOWER2
                                    if (myUI->sub(5, UiResource::SILVER)) {
                                        canUpgrade = true;
                                    }
                                    break;
                                case 2: // TOWER3
                                    if (myUI->sub(5, UiResource::GOLD)) {
                                        canUpgrade = true;
                                    }
                                    break;
                                default:
                                    break;
                                }
                                
                                if (canUpgrade) {
                                    tower->upgrade();
                                    myUI->updateUI();
                                    qDebug() << "炮塔升级成功";
                                } else {
                                    qDebug() << "资源不足，无法升级炮塔";
                                }
                            });
                            connect(towerOperationDialog, &TowerOperationDialog::dismantleTower, this, [this](Tower* tower) {
                                // 拆除炮塔逻辑
                                qDebug() << "拆除炮塔";
                                
                                // 计算资源返还
                                int towerType = static_cast<int>(tower->getTowerType());
                                int level = tower->getLevel();
                                
                                // 基础建造成本
                                int baseCost = 0;
                                int upgradeCostPerLevel = 0;
                                UiResource baseResource = UiResource::WOOD;
                                UiResource upgradeResource = UiResource::STONE;
                                
                                switch (towerType) {
                                case 0: // TOWER1
                                    baseCost = 5;
                                    upgradeCostPerLevel = 5;
                                    baseResource = UiResource::WOOD;
                                    upgradeResource = UiResource::STONE;
                                    break;
                                case 1: // TOWER2
                                    baseCost = 5;
                                    upgradeCostPerLevel = 5;
                                    baseResource = UiResource::STONE;
                                    upgradeResource = UiResource::SILVER;
                                    break;
                                case 2: // TOWER3
                                    baseCost = 5;
                                    upgradeCostPerLevel = 5;
                                    baseResource = UiResource::BRONZE;
                                    upgradeResource = UiResource::GOLD;
                                    break;
                                default:
                                    break;
                                }
                                
                                // 计算总返还资源
                                int totalCost = baseCost + (level - 1) * upgradeCostPerLevel;
                                int refund = totalCost / 2; // 返还50%
                                
                                // 返还资源
                                myUI->add(refund, baseResource);
                                myUI->updateUI();
                                qDebug() << "返还资源：" << refund;
                                
                                // 拆除炮塔
                                scene->removeItem(tower);
                                delete tower;
                                if (towerOperationDialog) {
                                    towerOperationDialog->close();
                                    delete towerOperationDialog;
                                    towerOperationDialog = nullptr;
                                }
                            });
                            
                            towerOperationDialog->show();
                            towerOperationDialog->raise();
                            towerOperationDialog->activateWindow();
                            return true;
                        }
                    }
                }
            }
        }
    }

    // 其他事件交给父类默认处理
    return QWidget::eventFilter(watched, event);
}
*/

// ---------------------------------------------------------
// 处理鼠标移动事件（预览塔跟随鼠标）
// ---------------------------------------------------------
bool Game::handleMouseMove(QMouseEvent* event)
{
    if (!buildManager->isBuilding())
        return false; // 非建造模式交给 View 默认处理

    QPoint viewPos = event->pos();
    QPointF worldPos = view->mapToScene(viewPos);
    QPoint grid = gMap->pixelToGrid(worldPos);

    bool canPlace = gMap->canPlaceTower(grid);
    bool canDetect = me->isDetectable(grid.x(), grid.y());

    PreviewTower* preview = buildManager->getPreviewTower();
    if (preview)
    {
        preview->setGridPos(grid);
        preview->setValid(canPlace && canDetect);
    }

    return false; // 允许 View 继续处理
}

// ---------------------------------------------------------
// 处理单击事件（选中塔 / 放置塔 / 取消）
// ---------------------------------------------------------
bool Game::handleMousePress(QMouseEvent* event)
{
    QPoint viewPos = event->pos();
    QPointF worldPos = view->mapToScene(viewPos);
    QPoint grid = gMap->pixelToGrid(worldPos);

    if (!buildManager->isBuilding())
    {
        // 非建造模式：处理塔选择和升级
        Tower* tower = buildManager->getTower(grid.x(), grid.y());

        Tower* selectedTower = buildManager->getSelectedTower();

        if (event->button() == Qt::LeftButton)
        {
            if (!tower) return true;
            // 第一次点击——选择塔
            if (!selectedTower)
            {
                selectTower(tower);
                return true;
            }

            // 第二次点击——尝试升级
            if (selectedTower != tower)
            {
                selectTower(tower);
                return true;
            }

            handleTowerUpgrade(tower);
            clearTowerSelection();
            return true;
        }
        else if (event->button() == Qt::RightButton)
        {
            // 右键取消选择
            clearTowerSelection();
            return true;
        }
    }
    else
    {
        // 建造模式：处理塔放置
        if (event->button() == Qt::LeftButton)
        {
            if (gMap->canPlaceTower(grid) && me->isDetectable(grid.x(), grid.y()))
            {
                // 扣除资源
                auto sourceNeeded = Tower::getBuildCost(buildManager->getBuildingType());
                for (auto& s : sourceNeeded)
                    myUI->sub(s.second, s.first);

                // 创建塔
                Tower* tower = new Tower(buildManager->getPreviewTower()->getTowerType());
                buildManager->finalBuild(grid.x(), grid.y(), tower);
                tower->put(grid.x(), grid.y());
                scene->addItem(tower);

                // 炮塔射击音效
                connect(tower, &Tower::fired, this, [this]() {
                    m_gameAudioPlayer->playSoundEffect("tower_shoot");
                });

                // 子弹创建与命中音效
                connect(tower->getManager(), &BulletManager::bulletCreated, this, [this](Bullet* bullet) {
                    scene->addItem(bullet);
                    connect(bullet, &QObject::destroyed, this, [this]() {
                        m_gameAudioPlayer->playSoundEffect("bullet_impact");
                    });
                });

                gMap->placeTower(QPointF(grid.x(), grid.y()));
                buildManager->cancelBuild();
                
                // 更新炮塔按钮状态
                updateBtn();
            }
            return true;
        }
        else if (event->button() == Qt::RightButton)
        {
            // 右键取消建造
            buildManager->cancelBuild();
            return true;
        }
    }

    return false;
}

// ---------------------------------------------------------
// 处理双击事件（直接升级塔）
// ---------------------------------------------------------
bool Game::handleMouseDoubleClick(QMouseEvent* event)
{
    if (event->button() != Qt::LeftButton)
        return false;

    if (buildManager->isBuilding()) return true; // 建造模式不处理

    QPoint viewPos = event->pos();
    QPointF worldPos = view->mapToScene(viewPos);
    QPoint grid = gMap->pixelToGrid(worldPos);

    Tower* tower = buildManager->getTower(grid.x(), grid.y());
    if (!tower) return true;

    handleTowerUpgrade(tower);
    clearTowerSelection();

    //qDebug() << "双击升级成功";
    return true;
}

// ---------------------------------------------------------
// 升级塔的统一逻辑
// ---------------------------------------------------------
void Game::handleTowerUpgrade(Tower* tower)
{
    const auto& sourceNeeded = tower->getUpgradeCost();

    for (auto& s : sourceNeeded)
    {
        if (myUI->getNum(s.first) < s.second)
            return; // 资源不足，无法升级
    }

    for (auto& s : sourceNeeded)
        myUI->sub(s.second, s.first);

    tower->upgrade();
}

bool Game::eventFilter(QObject* watched, QEvent* event)
{
    switch (event->type())
    {
    case QEvent::MouseMove:
        return handleMouseMove(static_cast<QMouseEvent*>(event));

    case QEvent::MouseButtonPress:
        return handleMousePress(static_cast<QMouseEvent*>(event));

    case QEvent::MouseButtonDblClick:
        return handleMouseDoubleClick(static_cast<QMouseEvent*>(event));

    default:
        return QWidget::eventFilter(watched, event);
    }
}

void Game::updateBtn()
{
    for (int i = 0; i < towerNum; i++)
    {
        std::vector<std::pair<UiResource, int>> sourceNeeded = Tower::getBuildCost(TowerType(i));
        bool isEnough = true;
        for (int i = 0; i < (int)sourceNeeded.size(); i++)
        {
            if (myUI->getNum(sourceNeeded[i].first) < sourceNeeded[i].second)
            {
                isEnough = false;
                break;
            }
        }
        tower[i]->setEnough(isEnough);
    }
}

void Game::selectTower(Tower* tower)
{
    if (!tower) return;

    // 清理之前的显示
    clearTowerSelection();

    buildManager->setSelectedTower(tower->getGridX(), tower->getGridY());

    // 绘制攻击范围
    if (tower->getTowerType() != TowerType::TOWER3)
    {
        QGraphicsEllipseItem* rangeCircle = new QGraphicsEllipseItem();
        rangeCircle->setRect(
            tower->x() + TILESIZE / 2.0 - tower->getAttackRange(),
            tower->y() + TILESIZE / 2.0 - tower->getAttackRange(),
            tower->getAttackRange() * 2,
            tower->getAttackRange() * 2
        );
        rangeCircle->setBrush(QBrush(QColor(0, 255, 0, 50))); // 半透明绿色
        rangeCircle->setPen(Qt::NoPen);
        scene->addItem(rangeCircle);
        buildManager->setRangeCircle(rangeCircle);  // Tower 保存这个指针方便取消
    }
    else
    {
        qreal outerR = tower->getAttackRange();
        qreal innerR = outerR / OUTER_DIVIDE_INNER;   // 外内环比 = 3

        QPainterPath path;
        path.setFillRule(Qt::OddEvenFill);

        // 外圆
        path.addEllipse(
            QPointF(
                tower->x() + TILESIZE / 2.0,
                tower->y() + TILESIZE / 2.0
            ),
            outerR,
            outerR
        );

        // 内圆（挖空）
        path.addEllipse(
            QPointF(
                tower->x() + TILESIZE / 2.0,
                tower->y() + TILESIZE / 2.0
            ),
            innerR,
            innerR
        );

        QGraphicsPathItem* rangeRing = new QGraphicsPathItem();
        rangeRing->setPath(path);
        rangeRing->setBrush(QColor(0, 255, 0, 50)); // 半透明绿色
        rangeRing->setPen(Qt::NoPen);
        rangeRing->setZValue(-1); // 在炮塔下面

        scene->addItem(rangeRing);
        buildManager->setRangeCircle(rangeRing);

    }

    // 添加升级提示文字
    QGraphicsTextItem* upgradeText = new QGraphicsTextItem("Upgrade?");
    upgradeText->setDefaultTextColor(Qt::yellow);
    upgradeText->setFont(QFont("Arial", 20, QFont::Bold));
    upgradeText->setPos(tower->x() - 20, tower->y() - 40); // 炮塔上方
    scene->addItem(upgradeText);
    buildManager->setUpgradeText(upgradeText);
}

void Game::clearTowerSelection()
{
    Tower* tower = buildManager->getSelectedTower();
    if (!tower) return;

    // 移除显示的攻击范围和文字
    if (buildManager->getRangeCircle()) {
        scene->removeItem(buildManager->getRangeCircle());
        delete buildManager->getRangeCircle();
        buildManager->setRangeCircle(nullptr);
    }

    if (buildManager->getUpgradeText()) {
        scene->removeItem(buildManager->getUpgradeText());
        delete buildManager->getUpgradeText();
        buildManager->setUpgradeText(nullptr);
    }

    buildManager->clearSelectedTower();
}


/**
 * @brief 暂停按钮点击事件处理
 * 当用户点击暂停按钮时调用，暂停或继续游戏
 */
void Game::on_pauseButton_clicked()
{
    if (!isPaused) {
        // 计算游戏已运行时间
        totalGameTime += gameStartTime.secsTo(QTime::currentTime());

        // 暂停游戏逻辑
        isPaused = true;
        if (viewTimer) {
            viewTimer->stop();
        }

        // 暂停怪物生成器（会暂停所有怪物相关定时器）
        if (monsterSpawner) {
            monsterSpawner->pause();
        }
        
        // 暂停所有游戏元素
        if (scene) {
            QList<QGraphicsItem*> items = scene->items();
            for (QGraphicsItem* item : items) {
                if (!item) continue;
                // 暂停炮塔
                Tower* tower = dynamic_cast<Tower*>(item);
                if (tower) {
                    tower->pause();
                    // 暂停炮塔的子弹管理器
                    BulletManager* bulletManager = tower->getManager();
                    if (bulletManager) {
                        bulletManager->pauseAllBullets();
                    }
                }
                // 暂停怪物
                Monster* monster = dynamic_cast<Monster*>(item);
                if (monster) {
                    monster->pause();
                }
            }
        }
        
        // 暂停玩家
        if (me) {
            me->pause();
        }

        qDebug() << "游戏已暂停";
        // 显示暂停弹窗
        if (pauseDialog) {
            pauseDialog->show();
        }
    }
    else {
        // 继续游戏逻辑
        isPaused = false;
        if (viewTimer) {
            viewTimer->start(16);
        }

        // 恢复怪物生成器（会恢复所有怪物相关定时器）
        if (monsterSpawner) {
            monsterSpawner->resume();
        }
        
        // 恢复所有游戏元素
        if (scene) {
            QList<QGraphicsItem*> items = scene->items();
            for (QGraphicsItem* item : items) {
                if (!item) continue;
                // 恢复炮塔
                Tower* tower = dynamic_cast<Tower*>(item);
                if (tower) {
                    tower->resume();
                    // 恢复炮塔的子弹管理器
                    BulletManager* bulletManager = tower->getManager();
                    if (bulletManager) {
                        bulletManager->resumeAllBullets();
                    }
                }
                // 恢复怪物
                Monster* monster = dynamic_cast<Monster*>(item);
                if (monster) {
                    monster->resume();
                }
            }
        }
        
        // 恢复玩家
        if (me) {
            me->resume();
        }

        // 更新游戏开始时间为当前时间
        gameStartTime = QTime::currentTime();

        qDebug() << "游戏已继续";
}


/**
 * @brief 加载游戏状态
 * 从存档文件读取游戏状态并恢复
 *
 * @param saveFileName 存档文件路径
 * @return bool 如果加载成功返回true，否则返回false
 */
bool Game::loadGame(const QString& saveFileName)
{
    qDebug() << "正在加载游戏存档：" << saveFileName;

    // 打开存档文件
    QFile file(saveFileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "无法打开存档文件：" << saveFileName;
        return false;
    }

    // 读取存档数据
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_15);

    GameSaveData saveData;
    in >> saveData;

    file.close();

    qDebug() << "成功读取存档数据：" << saveData.saveName;

    // 恢复游戏时间
    totalGameTime = saveData.totalGameTime;
    gameStartTime = QTime::currentTime();

    // 恢复玩家数据
    if (me) {
        me->setPos(saveData.player.position);
        // 恢复玩家生命值（如果Player类有相关方法）
        // me->setHealth(saveData.player.health);
    }

    // 恢复资源数据
    if (myUI) {
        // 假设PlayerUI类有以下方法来设置资源
        myUI->setWood(saveData.player.wood);
        myUI->setStone(saveData.player.stone);
        myUI->setGold(saveData.player.gold);
        myUI->setCampHealth(saveData.campHealth);
    }

    // 恢复怪物波数
    if (monsterSpawner) {
        
        monsterSpawner->setCurrentWave(saveData.currentWave);
        qDebug() << "恢复当前波数：" << saveData.currentWave;
        
    }

    // 清理当前所有炮塔
    if (scene) {
        QList<QGraphicsItem*> items = scene->items();
        for (QGraphicsItem* item : items) {
            Tower* tower = dynamic_cast<Tower*>(item);
            if (tower) {
                scene->removeItem(tower);
                delete tower;
            }
        }
    }

    // 恢复炮塔数据
    for (const TowerData& towerData : saveData.towers) {
        // 创建新的炮塔
        Tower* tower = new Tower(static_cast<TowerType>(towerData.towerType));

        // 设置炮塔属性
        // 假设Tower类有相关方法
        // tower->setLevel(towerData.level);
        // tower->setHealth(towerData.health);
        // tower->setAttackRange(towerData.attackRange);

        // 设置格子状态为障碍物，防止重复放置
        if (gMap->isGridInsideMap(towerData.gridPosition.x(), towerData.gridPosition.y())) {
            gMap->setTileState(towerData.gridPosition.x(), towerData.gridPosition.y(), TILE_BLOCKED);
        }

        // 将炮塔放置在网格位置
        tower->put(towerData.gridPosition.x(), towerData.gridPosition.y());

        // 将炮塔添加到场景
        scene->addItem(tower);
        
        // 连接炮塔射击信号到音效播放
        connect(tower, &Tower::fired, this, [this]() {
            m_gameAudioPlayer->playSoundEffect("tower_shoot");
        });
        
        // 连接子弹创建信号，确保子弹能正确添加到场景
        connect(tower->getManager(), &BulletManager::bulletCreated, this, [this](Bullet* bullet) {
            scene->addItem(bullet);
            connect(bullet, &QObject::destroyed, this, [this]() {
                m_gameAudioPlayer->playSoundEffect("bullet_impact");
            });
        });
    }

    qDebug() << "游戏存档加载完成";
    return true;
}

/**
 * @brief 保存按钮点击事件处理
 * 当用户点击保存按钮时调用，保存游戏进度
 */
void Game::on_saveButton_clicked()
{
    qDebug() << "用户点击了保存按钮";

    // 显示保存文件对话框，让用户选择保存位置和文件名
    QString fileName = QFileDialog::getSaveFileName(this, tr("保存游戏存档"), QDir::currentPath(), tr("存档文件 (*.sav);;所有文件 (*.*)"));
    if (!fileName.isEmpty()) {
        // 创建游戏存档数据
        GameSaveData saveData(fileName, this);

        // 打开文件进行写入
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly)) {
            QDataStream out(&file);
            out.setVersion(QDataStream::Qt_5_15);

            // 使用序列化函数写入整个存档数据
            out << saveData;

            file.close();
            qDebug() << "游戏存档保存成功：" << fileName;
        }
        else {
            qDebug() << "无法打开文件进行保存：" << fileName;
        }
    }
}