#include "Point.h"
#include<iostream>
int value;


point::point(int val):value(val) {}  // 构造函数
point::~point() {};           // 析构函数

    // Get 和 Set 方法
int point::getValue() const { return value; }
void point::setValue(int val) { value = val; }

    // 显示方法
void point::display() const {
    std::cout << "Value: " << value << std::endl;
}

    // 操作符重载
point& point::operator++() {
    value++;
    return *this;
}        // 前缀递增
point point::operator++(int) {
    point temp = *this;
    (temp.value)++;
    return *this;

}      // 后缀递增
point& point::operator--() {
    value--;
    return *this;
}        // 前缀递减
point point::operator--(int) {
    point temp = *this;
    (temp.value)--;
    return *this;
}      // 后缀递减
