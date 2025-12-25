/*2. 类Point的重载
【问题描述】
对类Point重载"++"和"--"运算符（包括前缀和后缀形式），
要求：1、Point类有x和y坐标。
2、重载运算符使"++"和"--"分别使得x和y同时增或减1。3、程序能够从标准输入读取Point坐标并测试运算符
【输入形式】
标准输入。第一行是初始x和y坐标。第二行是操作序列，包含"++"（前缀++）、"--"（前缀--）、"+++"（表示后缀++）、"---"（表示后缀--）
【输出形式】
每步操作后输出当前坐标，格式为"(x,y)"，如果没有进行操作，输出原坐标。
【样例输入】
2 3
++ -- +++ ---
【样例输出】
(3,4)
(2,3)
(3,4)
(2,3)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    // 前缀++
    Point& operator++() {
        ++x;
        ++y;
        return *this;
    }
    // 后缀++
    Point operator++(int) {
        Point temp = *this;
        ++(*this);
        return temp;
    }
    // 前缀--
    Point& operator--() {--x; --y;return *this;}//
    // 后缀--
    Point operator--(int) {Point temp = *this; --(*this);return temp;}//
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }
};

int main() {
    int x, y;
    int z = 0;
    cin >> x >> y;
    Point p(x, y);

    string operations;
    cin.ignore();
    getline(cin, operations);

    istringstream iss(operations);
    string op;
    while (iss >> op) {
        z += 1;
        if (op == "++") {
            ++p;
        }
        else if(op == "+++") {p++;}//

        else if (op == "---") {
            p--;
        }
        else {--p;}//
        cout << p << endl;
    }

    if (z == 0) { cout << p << endl; }

    return 0;
}







