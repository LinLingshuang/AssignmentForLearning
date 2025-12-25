/*【问题描述】
"交叉引用生成器"（cross-refrencer）是指具有如下功能的程序：
对输入的一篇文档，统计出现的所有单词及其所在行号。将其结果以规定格式输出。
【输入形式】
程序从文件crossin.txt读入一篇文档。该文档由若干行组成，每行中包含一系列单词。
行号由1开始计数。该文档中单词总量不超过200，每个单词长度最大不超过20个字符。
【输出形式】
将输入文档中所有出现的单词及其所在行号输出到文件crossout.txt中。
输出有若干行，每一行都是文档中出现的一个单词。按如下规格输出：
word:line1,line2, ... ,lineN
其中word是单词，后面紧跟一个冒号，然后是以逗号隔开的出现行号line1，line2，等等。在该行上各字符紧密输出，不使用空格分隔。在输出时遵循以下规定：
1.只输出所有由英文字母（包括连字符）构成的单词，数字或包含其它特殊字符的单词不用输出，
而且连字符不能作为单词首字符。先输出大写A—Z开头的字符，再输出小写a—z开头的字符。
2.各单词后面的行号从小到大排列。行号不重复打印，亦即如果一个单词在一行内多次出现，则只打印一次该行号。
3.统计的单词不包括如下四个单词：
           a
           an
           the
           and
【样例输入】

Alcatel provides end-to-end solutions.
It enables enterprises to deliver content to any type of user.
lcatel operates in 130 countries.
Alcatel focus on optimizing their service offerings and revenue streams.
【样例输出】
Alcatel:1,4
It:2
any:2
content:2
countries:3
deliver:2
enables:2
end-to-end:1
enterprises:2
focus:4
in:3
lcatel:3
of:2
offerings:4
on:4
operates:3
optimizing:4
provides:1
revenue:4
service:4
solutions:1
streams:4
their:4
to:2
type:2
user:2*/

#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>

using namespace std;



int main()
{
    ifstream input;
    input.open("crossin.txt");

    vector<string>line(100);
    
    map<string, vector<int>>str;

    int lineNum = 0;
    while (getline(input, line[lineNum])) {
        int i = 0;

        ofstream temp;
        temp.open("temp.txt");
        temp << line[lineNum];
        temp.close();

        ifstream temp1;
        temp1.open("temp.txt");

        string temp2;
        char end = '0';
        while (end != '.') {
            temp1 >> temp2;
            if (temp2 == "a" || temp2 == "an" || temp2 == "the" || temp2 == "and") {
                continue;
            }
            string temp4;
            char *temp3 = new char[20];
            int j = 0;
            for (char c : temp2) {
                if (c == '.') {
                    end = '.';
                    break;
                }
                temp3[j] = temp2[j];
                j++;
            }
            temp3[j] = '\0';
            temp4 = temp3;
           
            str[temp4].push_back(lineNum+1);
            i++;
            delete[] temp3;
        }
        lineNum++;
        temp1.close();
    }
    input.close();
   
    ofstream outfile;

    outfile.open("crossout.txt");

    for (map<string, vector<int>>::iterator iter = str.begin(); iter != str.end(); ++iter) {
        outfile << iter->first << ":";
        for (vector<int>::iterator iter1 = str[iter->first].begin(); iter1 != str[iter->first].end(); ++iter1) {
            outfile << *iter1;
            if (iter1 != str[iter->first].end()) {
                outfile << ',';
            }
        }
        outfile << endl;
    }

    outfile.close();


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
