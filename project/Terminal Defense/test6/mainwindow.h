#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// 前置声明
class QPushButton;
class QLabel;
class QVBoxLayout;
class QWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    // 菜单按钮的槽函数
    void onStartClicked();
    void onHelpClicked();
    void onQuitClicked();
    void onBackClicked();

private:
    void setupMainMenu();      // 设置主菜单界面
    void setupHelpScreen();    // 设置帮助界面

    // 界面组件
    QWidget* centralWidget;
    QVBoxLayout* mainLayout;

    // 主菜单组件
    QLabel* titleLabel;
    QPushButton* startButton;
    QPushButton* helpButton;
    QPushButton* quitButton;

    // 帮助界面组件
    QLabel* helpText;
    QPushButton* backButton;
};

#endif // MAINWINDOW_H
