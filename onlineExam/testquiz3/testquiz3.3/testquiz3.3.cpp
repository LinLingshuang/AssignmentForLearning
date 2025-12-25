/*计算Rectangle和Circle以及Square的面积
【问题描述】定义一个基类Shape，在此基础上派生出Rectangle和Circle，
二者带有getArea()函数计算对象的面积。使用Rectangle类创建一个派生类Square()。
请自行完善各类的数据成员和成员函数以及主函数测试语句。

【输入形式】键盘输入Rectangle的长、宽以及Circle的半径

【输出形式】屏幕显示Rectangle、Circle和Square的面积

【样例输入】3.5

           2.5

           1.5
【样例输出】8.75

           7.065

           12.25
【样例说明】Square的边长同Rectangle的长
【评分标准】

*/
#include<iostream>
using namespace std;

class Shape{
public:
    double getArea();
private:
};

class Rectangle :virtual public Shape {
public:
    Rectangle() {};
    Rectangle(double L, double W) :L(L), W(W) {};

    double getArea() { return L * W; }
    double getL() { return L; }
private:
    double L;
    double W;

};
class Square : public Rectangle {
public:
    Square (double L) :L(L) {};
    double getArea() { return L * L; }
private:
    double L;
};

class Circle :virtual public Shape {
public:
    Circle(double r) :r(r) {};
    double getArea() {
        return r * r * 3.14;
    }
private:
    double r;
};
int main() {
    double l, w,r;

    cin >> l >> w >> r;

    Rectangle re(l, w);
    Square se(l);
    Circle c(r);
    cout << re.getArea() << endl << c.getArea() << endl << se.getArea();

}