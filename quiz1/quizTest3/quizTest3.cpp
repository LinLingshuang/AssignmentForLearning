/*使用栈检测字符串中括号是否匹配
【问题描述】

编程完成函数isBalanced()，它检查给定字符数组中的括号是否成对出现且嵌套正确，
支持的括号类型包括圆括号 '()'、方括号 '[]' 和花括号 '{}'。
在main函数中调用isBalanced函数，输出判断结果.
编程结果提交包含main函数的完整源程序。

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

bool isBalanced(char expr[])

{
    // 请编程完成函数体代码
}
// 在main函数中输入表达式，调用isBalanced函数，输出判断结果
int main()

{

    char expr1[100];

    cin >> expr1;

    cout << (isBalanced(expr1) ? "Balanced" : "Not Balanced") << endl; // 应输出判断结果

}
【输入形式】
输入一个字符串，最大长度不超过100个字符，包含括号和其它字符，以空格分隔。例如："{ ()}[]"
【输出形式】
如果括号匹配且嵌套层次正确，输出"Balanced"；否则，输出"Not Balanced"。
【样例输入】
{()}[]
【样例输出】
Balanced
【样例说明】
输入的字符串中，括号成对出现且嵌套正确
【实现提示】
  遇到左括号入栈，遇到右括号出栈， 出栈时检查是否匹配，最后栈为空则匹配。*/

#include <iostream>
#include <stack>
#include <string>


using namespace std;

int main() {
    string input;
    stack<char>proccess;
    getline(cin, input);
    int len = input.length();
    bool Balanced = true;
    for (int i = 0; i < len; i++) {
        if (input[i] == '{' || input[i] == '(' || input[i] == '[') {
            proccess.push(input[i]);
        }
        else {
            char topelement = proccess.top();
            if ((topelement == '{' && input[i] == '}') || (topelement == '(' && input[i] == ')') || (topelement == '[' && input[i] == ']')) {
                proccess.pop();
            }
            else {
                Balanced = false;
            }
        }
    }
    cout << (Balanced ? "Balanced" : "Not Balanced") << endl;

}
