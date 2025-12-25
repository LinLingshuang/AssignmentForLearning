/*1. 题目：字符串加密
问题描述：

小明发明了一种新的字符串加密方法，该方法是统计每一个字符出现的频率，
并按照频率从小到大进行排序。假设共有已经按照频率排好序的M个字符code，
然后将字符code[i]和code[m-i]进行交换，
只交换一次。如果输入的字母种类是奇数个，
那么频率是中间的字母不加密。

输入形式：

一行字符串，每一个字符出现的频率不一样。

输出形式：

输出加密后的字符串

样例输入：

ABCDBDCDBCCDD

样例输出：

DCBACABACBBAA

样例说明：

每一个字符出现的频率是A=1，B=3，C=4，D=5

那么就是将A和D交换，B和C交换，加密后的字符串是

DCBACABACBBAA*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 读取输入字符串
    string input;
    getline(cin, input);
    
    // 统计每个字符的频率
    map<char, int> freqMap;
    for (char c : input) {
        freqMap[c]++;
    }
    
    // 将字符和频率存储到vector中以便排序
    vector<pair<char, int>> charFreq;
    for (auto& pair : freqMap) {
        charFreq.push_back(pair);
    }
    
    // 按照频率从小到大排序
    sort(charFreq.begin(), charFreq.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second;
    });
    
    // 创建加密映射表
    map<char, char> encryptMap;
    int m = charFreq.size() - 1;
    for (int i = 0; i <= m / 2; i++) {
        if (i != m - i) { // 避免奇数个字符时中间字符交换
            encryptMap[charFreq[i].first] = charFreq[m - i].first;
            encryptMap[charFreq[m - i].first] = charFreq[i].first;
        } else { // 奇数个字符时，中间字符保持不变
            encryptMap[charFreq[i].first] = charFreq[i].first;
        }
    }
    
    // 生成加密后的字符串
    string result;
    for (char c : input) {
        result += encryptMap[c];
    }
    
    // 输出结果
    cout << result << endl;
    
    return 0;
}

/*
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    map<char, int>frepmap;
    for (char c : input) {
        frepmap[c]++;
    }
    vector<pair<char, int>>charfrep;
    for (auto& pair : frepmap) {
        charfrep.push_back(pair);
    }

    sort(charfrep.begin(), charfrep.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second;
        });
}
*/
