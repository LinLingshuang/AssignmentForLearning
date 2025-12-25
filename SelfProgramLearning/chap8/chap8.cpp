// chap8.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class base0 {
public:


    virtual void vfun() = 0;


    int operator=(int) { return 0; }

    int  fun() {
        base0 b;
        return b = 2;
    }

private:

    int a;
};

class base1 {
public:


    int& operator++(){}//前置单目

    int operator++(int) {}//后置 单目

    friend ostream& operator<<(ostream &out,int a) {}//双目

    friend int operator-(base1 a,int b){}

    // -> [] () =
private:



};


class base2 {
public:

    virtual void fun() { cout << "base2"; }
    void fun1();
    virtual void fun2() { cout << "base2"; }
private:



};


class derived :public base2 {
public:
    void fun()override;
    void fun1()override;
    void fun2()final;

private:


};

int main()
{
    int a = 1;
    cout << a<<endl;
    base0 b;
    cout << b.fun();
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
