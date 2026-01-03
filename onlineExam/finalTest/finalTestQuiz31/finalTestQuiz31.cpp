/*31. 定义一个Circle类，计算圆的面积。
【问题描述】
定义一个Circle类，该类包含一个数据成员radius（半径）和一个成员函数getArea()，用于计算圆的面积。然后，通过构造Circle类的对象，输入圆的半径，并输出其面积。
【输入形式】
用户输入圆的半径值。
【输出形式】
输出对应圆的面积
【样例输入】
5.1
【样例输出】

81.6714
【样例说明】

PI=3.14
【评分标准】

*/

#include <iostream>
using namespace std;

#define PI 3.14


class Circle {
public:
    Circle(){}
    Circle(double r):radius(r){}

    double getArea() {

        return PI * radius * radius;
    }

private:

    double radius;

};



int main()
{
    double radius;
    
    cin >> radius;

    Circle circle(radius);

    cout << circle.getArea();


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
