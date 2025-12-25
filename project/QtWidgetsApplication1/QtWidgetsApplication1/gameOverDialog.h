#ifndef GAMEOVERDIALOG_H
#define GAMEOVERDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

/**
 * @brief 游戏失败对话框类
 * 当游戏失败时显示的对话框，包含返回主菜单和退出游戏选项
 */
class GameOverDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief 构造函数
     * 创建游戏失败对话框实例
     * 
     * @param parent 父窗口指针
     */
    explicit GameOverDialog(QWidget *parent = nullptr);
    
    /**
     * @brief 析构函数
     * 释放对话框资源
     */
    ~GameOverDialog();

signals:
    /**
     * @brief 返回主菜单信号
     * 当用户点击返回主菜单按钮时发送此信号
     */
    void returnToMenu();
    
    /**
     * @brief 退出游戏信号
     * 当用户点击退出游戏按钮时发送此信号
     */
    void exitGame();

private slots:
    /**
     * @brief 返回主菜单按钮点击事件处理
     * 当用户点击返回主菜单按钮时调用
     */
    void on_returnToMenuButton_clicked();
    
    /**
     * @brief 退出游戏按钮点击事件处理
     * 当用户点击退出游戏按钮时调用
     */
    void on_exitGameButton_clicked();

private:
    QVBoxLayout *layout;          // 垂直布局
    QLabel *titleLabel;           // 标题标签
    QPushButton *returnToMenuButton;  // 返回主菜单按钮
    QPushButton *exitGameButton;       // 退出游戏按钮
};

#endif // GAMEOVERDIALOG_H