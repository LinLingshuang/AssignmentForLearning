/*请编写一个抽象类Shape，在此基础上派生出Rectangle类和Circle类，
两者都有计算对象面积的函数getArea()、计算对象周长的函数getPerim()*/

#include<iostream>
using namespace std;

#define Pi 3.1415926;

class Shape {
public:

	virtual double getArea() = 0;
	virtual double getPerim() = 0;

private:


};

class Rectangle:public Shape {
public:
	Rectangle(double h = 0, double w = 0) : heigth(h), width(w){}
	double getArea() { return heigth * width; }
	double getPerim() { return heigth * 2 + width * 2; }
private:
	double heigth;
	double width;

};

class Circle :public Shape {
public:
	Circle(double r = 0) :redium(r) {}
	double getArea() { return  redium * redium * Pi; }
	double getPerim() { return 2 * redium * Pi; }


private:
	double redium;
};



int main() {
	Rectangle r(10, 1.5);
	Circle c(3);
	cout << r.getArea() << " " << r.getPerim() << endl;
	cout << c.getArea() << " " << c.getPerim() << endl;


}