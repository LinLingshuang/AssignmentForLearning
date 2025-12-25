/*���������Date�������һ��ǰһ���

������������
��Ʒ�������Ҫ���������Date����д������������������������ĸ�ʽ
ӵ�����ݳ�Աyear��month��day���ֱ�洢������
���캯�����������ղ�������ʼ��ȫ�����ݳ�Ա
���г�Ա����toText()����һ��string������Ϊ�����ڶ�������ֱ���ʽ�����硰2024-11-14��
���г�Ա����nextDay()����һ��Date���󣬱�ʾ�����ڵĺ�һ��
���г�Ա����prevDay()����һ��Date���󣬱�ʾ�����ڵ�ǰһ��
��������ʽ��
�� �� �գ��м����һ��
�������ʽ��
Date: ���������, Next Day: ��һ��, Prev Day:ǰһ��
���������롿
1979 1 16

�����������

Date:1979-1-16,Next Day:1979-1-17,Prev Day:1979-1-15

������˵����

Ҫ��ʵ��������Date
������
 ���꣺����һ�򣬰��겻���İ�������
 ������·�Ϊ29�죬��������·�Ϊ28��

#include <iostream>
#include <string>

string toText(){
        char buffer[1024];
        sprintf(buffer,"%d-%d-%d",year,month,day);
        return buffer;
}
*/
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
    bool leapyear=false;
    if ((y % 4 == 0 && y % 100 != 0)||y%400==0){
        leapyear = true; 
    }
    
    switch (m){
    case 1:
        if (d == 1) { py = y - 1; ny = y; pm = 12; nm = m; pd = 31; nd = d + 1; }
        else if (d == 31) { py = y; ny = y; pm = m; nm = m + 1; pd = d - 1; nd = 1; }
        else { py = y; ny = y; pm = m; nm = m; pd = d - 1; nd = d + 1; }
        break;
    case 2:
        if (d == 1) { py = y; ny = y; pm = m - 1; nm = m; pd = 31; nd = d + 1; }
        else if (d == 28 && !leapyear) { py = y; ny = y; pm = m; nm = m + 1; pd = d - 1; nd = 1; }
        else if (d == 28 && leapyear) { py = y; ny = y; pm = m; nm = m ; pd = d - 1; nd = d + 1; }
        else if (d == 29 && leapyear) { py = y; ny = y; pm = m; nm = m + 1; pd = d - 1; nd = 1; }
        else { py = y; ny = y; pm = m; nm = m; pd = d - 1; nd = d + 1; }
        break;
    case 3:
        if (d == 1 && !leapyear) { py = y; ny = y; pm = m - 1; nm = m; pd = 28; nd = d + 1; }
        else if (d == 1 && leapyear) { py = y; ny = y; pm = m - 1; nm = m; pd = 29; nd = d + 1; }
        else if (d == 31) { py = y; ny = y; pm = m; nm = m + 1; pd = d - 1; nd = 1; }
        else { py = y; ny = y; pm = m; nm = m; pd = d - 1; nd = d + 1; }
        break;
    case(5,7,8,10):
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

    cout <<"Date:" << text(y, m, d) << ",Next Day:" << text(ny, nm, nd) << ",Prev Day:" << text(py, pm, pd) << endl;

}