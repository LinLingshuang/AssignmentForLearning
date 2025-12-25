/*6-8 声明一个int型指针，用new语句为其分配包含十个元素的地址空间*/
#include<iostream>
using namespace std;
int main() {
	int* ptr = new int[10]();


	delete[]ptr;
}