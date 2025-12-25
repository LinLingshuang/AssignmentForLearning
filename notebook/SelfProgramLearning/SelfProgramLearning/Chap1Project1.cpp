/*
1.1
结构化设计：自顶向下、逐步求精，分为顺序、选择、循环
面向对象设计：分类、建立对象、封装
1.2
对象：含有数据（静态）、函数（动态）

2.1字符集
包括：abcdefg....12345....! # % ^ & * () _ - = + {} [] : : "" ,'' . / > < ? \ | ~
ABCDEF....等

2.2关键词
C/C++必须用一般为小写如:try,using,sign,void,if,int,long等

2.3标识符（即取名）
不能是标识符
只能用大小写字母和下划线

2.4操作符
数学运算符=-+/*逻辑运算符and andeq bitand not not_eq or or_eq xor xor_eq

2.5分隔符
() [] {} : , ;

2.6注释// 

*/


// 3.1数据类型之变量
#include<iostream>
using namespace std;

int main() {
	bool Test= true;
	char Test1='s';
	const char*Test2 = "abcd";
	signed char Test3 = 'd';
	unsigned char Test4 = 'f';
	short Test5 = 1;
	unsigned short Test6 =2;
	int Test7 = 345;
	unsigned int Test8 = 455;
	long Test9 = 51324546;
	unsigned long Test10 = 6;
	float Test11 = 7.12;
	double Test12 = 8.3562689;

	cout << Test << " "<< Test1 << " " << Test2 << " " << Test3 << " " << Test4 << " " << Test5 << " " << Test6 << endl;
	cout << Test7 << " " << Test8 << " " << Test9 << " " << Test10 << " " << Test11 << " " << Test12 << endl;
}


