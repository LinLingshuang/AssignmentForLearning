// chap7test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
using namespace std;


class base0 {
public:
	base0(int a):a0(a) { cout << "contructing base1"; }
	void fun0();
private:
	int a0;
};
class base1 {
public:
	base1() { cout << "contructing base1"; }
	void fun1();
private:
	int a1;

};
class base2 {
public:
	void fun2();
	//void virtual vfun2();
	void fun() { cout << "base2" << endl; }
private:
	int a2;

};

class base3 {
public:
	void fun3();
	void fun() { cout << "base3" << endl; }

private:
	int a3;

};



class derived0 :public base0 {
public:
	derived0():base0(1) {};
	derived0(int a,int d):base0(a),d0(d){ cout << "contructing derived0"; }

	derived0(derived0 &d) :base0(d) {}

	
private:
	int d0;
};
class derived1 :protected base1 {

	derived1() = default;

};

class derived2 :virtual private base2 {

	derived2(derived2& ) = delete;

};

class derived3 :public base0,public base2,public base3 {
public:
	derived3(int a, int d) :base0(a), d3(d) { cout << "contructing derived3"; }

	void fun() { cout << "derived3" << endl; }

private:
	int d3;
};





int main()
{
	derived3 d3(1,2);

	derived3* p = &d3;

	p->fun();
	p->base2::fun();
	p->base3::fun();
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
