#include "pausedialog.h"
#include "ui_pausedialog.h"

/**
 * @brief 暂停对话框构造函数
 * 
 * @param parent 父窗口指针
 */
PauseDialog::PauseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PauseDialog)
{
    ui->setupUi(this);
    // 设置对话框为模态
    this->setModal(true);
}

/**
 * @brief 暂停对话框析构函数
 */
PauseDialog::~PauseDialog()
{
    delete ui;
}

/**
 * @brief 保存并退出按钮点击事件处理
 * 发射saveAndExit信号
 */
void PauseDialog::on_saveExitButton_clicked()
{
    emit saveAndExit();
    this->close();
}

/**
 * @brief 继续按钮点击事件处理
 * 发射continueGame信号
 */
void PauseDialog::on_continueButton_clicked()
{
    emit continueGame();
    this->close();
}