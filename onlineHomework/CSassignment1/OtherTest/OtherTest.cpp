// OtherTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
#include <iostream>

int main()
{
    int x = 10, y = 9;
    int a, b, c;
    a = (--x == y++) ? --x : ++y;
    b = x++;
    c = y;
    printf("%d %d %d", a, b, c);
    return 0;
}
*/
/*
#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    int i;
    cout << "Right justification\n";
    for (i = 0; i < 3; i++)
    {
        cout.width(5);
        cout << setiosflags(ios::right) << i;
    }
    cout << "\nLeft justification\n";
    for (i = 0; i < 3; i++)
    {
        cout.width(5);
        cout << setiosflags(ios::left) << i;
    }
}
*/
/*
#include <stdio.h>
long fib(int x)
{
    switch (x)
    {
    case 0: return 0;
    case 1:
    case 2:  return 1;
    }
    return (fib(x - 1) + fib(x - 2));
}
int main()
{
    int x = 6;
    printf("%d\n", fib(x));
    return 0;
}

*/
/*
#include<stdio.h>
int fun2(int a, int b)
{
    int c;
    c = a * b % 3;
    return c;
}
int fun1(int a, int b)
{
    int c;
    a += a;
    b += b;
    c = fun2(a, b);
    return  c * c;
}
int main()
{
    int x = 11, y = 19;
    printf("%d\n", fun1(x, y));
    return 0;
}
*/
/*
#include<stdio.h>
void main()
{
    int x;
    for (x = 1; x < 100; x++)
        if (++x % 2 == 0)
            if (++x % 3 == 0)
                if (++x % 5 == 0)
                    printf("%d ", x);
}
*/
/*
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    char x = 'A', y = 'B';
    (x = 'B') || (y = 'C');
    cout << x << y << endl;
        return 0;
}
*/
/*
#include <iostream>

using namespace std;

int main()

{

    unsigned int x, y = 100, z = 50;

    x = z - y;

    cout << "x = " << x << endl;

    return 0;

}
*/
/*
#include <iostream>

using namespace std;

int main()
{

    float a, b = 4.8f;

    int i;

    i = b / 3;

    a = b / 3;

    cout << "i=" << i << ",a=" << a << endl;

    return 0;
}
*/
/*

1）如果高于85分，则输出“优”；

2）如果低于85但高于75，则输出“良”；

3）如果低于75但高于60，则输出“中”；

4）如果低于60分，则输出“差”。

请根据要求把以下程序填写完整。
*/
/*
#include<iostream>

using namespace std;

int main()

{

    int score;
    cin >> score;
    if (score >= 85) {
        cout << "优" << endl;
    } else if (score >= 75) {
        cout << "良" << endl;
    } else if (score >= 60) {
        cout << "中" << endl;
    } else {
        cout << "差" << endl;
    }
    return 0;

}
*/

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
