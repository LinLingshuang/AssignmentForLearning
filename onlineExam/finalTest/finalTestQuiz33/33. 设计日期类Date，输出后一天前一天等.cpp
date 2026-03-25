/*33. 设计日期类Date，输出后一天前一天等
【问题描述】

设计符合下述要求的日期类Date，编写代码根据输入的日期输出期望的格式

拥有数据成员year、month、day，分别存储年月日

构造函数接收年月日参数并初始化全部数据成员

公有成员函数toText()返回一个string对象，其为该日期对象的文字表达式，比如“2024-11-14”

公有成员函数nextDay()返回一个Date对象，表示该日期的后一天

公有成员函数prevDay()返回一个Date对象，表示该日期的前一天

【输入形式】

年 月 日，中间均空一格

【输出形式】

Date: 输入的日期, Next Day: 后一天, Prev Day:前一天

【样例输入】

1979 1 16

【样例输出】

Date:1979-1-16,Next Day:1979-1-17,Prev Day:1979-1-15

【样例说明】

要求实现日期类Date


其他：

 闰年：四年一闰，百年不闰，四百年又闰

 闰年二月份为29天，非闰年二月份为28天



#include <iostream>

#include <string>



string toText(){

        char buffer[1024];

        sprintf(buffer,"%d-%d-%d",year,month,day);

        return buffer;

}

*/


//方法一：有错误，应该是自己的
#define _CRT_SECURE_NO_WARNINGS


#include<iostream>
#include<string>
using namespace std;

class date {
private:
    int year;
    int month;
    int day;
public:
    date() {};
    date(int ayear, int amonth, int aday) :
        year(ayear),
        month(amonth),
        day(aday)
    {
    };
    string toText(date adate);
    date nextDay(date adate);
    date prevDay(date adate);

};

string date::toText(date adate) {

    char buffer[1024];

    sprintf(buffer, "%d-%d-%d", year, month, day);

    return buffer;

}

date date::nextDay(date adate) {
    if (month == 12 && day == 30) {
        year += 1;
        month = 1;
        day = 1;
        return adate;
    }
    else if ((month <= 7 && month % 2 == 0) || (month > 7 && month % 2 != 0)) {
        if (day == 30) {
            month += 1;
            day = 1;
            return adate;
        }
        else if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (month == 2 && day == 29) {
                month += 1;
                day = 1;
                return adate;
            }
            else if (month == 2 && day == 28) {
                day = 29;
                return adate;
            }
            else {
                day += 1;
                return adate;
            }

        }
        else if (month == 2) {
            if (day == 28) {
                month += 1;
                day = 1;
                return adate;
            }
            else {
                day += 1;
                return adate;
            }
        }
        else {
            day += 1;
            return adate;
        }
    }
    else if ((month <= 7 && month % 2 != 0) || (month > 7 && month % 2 == 0)) {
        if (day == 31) {
            month += 1;
            day = 1;
            return adate;
        }
        else {
            day += 1;
            return adate;
        }
    }


}

date date::prevDay(date adate) {
    if (month == 1 && day == 1) {
        year -= 1;
        month = 12;
        day = 30;
        return adate;
    }
    else if ((month <= 7 && month % 2 == 0) || (month > 7 && month % 2 != 0)) {
        if (day == 1) {
            month -= 1;
            day = 31;
            return adate;
        }
        else {
            day -= 1;
            return adate;
        }
    }
    else if ((month <= 7 && month % 2 != 0) || (month > 7 && month % 2 == 0)) {

        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (month == 3 && day == 1) {
                month -= 1;
                day = 29;
                return adate;
            }
            else if (day == 1) {
                day = 30;
                month -= 1;
                return adate;
            }
            else {
                day -= 1;
                return adate;
            }
        }
        else if (month == 3 && day == 1) {
            month -= 1;
            day = 28;
            return adate;
        }
        else if (day == 1) {
            month -= 1;
            day = 30;
            return adate;
        }
        else {
            day -= 1;
            return adate;
        }
    }




}


int main() {
    int year;
    int month;
    int day;
    cin >> year >> month >> day;
    date mydate(year, month, day);
    date ndate(year, month, day);
    date pdate(year, month, day);
    ndate.nextDay(ndate);
    pdate.prevDay(pdate);

    cout << "Date:" << mydate.toText(mydate) << ",Next Day:" << ndate.toText(ndate) << ",Prev Day:" << pdate.toText(pdate);



}

//方法二：好像是ai的
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

string text(int y, int m, int d) {
    char buffer[1024];
    sprintf(buffer, "%d-%d-%d", y, m, d);
    return buffer;
}


int main() {
    int y, m, d;
    int ny, nm, nd;
    int py, pm, pd;
    cin >> y >> m >> d;
    bool leapyear = false;
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
        leapyear = true;
    }

    switch (m) {
    case 1:
        if (d == 1) { py = y - 1; ny = y; pm = 12; nm = m; pd = 31; nd = d + 1; }
        else if (d == 31) { py = y; ny = y; pm = m; nm = m + 1; pd = d - 1; nd = 1; }
        else { py = y; ny = y; pm = m; nm = m; pd = d - 1; nd = d + 1; }
        break;
    case 2:
        if (d == 1) { py = y; ny = y; pm = m - 1; nm = m; pd = 31; nd = d + 1; }
        else if (d == 28 && !leapyear) { py = y; ny = y; pm = m; nm = m + 1; pd = d - 1; nd = 1; }
        else if (d == 28 && leapyear) { py = y; ny = y; pm = m; nm = m; pd = d - 1; nd = d + 1; }
        else if (d == 29 && leapyear) { py = y; ny = y; pm = m; nm = m + 1; pd = d - 1; nd = 1; }
        else { py = y; ny = y; pm = m; nm = m; pd = d - 1; nd = d + 1; }
        break;
    case 3:
        if (d == 1 && !leapyear) { py = y; ny = y; pm = m - 1; nm = m; pd = 28; nd = d + 1; }
        else if (d == 1 && leapyear) { py = y; ny = y; pm = m - 1; nm = m; pd = 29; nd = d + 1; }
        else if (d == 31) { py = y; ny = y; pm = m; nm = m + 1; pd = d - 1; nd = 1; }
        else { py = y; ny = y; pm = m; nm = m; pd = d - 1; nd = d + 1; }
        break;
    case(5, 7, 8, 10):
        if (d == 1) { py = y; ny = y; pm = m - 1; nm = m; pd = 30; nd = d + 1; }
        else if (d == 31) { py = y; ny = y; pm = m; nm = m + 1; pd = d - 1; nd = 1; }
        else { py = y; ny = y; pm = m; nm = m; pd = d - 1; nd = d + 1; }
        break;
    case(4, 6, 9, 11):
        if (d == 1) { py = y; ny = y; pm = m - 1; nm = m; pd = 31; nd = d + 1; }
        else if (d == 30) { py = y; ny = y; pm = m; nm = m + 1; pd = d - 1; nd = 1; }
        else { py = y; ny = y; pm = m; nm = m; pd = d - 1; nd = d + 1; }
        break;
    case 12:
        if (d == 1) { py = y; ny = y; pm = m - 1; nm = m; pd = 30; nd = d + 1; }
        else if (d == 31) { py = y; ny = y + 1; pm = m; nm = 1; pd = d - 1; nd = 1; }
        else { py = y; ny = y; pm = m; nm = m; pd = d - 1; nd = d + 1; }
        break;
    }

    cout << "Date:" << text(y, m, d) << ",Next Day:" << text(ny, nm, nd) << ",Prev Day:" << text(py, pm, pd) << endl;

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
