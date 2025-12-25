/**
 * @file towerButton.h
 * @brief 炮塔按钮类头文件
 * 定义了游戏中用于选择炮塔的按钮类TowerButton
 */
#ifndef TOWERBUTTON_H
#define TOWERBUTTON_H

#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QSize>
#include <QEvent>
#include <QEnterEvent>
#include "tower.h"

/**
 * @brief 炮塔按钮类
 * 继承自QPushButton，用于游戏中选择不同类型的炮塔
 */
class TowerButton : public QPushButton
{
    Q_OBJECT
public:
    /**
     * @brief 构造函数
     * 创建炮塔按钮实例
     * 
     * @param str 炮塔名称
     * @param parent 父窗口指针
     */
    explicit TowerButton(QString str, TowerType type,QWidget *parent = nullptr);

    /**
     * @brief 鼠标进入事件处理
     * 当鼠标光标进入按钮区域时调用
     * 
     * @param event 鼠标进入事件对象
     */
    void enterEvent(QEnterEvent *event) override;
    
    /**
     * @brief 鼠标离开事件处理
     * 当鼠标光标离开按钮区域时调用
     * 
     * @param event 鼠标离开事件对象
     */
    void leaveEvent(QEvent *) override;
    
	// 添加切换图片的公有方法


	void switchToNormal() { setNormalPic(); }  // 切换到普通状态图片

	void switchToSelect() { setSelectPic(); }  // 切换到选中状态图片

	void switchToLack() { setLackPic(); }      // 切换到资源不足状态图片

    

    TowerType getTowerType() { return type; }

    bool enoughOrNot() { return isEnough; }
    void setEnough(bool on);
    
  
    /**
    * @brief 获取按钮大小
    *
    * @return 按钮的大小
    */
    QSize getSize() { return buttonSize; }
signals:

    void towerSelected(TowerType type); // 当炮塔按钮被选中时发出信号
    void towerDeselected();             // 当炮塔按钮被取消选中时发出信号

  
protected:
    /**
     * @brief 设置普通状态图片
     * 设置按钮默认状态下的显示图片
     */
    void setNormalPic();
    
    /**
     * @brief 设置选中状态图片
     * 设置按钮被选中或鼠标悬停时的显示图片
     */
    void setSelectPic();
    
    /**
     * @brief 设置资源不足状态图片
     * 当玩家资源不足以建造该炮塔时显示的图片
     */
    void setLackPic();

private:
    QString name;       // 炮塔名字
    QSize buttonSize;   // 炮塔按钮的宽高

    
    TowerType type;
    
    bool isEnough = false;

};

#endif // TOWERBUTTON_H
