//SimpleCircle.h
#ifndef _SimpleCircle_H
#define _SimpleCircle_H
class SimpleCircle
{
public:
	SimpleCircle();      //默认构造函数
	SimpleCircle(int);   //构造函数
	SimpleCircle(const SimpleCircle&); //复制构造函数
	~SimpleCircle() {}   //析构函数
	void setRadius(int);     //对半径赋值
	int getRadius() const;   //获得指向圆的半径的指针
private:
	int* itsRadius;         //指向圆半径值的指针
};
#endif  //_SimpleCircle_H
