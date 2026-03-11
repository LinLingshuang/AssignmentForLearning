/*编写程序提示用户输入一个十进制整数，分别用十进制、八进制和十六进制的形式输出*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "请输入一个十进制整数" << endl;

	int input;

	cin >> input;

	cout << setiosflags(ios_base::dec) << "输出十进制"<<input << endl
		<< resetiosflags(ios_base::dec) 
		<< setiosflags(ios_base::oct) << "输出八进制"<<input << endl
		<< resetiosflags(ios_base::oct)
		<< setiosflags(ios_base::hex) << "输出十六进制"<<input << endl;


}
