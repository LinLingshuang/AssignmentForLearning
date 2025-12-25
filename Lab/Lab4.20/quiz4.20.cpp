/*定义一个复数类Complex，使得下面的代码能够工作
Complex c1(3,5);   // 用复数3+5i初始化c1
Complex c2=4.5;    // 用实数4.5初始化c2
c1.add(c2);        // 将c1和c2相加，结果保存在c1中
c1.show();         // 将c1输出，结果应该为7.5+5i

*/

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Complex {
public:
	Complex(double inputreal) {
		real = inputreal;
		unreal = 0;
	}
	Complex(double inputreal,double inputunreal) {
		real = inputreal;
		unreal = inputunreal;
	}
	Complex(){}
	Complex(Complex &c);

	void add(Complex a);
	void show();
	~Complex(){}
private:
	double real;
	double unreal;

};

Complex::Complex(Complex &c){
	real = c.real;
	unreal = c.unreal;

}

void Complex::add(Complex a) {
	real = real + a.real;
	unreal = unreal + a.unreal;
}
void Complex::show() {
	cout << real << "+" << unreal << "i";
}


int main() {
	Complex c1(3, 5);
	Complex c2 = 4.5;
	c1.add(c2);
	c1.show();

}