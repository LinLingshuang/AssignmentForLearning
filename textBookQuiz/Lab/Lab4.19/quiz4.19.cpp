/*4-19、编写一个名为CPU的类，描述一个CPU以下的信息：时钟频率，
最大不会超过3000MHz；字长可以是32位或64位；核数可以是单核、
双核或四核；是否支持超线程。各项信息要求使用位域来表示。通过
输出sizeof(CPU)来观察该类的字节数。*/

#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

enum byte{bit32,bit64};
enum core {single,two,four};
enum exceedexe{suppose,notsuppose};

class CPU {
public:
	CPU(int xclockHz=0,byte xbyte=bit32,core xcore=single, exceedexe xexceedexe= notsuppose)
		:clockHz(xclockHz),bytetype(xbyte),coretype(xcore),exceedexetype(xexceedexe){}
	CPU(CPU& c) {
		clockHz = c.clockHz;
		bytetype = c.bytetype;
		coretype = c.coretype;
		exceedexetype = c.exceedexetype;
	}
	void show();
	~CPU(){}
private:
	int clockHz:20;
	byte bytetype:4;
	core coretype:2;
	exceedexe exceedexetype : 4;
};

void CPU::show() {
	cout<<"时钟频率为：" << clockHz << "MHz" << endl;
	switch ((unsigned)bytetype) {
	case bit32:
		cout << "字长为：32位" << endl;
		break;
	case bit64:
		cout << "字长为：64位" << endl;
		break;
	default:
		cout << "字长输入错误" << endl;
		break;
	}
	switch ((unsigned)coretype) {
	case single:
		cout << "核数为：单核" << endl;
		break;
	case two:
		cout << "核数为：双核" << endl;
		break;
	case four:
		cout << "核数为：四核" << endl;
		break;
	default:
		cout << "核数输入错误" << endl;
		break;
	}
	switch ((unsigned)exceedexetype) {
	case suppose:
		cout << "可以超线程" << endl;
		break;
	case notsuppose:
		cout << "不可以超线程" << endl;
		break;
	default:
		cout << "超线程输入错误" << endl;
		break;
	}
	cout << endl;
}



int main() {
	CPU CPU1(2000,bit32,single,suppose);
	CPU CPU2(1000,bit64,two,notsuppose);
	CPU CPU3(3000,bit32,four,suppose);
	cout << sizeof(CPU1) << endl;
	cout << sizeof(CPU2) << endl;
	cout << sizeof(CPU3) << endl;
	
	CPU1.show();
	CPU2.show();
	CPU3.show();
}