#include "menuWidget.h"
#include "ui_menuWidget.h"
#include "gameWidget.h"
#include "settingsWidget.h"
#include <QDebug>
#include <QFileDialog>  // 包含文件对话框头文件

/**
 * @brief 菜单界面构造函数
 * 初始化菜单界面的UI组件、样式和信号槽连接
 *
 * @param parent 父窗口指针，默认为nullptr
 */
Widget::Widget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , settingsWidget(nullptr)
    , en(nullptr)
{
    ui->setupUi(this);

    this->setWindowTitle("Menu");

    //放置图片
    ui->menuLable->setPixmap(QPixmap(":/picture/menuBackground/menuBackground.png"));

    //设置按钮边框样式
    ui->startButton->setStyleSheet(
        "QPushButton {"
        "    background: transparent;"
        "    border: 8px solid black;"
        "    color: black;"
        "}"
    );

    ui->closeButton->setStyleSheet(
        "QPushButton {"
        "    background: transparent;"
        "    border: 8px solid black;"
        "    color: black;"
        "}"
    );

    // 设置load按钮
    ui->loadButton->setStyleSheet(
        "QPushButton {"
        "    background: transparent;"
        "    border: 8px solid black;"
        "    color: black;"
        "}"
    );

    // 设置设置按钮
    ui->settingsButton->setStyleSheet(
        "QPushButton {"
        "    background: transparent;"
        "    border: 8px solid black;"
        "    color: black;"
        "}"
    );


    // 创建设置界面（设置为独立窗口，不依附于菜单窗口）
    settingsWidget = new SettingsWidget(nullptr);  // nullptr makes it a separate window
    settingsWidget->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    connect(settingsWidget, &SettingsWidget::settingsSaved, this, &Widget::onSettingsSaved);

    // 创建图鉴界面（设置为独立窗口，不依附于菜单窗口）
    en = new EncyclopediaDialog(nullptr);  // nullptr makes it a separate window
    en->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    /*
    m_audioPlayer = new AudioPlayer();
    // ========== 音频播放逻辑（正确写在构造函数内） ==========
    // 预加载音效
    m_audioPlayer->loadSoundEffect("btn_click", "://sounds//music//di.2-new.wav");
    m_audioPlayer->loadSoundEffect("game_start", "://sounds//music//bgm-new.wav");
    m_audioPlayer->playBgm("://sounds//music//bgm-new.wav", 15000);
    */
}

/**
 * @brief 菜单界面析构函数
 * 释放所有动态分配的资源，包括设置界面和UI对象
 */
Widget::~Widget()
{
    delete settingsWidget;
    delete en;
    delete ui;
}

/**
 * @brief 开始游戏按钮点击事件处理
 * 当用户点击开始游戏按钮时调用此函数
 * 关闭当前菜单界面并创建游戏主界面实例
 */
void  Widget::on_startButton_clicked()
{
    this->close();
    // 创建Game实例并传入当前游戏设置
    Game* g = new Game(getGameSettings());
    g->show();  
    if (en) {
        en->close();
    }
    if (settingsWidget) {
        settingsWidget->close();
    }
}

/**
 * @brief 关闭按钮点击事件处理
 * 当用户点击关闭按钮时调用此函数
 * 关闭当前菜单界面
 */
void  Widget::on_closeButton_clicked()
{
    this->close();
}

/**
 * @brief 设置按钮点击事件处理
 * 当用户点击设置按钮时调用此函数
 * 显示设置界面并传入当前游戏设置
 */
void  Widget::on_loadButton_clicked()
{
    // 显示文件选择对话框，让用户选择存档文件
    QString fileName = QFileDialog::getOpenFileName(
        this,                // 父窗口
        tr("加载游戏存档"),   // 对话框标题
        QDir::currentPath(), // 初始目录
        tr("存档文件 (*.sav);;所有文件 (*.*)")  // 文件过滤器
    );

    if (!fileName.isEmpty()) {
        // 关闭当前菜单界面
        this->close();
        
        // 使用带存档文件路径的Game构造函数加载游戏
        Game* g = new Game(fileName, getGameSettings());
        g->show();
    }
}

void  Widget::on_settingsButton_clicked()
{
    if (settingsWidget) {
        // 设置当前设置到设置界面
        settingsWidget->setSettings(gameSettings);
        // 居中显示设置窗口
        settingsWidget->move(this->x() + (this->width() - settingsWidget->width()) / 2,
            this->y() + (this->height() - settingsWidget->height()) / 2);
        // 显示设置界面（作为独立窗口）
        settingsWidget->show();
        settingsWidget->raise();  // 确保窗口在最前面
        settingsWidget->activateWindow();  // 激活窗口以接收键盘事件
    }
}

/**
 * @brief 设置保存事件处理
 * 当设置界面保存设置时，通过信号槽机制调用此函数
 *
 * @param settings 保存的游戏设置对象
 */
void  Widget::onSettingsSaved(const GameSettings& settings)
{
    gameSettings = settings;
    qDebug() << "Settings saved: " <<
        "Sound: " << settings.soundEffectVolume <<
        "Music: " << settings.musicVolume <<
        "Difficulty: " << settings.difficulty;
}

/**
 * @brief 获取当前游戏设置
 * 返回当前保存的游戏设置对象
 *
 * @return 当前游戏设置对象
 */
GameSettings  Widget::getGameSettings() const
{
    return gameSettings;
}


void Widget::on_encyclopediaButton_clicked()
{
    if (en) {
        // 居中显示图鉴窗口
        en->move(this->x() + (this->width() - en->width()) / 2,
            this->y() + (this->height() - en->height()) / 2);
        // 显示图鉴界面（作为独立窗口）
        en->show();
        en->raise();  // 确保窗口在最前面
        en->activateWindow();  // 激活窗口以接收键盘事件
    }
}
