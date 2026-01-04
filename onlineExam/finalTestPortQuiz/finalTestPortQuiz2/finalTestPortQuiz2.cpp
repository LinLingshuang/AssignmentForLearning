/*2. 指针
【问题描述】实现一个名为SimpleCircle的简单函数，其数据成员Int *itsRadius为一个指向其半径值的指针，设计对数组成员的各种操作，给出这个类的完整实现并测试这个类。
           注意：此题提供main.cpp工程文件作为示范，和SimpleCircle.h声明文件作为约束和提示，请独自完成SimpleCircle.cpp函数实现文件的编写。
【输入形式】从键盘输入4个不同的圆的半径【输出形式】
【样例输入】1 2 3 4
【样例输出】
利用三种不同的构造函数生成的四个圆的半径值为：
CircleOne: 5
CircleTwo: 9
CircleThree: 5
CircleFour: 9
利用成员函数void setRadius(int)改变后的四个圆的半径值为：
CircleOne: 1
CircleTwo: 2
CircleThree: 3
CircleFour: 4
【样例说明】
【评分标准】完全正确，满分*/
//  "main" 函数。先显示调用类SimpleCircle的默认构造函数、带参数的构造函数、复制构造函数后四个圆类的半径，然后再输入四个不同的半径值，显示改变了半径值后的四个圆的半径。
//

#include <iostream>
#include "SimpleCircle.h"
using namespace std;

int main()
{
    SimpleCircle CircleOne, CircleTwo(9), CircleThree(3), CircleFour;
    CircleThree = CircleOne;
    CircleFour = CircleTwo;
    cout << "利用三种不同的构造函数生成的四个圆的半径值为：" << endl;
    cout << "CircleOne: " << CircleOne.getRadius() << endl;
    cout << "CircleTwo: " << CircleTwo.getRadius() << endl;
    cout << "CircleThree: " << CircleThree.getRadius() << endl;
    cout << "CircleFour: " << CircleFour.getRadius() << endl;
    int i, j, k, l;
    // cout << "请输入四个圆类的半径：" << endl;
    cin >> i >> j >> k >> l;
    cout << "利用成员函数void setRadius(int)改变后的四个圆的半径值为：" << endl;
    CircleOne.setRadius(i);
    CircleTwo.setRadius(j);
    CircleThree.setRadius(k);
    CircleFour.setRadius(l);
    cout << "CircleOne: " << CircleOne.getRadius() << endl;
    cout << "CircleTwo: " << CircleTwo.getRadius() << endl;
    cout << "CircleThree: " << CircleThree.getRadius() << endl;
    cout << "CircleFour: " << CircleFour.getRadius() << endl;
    return 0;

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
