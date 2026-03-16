/*
3.2数据类型之常量


*/
#include<iostream>
using namespace std;

int main() {
	//数值常量
	234;//这是个常量
	487L;//这也是常量
	0x5af;//十六进制
	0.3454E+2;//指数10的2次方，E、e都可以
	-34.4E-5;
	0123;//八进制
	12.3f;//浮点数

	int Test = 0x5af;//1455
	float Test1 = 10e-3;//0.01

	cout << Test <<" " << Test1<<endl;
	
	//字符、字符串常量
	'a';
	'?';
	'\a';//转意常量
	'\n';
	'\'';
	'\0';

	"This is a string.";
	"Please enter\"Yes\"or\"no\"";//字符串常量

	const float PI = 3.1415926;

	cout << PI <<" " << "Please enter\"Yes\"or\"no\"" <<" " << 'l' <<" "<< 10e-3;
}