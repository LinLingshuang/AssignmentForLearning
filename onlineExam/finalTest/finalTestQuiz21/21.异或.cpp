/*【问题描述】

从标准输入中输入两组整数(每行不超过20个整数，每组整数中元素不重复),合并两组整数，去掉在两组整数中都出现的整数，并按从大到小顺序排序输出（即两组整数集"异或"）。

【输入形式】

首先输入第一组整数，以一个空格分隔各个整数；然后在新的一行上输入第二组整数，以一个空格分隔，行末有回车换行。

【输出形式】

按从大到小顺序排序输出合并后的整数集（去掉在两组整数中都出现的整数，以一个空格分隔各个整数）。

【样例输入】

5 1 4 32 8 7 9 -6
5 2 87 10 1
【样例输出】

87 32 10 9 8 7 4 2 -6
【样例说明】*/

#include <iostream>
#include <set>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    set<string>c;
    string temp2;
    for (char temp1 : a) {
        if (temp1 == ' ') {
            c.insert(temp2);
            temp2.clear();
            continue;
        }
        temp2.push_back(temp1);
    }
    c.insert(temp2);
    temp2.clear();
    for (char temp1 : b) {
        if (temp1 == ' ') {
            bool skip = false;
            for (string d : c) {
                if (d == temp2) {
                    skip = true;
                    c.erase(d);
                    break;
                }
            }
            if (!skip){
                c.insert(temp2);
            }
            temp2.clear();
            continue;
        }
        temp2.push_back(temp1);
    }
    bool skip = false;
    for (string d : c) {
        if (d == temp2) {
            skip = true;
            c.erase(d);
            break;
        }
    }
    if (!skip) {
        c.insert(temp2);
    }
    temp2.clear();
   
    ofstream out;
    out.open("temp.txt");
    int num = 0;

    for (string d : c) {
        out << d << ' ';
        num++;
    }
    out.close();

    ifstream in;
    in.open("temp.txt");
    int tempnum;
    vector<int>result;
    for (int i = 0; i < num; i++) {
        in >> tempnum;
        result.push_back(tempnum);
    }
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - 1; j++) {
            if (result[j] < result[j + 1]) {
                int tempSwapNum = result[j];
                result[j] = result[j + 1];
                result[j + 1] = tempSwapNum;
            }
        }
    }
    for (int i = 0; i < num; i++) {
        cout << result[i] << ' ';
    }
    in.close();
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
