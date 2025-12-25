/**
 * @file structVector.h
 * @brief 二维向量结构体头文件
 * 定义了Vector2结构体，用于处理游戏中的二维位置、速度和方向等向量计算
 */

#ifndef STRUCTVECTOR_H
#define STRUCTVECTOR_H

#include <cmath>  ///< 包含数学函数库，用于sqrt等计算

/**
 * @brief 二维向量结构体
 * 用于表示二维空间中的点、向量、位置、速度等，提供基本的向量运算功能
 */
struct Vector2
{
    float x;  ///< 向量的X分量
    float y;  ///< 向量的Y分量

    /**
     * @brief 构造函数
     * 创建一个二维向量实例
     * 
     * @param x X分量的初始值（默认为0）
     * @param y Y分量的初始值（默认为0）
     */
    Vector2(float x = 0, float y = 0) : x(x), y(y) {}

    /**
     * @brief 计算到另一个向量的距离
     * 
     * @param other 目标向量
     * @return 两个向量之间的欧几里得距离
     */
    float distanceTo(const Vector2& other) const {
        float dx = other.x - x;  // X方向的差值
        float dy = other.y - y;  // Y方向的差值
        return std::sqrt(dx * dx + dy * dy);  // 计算欧几里得距离
    }

    /**
     * @brief 获取单位向量
     * 将当前向量归一化，保持方向不变但长度为1
     * 
     * @return 归一化后的单位向量
     */
    Vector2 normalized() const {
        float len = std::sqrt(x * x + y * y);  // 计算向量长度
        return len > 0 ? Vector2(x / len, y / len) : *this;  // 归一化，避免除以0
    }

    /**
     * @brief 向量加法运算符重载
     * 
     * @param other 要相加的向量
     * @return 两个向量相加后的结果
     */
    Vector2 operator+(const Vector2& other) const { 
        return Vector2(x + other.x, y + other.y); 
    }

    /**
     * @brief 向量减法运算符重载
     * 
     * @param other 要减去的向量
     * @return 两个向量相减后的结果
     */
    Vector2 operator-(const Vector2& other) const { 
        return Vector2(x - other.x, y - other.y); 
    }

    /**
     * @brief 向量标量乘法运算符重载
     * 
     * @param scalar 要乘以的标量值
     * @return 向量与标量相乘后的结果
     */
    Vector2 operator*(float scalar) const { 
        return Vector2(x * scalar, y * scalar); 
    }
};

#endif // STRUCTVECTOR_H
