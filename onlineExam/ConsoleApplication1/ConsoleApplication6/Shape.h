/*3.
请在下列抽象类Shape的声明文件Shape.h的代码中，补齐部分注释要求达成的内容，
实现子类Rectangle和Circle对父类Shape的继承，和对应矩形、圆形的面积、周长计算：
*/
// Shape.h

#ifndef SHAPE_H

#define SHAPE_H

#include <iostream>

// 定义Shape类

class Shape {

public:

    // 纯虚函数：计算面积和周长
    virtual double getArea() const = 0;// 如果复制注释中的提示语句，请务必检查符号是否是中文。请写出如何构建纯虚函数的代码。
    // 此行为面积，Area，注意大小写。方法为使用get函数getArea()，类型为double，不要遗漏";"


    virtual double getPerim() const = 0;//请写出如何构建纯虚函数的代码。此行为周长，Perim，注意大小写。
    // 方法为使用get函数getPerim()，类型为double,不要遗漏";"
// 纯虚函数：显示名称

    virtual void display() const = 0;

    // 虚函数声明

    virtual ~Shape() {}//请写出对应Shape类的虚函数声明语句，注意不要遗漏"{}"，且注意该行不是";"结尾！
};
// 定义Rectangle类，继承Shape类

class Rectangle :public Shape {//提示已告知此处是Rectangle子类，用于继承Shape类，
    //则此行是使用class来实现对public Shape的继承方法，同时注意行末已有"{"，所以不要重复
private:
    double width;
    double height;
public:

    // 构造函数和析构函数


    Rectangle() {};//既然定义的是Rectangle子类，那此行就是Rectangle子类的构造函数，不要遗漏";"


    Rectangle(double w, double h) :width(w), height(h) {};//往下查看set函数可以发现，Rectangle子类用于计算的是"w"和"h"，
    //且类型为double，不要遗漏";"


//Rectangle子类的析构函数，注意不要遗漏"{}"，且注意该行不是";"结尾！

    // get函数
    double getWidth() const { return 0; };
    double getHeight() const { return 0; };

    // set函数

    void setWidth(double w) {};
    void setHeight(double h) {};

    // 实现抽象方法


    double getArea() const override { return 0; };//面积。第三行的显示中已有实现方法的提示，即使用"override"，让Rectangle子类重载Shape基类中的getArea()函数，类型仍然是double，不要遗漏";"


    double getPerim() const override { return 0; };//周长。方法同上一行。

    void display() const override { std::cout << "这是长方形" << std::endl; };

};



// 定义Circle类，继承Shape类

class Circle :public Shape {//对照Rectangle子类，使用class实现Circle子类对public Shape的继承。注意事项同上。

private:
    double radius;
public:

    // 构造函数和析构函数

    Circle() {}//对照Rectangle子类的实现方法，实现Circle子类的构造函数，不要遗漏";"
    Circle(double r) :radius(r) {};//下面set函数已提示为"double r"，不要遗漏";"

    //对照Rectangle子类的实现方法，实现Circle子类的析构函数。注意事项同上。

        // get函数
    double getRadius() const { return 0; };
    // set函数
    void setRadius(double r) {};
    // 实现抽象方法
    // 
    double getArea() const override { return 0; };//面积。对照Rectangle子类的实现方法，实现Circle子类的面积计算，不要遗漏";"


    double getPerim() const override { return 0; };//周长。对照Rectangle子类的实现方法，实现Circle子类的周长计算，不要遗漏";"

    void display() const override { std::cout << "这是圆" << std::endl; };

};

#endif // SHAPE_H


