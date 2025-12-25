#include <iostream>
#include <vector>
using namespace std;
//定义类，此题本质为约瑟夫递减问题
class Joseph {
private:
    int n;
    int m;
    int k;
public:
    Joseph(int n_val, int m_val, int k_val) :n(n_val), m(m_val), k(k_val) {}//构造函数
    void simulate() {   //成员函数
        vector<int>monkey(n);  //猴子的编号
        vector<bool>eliminated(n, false);  //猴子是否淘汰的状态
        for (int i = 0; i < n; i++) {    //编号的赋值
            monkey[i] = i + 1;
        }
        int now = k - 1;  //当前报号的编号
        int count = 0;  //淘汰数
        while (count < n) {   //遍历淘汰过程
            int distan = m - 1;  //报号间隔
            while (distan > 0) {
                now = (now + 1) % n;  //移动报号的编号
                if (!eliminated[now])distan--;  //判断是否被淘汰
            }
            eliminated[now] = true;  //改变淘汰状态
            count++;  //增加淘汰个数
            if (count < n) {
                do { now = (now + 1) % n; } while (eliminated[now]); //跳过刚刚被淘汰的猴子
            }
        }
        cout << monkey[now] << endl;//输出最终结果
    }

};



int main() {

    int n, m, k;
    cin >> n >> m >> k;

    Joseph obj(n, m, k);
    obj.simulate();
    return 0;
}
