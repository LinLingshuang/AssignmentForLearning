#include <iostream>
using namespace std;

// 定义日期结构体
struct Date {
    int year;
    int month;
    int day;
};

// 判断闰年
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取某月的天数
int getDaysInMonth(int year, int month) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month];
}

// 计算从公元1年1月1日到给定日期的总天数
int calculateTotalDays(const Date& date) {
    int totalDays = 0;
    
    // 加上所有完整年份的天数
    for (int y = 1; y < date.year; y++) {
        totalDays += isLeapYear(y) ? 366 : 365;
    }
    
    // 加上当前年份中到给定月份之前的天数
    for (int m = 1; m < date.month; m++) {
        totalDays += getDaysInMonth(date.year, m);
    }
    
    // 加上当前月份的天数
    totalDays += date.day;
    
    return totalDays;
}

// 计算两个日期之间的天数差
int calculateDaysDifference(const Date& date1, const Date& date2) {
    return calculateTotalDays(date2) - calculateTotalDays(date1);
}

int main() {
    Date date1, date2;
    
    // 读取第一个日期
    cin >> date1.year >> date1.month >> date1.day;
    
    // 读取第二个日期
    cin >> date2.year >> date2.month >> date2.day;
    
    // 计算并输出天数差
    int difference = calculateDaysDifference(date1, date2);
    cout << difference << endl;
    
    return 0;
}