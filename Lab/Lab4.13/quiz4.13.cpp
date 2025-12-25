/*4-13、定义一个Circle类，有数据成员radius（半径），成员函数
getArea()，计算圆的面积。构造一个Circle的对象进行测试。*/
#include<iostream>
using namespace std;

class Circle {
public:
	Circle(double xradius) :radius(xradius) {}
	Circle(Circle& c) {
		radius = c.radius;
	}
	Circle(){}
	double getArea(double radius){
		return PI * radius * radius;
	}
	~Circle() {};
private:
	double radius;
	const double PI = 3.1415926;
};

int main() {
	double input_r = 0;
	Circle testcircle;
	cin >> input_r;
	cout<< testcircle.getArea(input_r);
}