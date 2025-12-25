#ifndef PAUSEDIALOG_H
#define PAUSEDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
    class PauseDialog;
}
QT_END_NAMESPACE

/**
 * @brief 暂停对话框类
 * 当游戏暂停时显示的对话框，包含保存并退出和继续游戏选项
 */
class PauseDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief 构造函数
     * 创建暂停对话框实例
     * 
     * @param parent 父窗口指针
     */
    explicit PauseDialog(QWidget *parent = nullptr);
    
    /**
     * @brief 析构函数
     * 释放对话框资源
     */
    ~PauseDialog();

signals:
    /**
     * @brief 保存并退出信号
     * 当用户点击保存并退出按钮时发送此信号
     */
    void saveAndExit();
    
    /**
     * @brief 继续游戏信号
     * 当用户点击继续按钮时发送此信号
     */
    void continueGame();

private slots:
    /**
     * @brief 保存并退出按钮点击事件处理
     * 当用户点击保存并退出按钮时调用
     */
    void on_saveExitButton_clicked();
    
    /**
     * @brief 继续按钮点击事件处理
     * 当用户点击继续按钮时调用
     */
    void on_continueButton_clicked();

private:
    Ui::PauseDialog *ui;  // UI界面指针
};

#endif // PAUSEDIALOG_H
