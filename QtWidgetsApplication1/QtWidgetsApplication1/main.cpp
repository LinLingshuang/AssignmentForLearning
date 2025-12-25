/**
 * @file main.cpp
 * @brief 游戏应用程序入口点
 * 该文件包含游戏的主函数，负责初始化Qt应用程序并显示主菜单界面
 */

#include "menuWidget.h" ///< 包含主菜单界面类的头文件
#include <QApplication>  ///< 包含Qt应用程序类的头文件

/**
 * @brief 应用程序主函数
 * 程序的入口点，负责创建Qt应用程序实例、主菜单界面实例，并启动事件循环
 * 
 * @param argc 命令行参数数量
 * @param argv 命令行参数数组
 * @return 应用程序退出代码
 */
int main(int argc, char *argv[])
{
    // 创建Qt应用程序实例
    QApplication a(argc, argv);
    
    // 创建主菜单界面实例
    Widget w;
    
    // 显示主菜单界面
    w.show();
    
    // 启动Qt应用程序事件循环
    return a.exec();
}
