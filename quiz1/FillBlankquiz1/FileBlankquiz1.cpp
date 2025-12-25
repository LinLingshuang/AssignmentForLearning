/*字符串流处理 + 单词统计-v2
【问题描述】
请补充完整下面空白的程序语句。
从键盘输入的字符串，其中的单词可能包含字母、空格、数字和其它字符，
分割出字符串中单词，把除了字母和空格之外的字符替换为下划线后，统计字符串中单词的总数及最长单词长度。
函数 countWords( )接收一个字符串 ，通过字符串流istringstream 分割输入字符串中的单词，并统计字符串中单词的总数及最长单词长度。
函数processText( )接收一个字符串，将其中除了字母和空格之外的字符替换为下划线后输出。
函数isAlphaWord( )接收一个字符串，判断字符串是否全由字母组成。
【输入形式】
从键盘输入字符串，字符串中可能包含字母、数字、标点符号及其它字符。
【输出形式】
输出处理后的字符串，串中单词的总数及最长单词长度。
【样例输入】
Good luck to all classmates!
【样例输出】
InputText: Good luck to all classmates!
Cleaned Text: classmates_
Total words: 5
Max length: 11
【样例说明】
classmates! 处理后变成 classmates_*/

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

bool isAlphaWord(const string& word);
string processText(const string& input);

void countWords(const string& text, int& total, long unsigned int& maxLength)
{
    istringstream iss(text); // iss是字符串流对象，用于读取字符串text中的单词
    string word;
    total = 0;
    maxLength = 0;

    while (iss >> word)//相当于cin>>word;
    {
        if (!isAlphaWord(word))
        {
            processText(word);//
            
            // 空1
        }

        ++total;
        if (word.length() > maxLength)

            maxLength = word.length();//
        // 空2
    }
}

bool isAlphaWord(const string& word)
{
    for (char c : word)
        if (!isalpha(c))

            return false;//
    // 空3
    return true;
}

string processText(const string& input)
{
    string cleaned;
    for (char c : input)
        if ((isalnum(c) || c == ' ') && !isdigit(c))

            cleaned += c;//
    // 空4   
        else

            cleaned += "_";//
    // 空5
    cout << "Cleaned Text: " << cleaned << endl;
    return cleaned;
}

int main()
{
    int total;
    long unsigned int  maxLen;
    string inputText;

    getline(cin, inputText); // 从键盘输入字符串
    cout << "InputText: " << inputText << endl;
    countWords(inputText, total, maxLen);
    cout << "Total words: " << total << endl;
    cout << "Max length: " << maxLen << endl;

    cin.ignore();
    return 0;
}