/*6-20 声明一个参数为int类型、返回值为long型的函数指针；声明类A的一个成员函数指针，其参数为int型，返回值long型*/
#include<iostream>
using namespace std;



long fun1(int x) {
	return x;
}

class A {
public:
	long fun2(int y) {
		return y;
	}
	
};


int main() {
	long (*p1)(int);
	p1 = fun1;
	cout<<p1(100)<<endl;
	long(A:: * p2)(int);
	p2 = &A::fun2;
	A test;
	cout<<(test.*p2)(200);
}