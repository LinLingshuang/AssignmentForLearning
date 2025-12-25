#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    // 读取第一组整数
    int n1;
    cin >> n1;
    vector<int> set1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> set1[i];
    }

    // 读取第二组整数
    int n2;
    cin >> n2;
    vector<int> set2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> set2[i];
    }

    // 将两组整数转换为集合，方便查找
    set<int> s1(set1.begin(), set1.end());
    set<int> s2(set2.begin(), set2.end());

    // 存储结果的向量
    vector<int> result;

    // 找出在set1中但不在set2中的元素
    for (int num : s1) {
        if (s2.find(num) == s2.end()) {
            result.push_back(num);
        }
    }

    // 找出在set2中但不在set1中的元素
    for (int num : s2) {
        if (s1.find(num) == s1.end()) {
            result.push_back(num);
        }
    }

    // 对结果排序
    sort(result.begin(), result.end());

    // 输出结果，元素之间用空格分隔
    for (size_t i = 0; i < result.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << result[i];
    }
    cout << endl;

    return 0;
}