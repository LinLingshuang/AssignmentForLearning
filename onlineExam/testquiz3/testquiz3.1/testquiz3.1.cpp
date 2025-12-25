/*1. 定义Boat与Car两个类，定义一个友元函数计算二者的重量和
【问题描述】定义Boat与Car两个类，二者都有weight属性，定义二者的一个友元函数getTotalWeight(),计算二者的重量和

【输入形式】用户从键盘输入Boat和Car的重量值，用空格分隔

【输出形式】对每组输入的重量值，使用友元函数getTotalWeight(),计算二者的重量和

【样例输入】66 77

【样例输出】143

【样例说明】66和77分别代表Boat和Car的重量值*/
#include<iostream>
using namespace std;


class Boat {
public:
	Boat(int weight) :weight(weight){}
	friend int getTotalWeight();
	int get() { return weight; }
private:
	int weight;
};

class Car {
public:
	Car(int weight):weight(weight) {}
	friend int getTotalWeight();
	int get() { return weight; }
private:
	int weight;
};

int  getTotalWeight(Boat b, Car c) {

	return b.get() + c.get();

}
int main() {
	int b, c;
	cin >> b >> c;
	Boat myb(b);
	Car myc(c);
	cout << getTotalWeight(myb, myc);

}