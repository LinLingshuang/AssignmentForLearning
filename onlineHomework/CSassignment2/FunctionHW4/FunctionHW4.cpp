/*题目：输入若干个字符串(每个字符串的长度不超过30个字符，字符串总数不超过30)，和一个英文字符。
要求：
- 删除每个字符串中的字符(区分大小写)，得到新的字符串
- 将新的字符串按照字典逆序排序后输出

输入形式：
第一行输入英文字符
每一行输入一个字符串
最后一行单独输入特殊字符@做为结束标志

输出形式：
删除ch的新字符串按字典逆序输出
每行输出一个字符串

样例输入：
e
shangejiao
fudean
teongji
shangcai
@

样例输出：
tongji
shangjiao
shangcai
fudan*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    // 读取要删除的字符
    char targetChar;
    cin >> targetChar;
    cin.ignore(); // 忽略换行符
    
    vector<string> strings;
    string input;
    
    // 读取字符串，直到遇到@
    while (true) {
        getline(cin, input);
        if (input == "@") {
            break;
        }
        // 处理字符串，删除目标字符
        string processed;
        for (char c : input) {
            if (c != targetChar) {
                processed += c;
            }
        }
        strings.push_back(processed);
    }
    
    // 按字典逆序排序
    sort(strings.begin(), strings.end(), greater<string>());
    
    // 输出结果
    for (const string& s : strings) {
        cout << s << endl;
    }
    
    return 0;
}