/*#include <iostream>
#include <vector>
using namespace std;

class Joseph {
private:
    int n;  // 总人数
    int m;  // 间隔长度
    int k;  // 起始位置
    vector<int> people;  // 存储剩余的人的编号
    vector<int> result;  // 存储出列顺序

public:
    // 构造函数
    Joseph(int n, int m, int k) : n(n), m(m), k(k) {
        // 初始化people数组，编号从1到n
        for (int i = 1; i <= n; i++) {
            people.push_back(i);
        }
    }

    // 模拟约瑟夫环过程
    void simulate() {
        int currentIndex = k - 1;  // 起始位置的索引（从0开始）
        
        while (!people.empty()) {
            // 计算要删除的元素的索引
            // m可能大于n，所以需要取模
            currentIndex = (currentIndex + m - 1) % people.size();
            
            // 将删除的元素添加到结果数组
            result.push_back(people[currentIndex]);
            
            // 从people数组中删除该元素
            people.erase(people.begin() + currentIndex);
        }
        
        // 输出结果
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) {
                cout << " ";
            }
            cout << result[i];
        }
        cout << endl;
    }
};

int main() {
    int n, m, k;
    // 读取输入
    cin >> n >> m >> k;
    
    // 创建Joseph对象并模拟
    Joseph obj(n, m, k);
    obj.simulate();
    
    return 0;
}
*/

#include <iostream>
#include <vector>
using namespace std;

class Joseph {
private:
    int n;
    int m;
    int k;
public:
    Joseph(int n_val,int m_val,int k_val):n(n_val),m(m_val),k(k_val){}
    void simulate() {
        vector<int>people(n);
        vector<bool>eliminated(n, false);
        for (int i = 0; i < n; i++) {
            people[i] = i + 1;
        }
        int now = k - 1;
        int count = 0;
        while (count < n) {
            int distan = m -1;
            while (distan > 0) {
                now = (now + 1) % n;
                if (!eliminated[now])distan--;
            }
            eliminated[now] = true;
            cout << people[now];
            count++;
            if (count < n) {
                do { now = (now + 1) % n; } while (eliminated[now]);
            }
        }
        cout <<endl;
    }

};



int main() {

    int n,m,k;
    cin >> n>>m>>k;

    Joseph obj(n, m, k);
    obj.simulate();
    return 0;
}
