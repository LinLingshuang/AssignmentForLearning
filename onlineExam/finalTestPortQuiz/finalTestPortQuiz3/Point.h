#ifndef POINT_H
#define POINT_H

#include <iostream>

class point {
    //由于希冀平台显示限制，此处类的实现逻辑跟Point类重载填空题不同！
private:
    int value;

public:
    point(int val = 0);  // 构造函数
    ~point();           // 析构函数

    // Get 和 Set 方法
    int getValue() const;
    void setValue(int val);

    // 显示方法
    void display() const;

    // 操作符重载
    point& operator++();        // 前缀递增
    point operator++(int);      // 后缀递增
    point& operator--();        // 前缀递减
    point operator--(int);      // 后缀递减
};

#endif // POINT_H


