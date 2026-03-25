/*18. 时间类Time的编写
【问题描述】
编写一个程序，定义一个时间类Time，包含三个属性： hour, minute 和 second
要求通过运算符重载实现如下功能:
时间输入输出(>>、<<)；
时间增加减少若干(+=、-=)，例：Time& operator+=(const Time&);Time& operator-=(const Time&)；
时间前、后自增加/减少1秒(++、--)，前自增例：Time& operator++(); 后自增例：Time operator++(int)；
【输入形式】
输入固定为两个Time实例(time1，time2),每个实例占一行；
Time实例输入格式为：hour minute second。
【输出形式】
Time实例输出格式为：hour:minute:second；
每个输出实例占一行。
依次输出以下表达式的值
time1 += (time2++)
time1 -= time2
++time2
time2 += (time1--)
--time1
time2 -= time1
【样例输入】
21 10 35
10 15 25
【样例输出】
07:26:00
21:10:34
10:15:27
07:26:01
21:10:32
10:15:29
【样例说明】
不要显示多余的提示信息，避免输出判定错误。
输出结束后不要输出任何内容，包括空格和换行。
注意判断输出信息是否符合要求。*/

#include <iostream>
using namespace std;

class Time {
public:

	Time() :hour(0), minute(0), second(0) {};
	Time(int h, int m, int s) :hour(h), minute(m), second(s) {};


	Time& operator+=(const Time& time){
		
		int tempSecond =this->getSecond() + time.getSecond();
		int tempMinute = this->getMinute() + time.getMinute();
		int tempHour = this->getHour() + time.getHour();
		if (tempSecond >= 60) {
			tempSecond -= 60;
			tempMinute++;
		}
		if (tempMinute >= 60) {
			tempMinute -= 60;
			tempHour++;
		}
		if (tempHour >= 24) {
			tempHour -= 24;
		}
		*this = Time(tempHour, tempMinute,tempSecond );
		return *this;
	}
	Time& operator-=(const Time& time){
		int tempSecond = this->getSecond() - time.getSecond();
		int tempMinute = this->getMinute() - time.getMinute();
		int tempHour = this->getHour() - time.getHour();
		if (tempSecond < 0) {
			tempSecond += 60;
			tempMinute--;
		}
		if (tempMinute < 0) {
			tempMinute += 60;
			tempHour--;
		}
		if (tempHour < 0) {
			tempHour += 24;
		}
		*this = Time(tempHour, tempMinute,tempSecond );
		return *this;

	}
	Time& operator++() {
		int tempSecond = this->getSecond() +1;
		int tempMinute = this->getMinute();
		int tempHour = this->getHour();
		if (tempSecond >= 60) {
			tempSecond -= 60;
			tempMinute++;
		}
		if (tempMinute >= 60) {
			tempMinute -= 60;
			tempHour++;
		}
		if (tempHour >= 24) {
			tempHour -= 24;
		}
		*this = Time(tempHour, tempMinute,tempSecond );
		return *this;
	}
	Time operator++(int) {
		int tempSecond = this->getSecond() + 1;
		int tempMinute = this->getMinute();
		int tempHour = this->getHour();

		int tempSecond1 = this->getSecond();
		int tempMinute1 = this->getMinute();
		int tempHour1 = this->getHour();
		Time temptime(tempHour1,tempMinute1,tempSecond1);

		if (tempSecond >= 60) {
			tempSecond -= 60;
			tempMinute++;
		}
		if (tempMinute >= 60) {
			tempMinute -= 60;
			tempHour++;
		}
		if (tempHour >= 24) {
			tempHour -= 24;
		}
		*this = Time(tempHour, tempMinute,tempSecond );
		return temptime;


	}
	Time& operator--() {
		int tempSecond = this->getSecond() -1;
		int tempMinute = this->getMinute();
		int tempHour = this->getHour();
		if (tempSecond < 0) {
			tempSecond += 60;
			tempMinute--;
		}
		if (tempMinute < 0) {
			tempMinute += 60;
			tempHour--;
		}
		if (tempHour < 0) {
			tempHour += 24;
		}
		*this = Time(tempHour, tempMinute, tempSecond);
		return *this;


	}
	Time operator--(int) {
		int tempSecond = this->getSecond() - 1;
		int tempMinute = this->getMinute();
		int tempHour = this->getHour();

		int tempSecond1 = this->getSecond();
		int tempMinute1 = this->getMinute();
		int tempHour1 = this->getHour();
		Time temptime(tempHour1, tempMinute1, tempSecond1);
		if (tempSecond < 0) {
			tempSecond += 60;
			tempMinute--;
		}
		if (tempMinute < 0) {
			tempMinute += 60;
			tempHour--;
		}
		if (tempHour < 0) {
			tempHour += 24;
		}
		*this = Time(tempHour, tempMinute, tempSecond);
		return temptime;


	}

	int getHour()const { return hour; }
	int getMinute()const { return minute; }
	int getSecond()const { return second; }


	friend istream& operator>>(istream& in,Time& time) {
		int hour,minute,second;
		in >> hour >> minute >> second;
		time = Time(hour, minute, second);
		return in;
	}

	friend ostream& operator<<(ostream& out,Time& time) {
		if (time.getHour() < 10) {
			out << '0' << time.getHour() << ':';
		}
		else {
			out << time.getHour() << ':';
		}
		if (time.getMinute() < 10) {
			out << '0' << time.getMinute() << ':';
		}
		else {
			out << time.getMinute() << ':';
		}
		if (time.getSecond() < 10) {
			out << '0' << time.getSecond();
		}
		else {
			out << time.getSecond();
		}

		out << endl;

		return out;
	}


private:

	int hour;
	int minute;
	int second;

};

int main()
{
	Time time1, time2;
	cin >> time1;
	cin >> time2;
   
	cout<<(time1 += (time2++));
	cout<<(time1 -= time2);
	cout<<(++time2);
	cout<<(time2 += (time1--));
	cout<<(--time1);
	cout<<(time2 -= time1);


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
