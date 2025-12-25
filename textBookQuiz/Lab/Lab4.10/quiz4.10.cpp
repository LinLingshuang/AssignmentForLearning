/*4-10、设计一个用于人事管理的“人员”类。由于考虑到通用性，这
里只抽象出所有类型人员都具有的属性：编号、性别、出生日期、身
份证号等。其中“出生日期”声明为一个内嵌子对象“日期”
。用成员函数实现对人员信息的录入和显示。要求包括：构造函数和析构函
数、复制 构造函数、内联成员函数、带默认形参值的成员函数、类的
组合。*/

#include<iostream>
using namespace std;

class date {
public:
	date(int y = 0, int m = 0, int d = 0) {  //date的构造函数，内联函数
		year = y;
		month = m;
		day = d;
	};
	void showdate() {  //显示日期
		if (inputYN) {
			cout << "生日是：" << year << "年" << month << "月" << day << "日" << endl;
		}
		else cout << "输入日期有误" << endl;
	}
	void rewritedate(){  //录入日期
		cout << "请输入年月日(空格间隔)：" ;
		cin >> year >> month >> day;
		if (month <= 0 || month >= 13||day<=0||day>=32)inputYN = false;
	}

	date(date& d);  //复制构造函数
	~date() {};  //析构函数
private:
	int year;
	int month;
	int day;
	bool inputYN = true;
};

date::date(date &d){  //复制构造函数的实现
	year = d.year;
	month = d.month;
	day = d.day;
}


class staff {
public:
	staff(int staffnum0, int sex0, date borndate0, int IDnum0);//构造函数
	staff();
	staff(staff& s);   //复制构造函数
	void showstaff() {
		cout << "---------------------" << endl;
		cout << "显示录入信息，请核对" << endl;
		cout << "---------------------" << endl;
		if (sex == 1) {
			cout << "编号是：" << staffnum << endl << "性别是：" << "男" << endl;
		}
		else if (sex == 0) {
			cout << "编号是：" << staffnum << endl << "性别是：" << "女" << endl;
		}
		else {
			cout << "编号是：" << staffnum << endl << "性别输入" << "错误" << endl;
		}
		borndate.showdate();
		cout << "身份证号是：" << IDnum<<endl;
	};
	void rewritestaff() {
		cout <<"请输入人员编号：";
		cin >> staffnum;
		cout <<"请输入人员性别：";
		cin >> sex;
		borndate.rewritedate();
		cout << "请输入人员身份证号：";
		cin >> IDnum;
	};
	~staff(){};  //析构函数
private:
	int staffnum;
	int sex;
	date borndate;
	int IDnum;
};
staff::staff(int staffnum0, int sex0, date borndate0, int IDnum0):staffnum(staffnum0),sex(sex0),borndate(borndate0),IDnum(IDnum0){} //构造函数的实现
staff::staff() :staffnum(0), sex(0), borndate(0,0,0), IDnum(0) {}  //默认构造函数
staff::staff(staff &s):staffnum(s.staffnum),sex(s.sex),borndate(s.borndate),IDnum(s.IDnum){}  //复制构造函数

int main() {
	cout << "---------------------" << endl;
	cout << "人事管理录入与显示系统" << endl;
	date defaultdate;
	staff input;
	cout << "---------------------" << endl;
	cout << "显示默认日期" << endl;
	defaultdate.showdate();
	cout << "---------------------" << endl;
	cout << "输入数字以0为女，1为男" << endl;
	cout << "---------------------" << endl;
	input.rewritestaff();
	input.showstaff();
	cout << "---------------------" << endl;
	cout << "录入已完成，请重启程序" << endl;
	cout << "---------------------" << endl;
}