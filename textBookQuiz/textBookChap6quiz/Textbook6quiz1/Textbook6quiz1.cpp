/*6-18 改正下列程序*/

#include<iostream>
using namespace std;

int fn1() {
	int* p = new int(5);
	int val = *p;//以下为修改
	delete p;//修改
	p = nullptr;//修改
	return val;
}

int main() {
	int a = fn1();
	cout << "the value of a is:" << a;
	return 0;
}