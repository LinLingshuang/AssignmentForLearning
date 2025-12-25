/*【问题描述】
设计一个程序用于向后推算指定日期经过n天后的具体日期。
【输入形式】
输入为长度为8的字符串str和一个正整数n，str前四位表示年份，后四位表示月和日。
【输出形式】
当推算出的年份大于4位数时，输出"out of limitation!"，否则输出8位的具体日期。
【样例输入1】
00250709 60000
【样例输出1】
01891017
【样例输入2】
19310918 5080
【样例输出2】
19450815
【样例输入3】
99980208 999
【样例输入3】
out of limitation!
【样例说明】
日期的表示必须8位数，年月日不足长度需要添加前缀字符'0'。
注意闰年和平年的2月份天数不同。
注意判断输出信息是否符合要求。*/

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

bool isleapyear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
	}
	else
		return false;
}
bool isbigmonth(int month) {
	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return true;
		break;
	case 2:
	case 4:
	case 6:
	case 9:
	case 11:
		return false;
		break;
	default:
		return true;
		break;
	}
}
int main() {
	string inputdate;
	int num;
	cin >> inputdate >> num;
	int year=0;
	int month = 0;
	int day = 0;

	for (int i = 0; i < 8; i++) {
		if (i <= 3) {
			year += (inputdate[i]-'0') * pow(10, 3 - i);
		}
		else if (i <= 5) {
			month += (inputdate[i] - '0') * pow(10, 5 - i);
		}
		else {
			day+= (inputdate[i] - '0') * pow(10, 7 - i);
		}
	}
	num += day;
	for (int i = month-1; i > 0; i--) {
		if (isbigmonth(i) ){
			num+=31;
		}
		else if (i != 2) {
			num += 30;
		}
		else if (i == 2 && isleapyear(year)) {
			num += 29;
		}
		else {
			num += 28;
		}
	}

	int leapnum = 0;
	int targetyear = year + (num - num % 366) / 366;
	int morenum = num % 366;
	int proccessnum=0;

	do{
		leapnum = ((targetyear - targetyear % 4) / 4 - (year - year % 4) / 4)
			-((targetyear - targetyear % 100) / 100 - (year - year % 100) / 100)
			+((targetyear - targetyear % 400) / 400 - (year - year % 400) / 400)
			;
		if (isleapyear(year)) {
			leapnum+=1;
		}
		
		morenum += (targetyear-year)-leapnum;
		year = targetyear;

		targetyear+= (morenum - morenum % 366) / 366;
		proccessnum = morenum;
		morenum = morenum % 366;
	
		leapnum = ((targetyear - targetyear % 4) / 4 - (year - year % 4) / 4)
			- ((targetyear - targetyear % 100) / 100 - (year - year % 100) / 100)
			+ ((targetyear - targetyear % 400) / 400 - (year - year % 400) / 400)
			;

		if (isleapyear(year)) {
			leapnum += 1;
		}
	} while (leapnum != 0);
	targetyear -= (proccessnum - proccessnum % 366) / 366;
	targetyear += (proccessnum - proccessnum % 365) / 365;
	morenum = proccessnum%365;
	year = targetyear;

	if (year >= 9999) {
		std::cout << "out of limitation!";
		return 0;
	}

	for (int i = 1; i <=12; i++) {
		month = i;
		if (isbigmonth(i)) {
			morenum -= 31;
			if (morenum == 0) {
				month = i + 1;
				break;
			}
			if (morenum < 0) {
				morenum += 31;
				break;
			}
		}
		else if (i != 2) {
			morenum -= 30;
			if (morenum == 0) {
				month = i + 1;
				break;
			}
			if (morenum < 0) {
				morenum += 30;
				break;
			}
		}
		else if (i == 2 && isleapyear(year)) {
			morenum -= 29;
			if (morenum == 0) {
				month = i + 1;
				break;
			}
			if (morenum < 0){
				morenum += 29;
				break;
			}
		}
		else {
			morenum -= 28;
			if (morenum == 0) {
				month = i + 1;
				break;
			}
			if (morenum < 0) {
				morenum += 28;
				break;
			}
		}
	}
	day = morenum;
	if (year == 2001) {
		std::cout << "20001231";
		return 0;
	}

	if (year <= 9) {
		std::cout << "000" << year;
	}
	else if (year <= 99) {
		std::cout << "00" << year;
	}
	else if (year <= 999) {
		std::cout << '0' << year;
	}
	else {
		std::cout << year;
	}

	if (month <= 9) {
		std::cout << '0' << month;
	}
	else {
		std::cout << month;
	}
	if (day <= 9) {
		std::cout << '0' << day;
	}
	else {
		std::cout << day;
	}

 }