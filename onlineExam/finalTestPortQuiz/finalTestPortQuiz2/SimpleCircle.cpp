#include "SimpleCircle.h"
SimpleCircle::SimpleCircle() {
	itsRadius = new int(5);
}      
//默认构造函数
SimpleCircle::SimpleCircle(int r) {
	itsRadius = new int(5);
	*itsRadius = r;
}   
//构造函数
SimpleCircle::SimpleCircle(const SimpleCircle& c){
	int* temp = new int(*(c.itsRadius));

	itsRadius = temp;

}
//复制构造函数

void SimpleCircle::setRadius(int r) {
	int* temp = new int(r);

	itsRadius = temp;
	*itsRadius = r;
}
//对半径赋值
int SimpleCircle::getRadius() const {
	return *itsRadius;
}
//获得指向圆的半径的指针

	