/*29. 定义Boat与Car两个类，定义一个友元函数计算二者的重量和
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
	Boat(int weight) :weight(weight) {}
	friend int getTotalWeight();
	int get() { return weight; }
private:
	int weight;
};

class Car {
public:
	Car(int weight) :weight(weight) {}
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
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
