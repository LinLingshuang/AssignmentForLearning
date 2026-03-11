#include<iostream>
using namespace std;

class Clock{ //时钟类的定义 
	//外部接口,公有成员函数
public:
	void setTime(int newH=0,int newM=0,int newS=0);//=0的部分是初始化
	void showTime();
	//私有数据成员
private:
	int hour, minute, second;
};
//时钟类成员函数的具体实现
 void Clock::setTime(int newH, int newM, int newS)
{
	 hour = newH;
	 minute = newM;
	 second = newS;
}

 inline void Clock::showTime() {
	 cout << hour << ":" << minute << ":" << second << endl;
 }
		//主函数
 int main() {
	 Clock myClock;
	 //定义对象 myclock
	 cout << "First time set and output;" << endl;
	 myClock.setTime();
	 myClock.showTime();
	 //设置时间为默认值
	 //显示时间
	 cout << "Second time set and output:" << endl;
	 myClock.setTime(8, 30, 30);
	 //设置时间为8:30:30
	 myClock.showTime();
	 //显示时间
	 return 0;
 }