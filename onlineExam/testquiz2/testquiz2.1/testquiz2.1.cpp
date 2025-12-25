/*【问题描述】定义Boat与Car两个类，二者都有weight属性，定义二者的一个友元函数getTotalWeight(),计算二者的重量和
【输入形式】用户从键盘输入Boat和Car的重量值，用空格分隔
【输出形式】对每组输入的重量值，使用友元函数getTotalWeight(),计算二者的重量和
【样例输入】66 77
【样例输出】143
【样例说明】66和77分别代表Boat和Car的重量值*/
#include<iostream>
using namespace std;

class boat {
public:
	boat(int w):w(w) {
	}

	friend  int getTotalWeight();


	int getw() {
		return w;

	}

private:
	int w;

};
class car {

public:

	car(int w) :w(w) {


	}

	int getw() { return w; }


	friend int getTotalWeight();

private:

	int w;




 };

int getTotalWeight(car c,boat b) {

	return c.getw() + b.getw();

}



int main() {
	int w1, w2;
	cin >> w1 >> w2;


	boat b(w1);

    car c(w2);


	cout << getTotalWeight(c, b);


}