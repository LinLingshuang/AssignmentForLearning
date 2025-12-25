#include <iostream>
#include <string>
#include <set>
#include <cctype>

using namespace std;

int main() {
    set<string> vocabulary;  //定义词汇表，自动剔除重复的词
    string word;  //定义单词字符串
    char c; //定义正在扫描的字母
    bool inWord = false;  //定义是否处于扫描某个单词的状态
    
    // 读取输入直到EOF（Ctrl+Z）
    while (cin.get(c)) {  // 遍历所有输入
        if (isalpha(c)) {
            // 如果是字母，加入当前单词并标记在单词内
            word += tolower(c);
            inWord = true;//调为处于扫描单词中
        } else {
            // 如果不是字母且之前在单词内，则将当前单词加入集合
            if (inWord) {
                vocabulary.insert(word);  //单词表插入
                word.clear();  //当前单词扫描完成，重置
                inWord = false;// 调为不处于扫描单词中
            }
        }
    }
    
    // 处理可能留在缓冲区的最后一个单词
    if (inWord && !word.empty()) {
        vocabulary.insert(word);
    }
    
    // 按字典序输出词汇表
    for (const auto& w : vocabulary) {
        cout << w << endl;
    }
    
    return 0;
}