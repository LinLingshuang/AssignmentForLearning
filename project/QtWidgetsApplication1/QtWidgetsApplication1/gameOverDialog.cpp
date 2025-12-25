#include "gameOverDialog.h"
#include <QFont>
#include <QSpacerItem>

/**
 * @brief 游戏失败对话框构造函数
 * 创建游戏失败对话框实例
 * 
 * @param parent 父窗口指针
 */
GameOverDialog::GameOverDialog(QWidget *parent)
    : QDialog(parent),
    layout(nullptr),
    titleLabel(nullptr),
    returnToMenuButton(nullptr),
    exitGameButton(nullptr)
{
    // 设置对话框标题
    setWindowTitle(tr("游戏失败"));
    
    // 设置对话框大小
    setFixedSize(400, 200);
    
    // 设置对话框样式
    setStyleSheet(
        "QLabel { color: #ff0000; font-size: 24px; font-weight: bold; text-align: center; }"
        "QPushButton { background-color: #4a90e2; color: white; font-size: 16px; padding: 10px 20px; border-radius: 4px; border: none; }"
        "QPushButton:hover { background-color: #357abd; }"
        "QPushButton:pressed { background-color: #2a5e9e; }"
        "QDialog { background-color: rgba(0, 0, 0, 0.8); border-radius: 8px; }"
    );
    
    // 创建布局
    layout = new QVBoxLayout(this);
    
    // 创建标题标签
    titleLabel = new QLabel(tr("你的帐篷被怪物摧毁了！"), this);
    titleLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(titleLabel);
    
    // 添加垂直间距
    layout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
    
    // 创建按钮容器布局
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    
    // 创建返回主菜单按钮
    returnToMenuButton = new QPushButton(tr("返回主菜单"), this);
    connect(returnToMenuButton, &QPushButton::clicked, this, &GameOverDialog::on_returnToMenuButton_clicked);
    buttonLayout->addWidget(returnToMenuButton);
    
    // 添加水平间距
    buttonLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    
    // 创建退出游戏按钮
    exitGameButton = new QPushButton(tr("退出游戏"), this);
    connect(exitGameButton, &QPushButton::clicked, this, &GameOverDialog::on_exitGameButton_clicked);
    buttonLayout->addWidget(exitGameButton);
    
    // 将按钮布局添加到主布局
    layout->addLayout(buttonLayout);
    
    // 添加垂直间距
    layout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
    
    // 设置主布局
    setLayout(layout);
}

/**
 * @brief 游戏失败对话框析构函数
 * 释放对话框资源
 */
GameOverDialog::~GameOverDialog()
{
    // 所有控件都有父对象，会自动被销毁，不需要手动删除
}

/**
 * @brief 返回主菜单按钮点击事件处理
 * 当用户点击返回主菜单按钮时调用，发送returnToMenu信号
 */
void GameOverDialog::on_returnToMenuButton_clicked()
{
    emit returnToMenu();
    close();
}

/**
 * @brief 退出游戏按钮点击事件处理
 * 当用户点击退出游戏按钮时调用，发送exitGame信号
 */
void GameOverDialog::on_exitGameButton_clicked()
{
    emit exitGame();
    close();
}