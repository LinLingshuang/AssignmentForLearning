#include<iostream>
#include<string>
#include<vector>

using namespace std;

// 验证函数：使用更简单的大数乘法实现
string multiply(const string& num1, const string& num2) {
    int n = num1.size(), m = num2.size();
    vector<int> res(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + res[p2];

            res[p1] += sum / 10;
            res[p2] = sum % 10;
        }
    }

    string str;
    for (int i = 0; i < res.size(); i++) {
        if (!(str.empty() && res[i] == 0)) {
            str.push_back(res[i] + '0');
        }
    }

    return str.empty() ? "0" : str;
}

int main() {
    // 测试样例
    string test1_num1 = "1234567890";
    string test1_num2 = "9876543210";
    string expected1 = "12193263111263526900";

    // 测试可能有问题的情况
    string test2_num1 = "9999999999";
    string test2_num2 = "9999999999";
    string expected2 = "99999999980000000001";

    string result1 = multiply(test1_num1, test1_num2);
    string result2 = multiply(test2_num1, test2_num2);

    cout << "Test 1: " << (result1 == expected1 ? "PASS" : "FAIL") << endl;
    cout << "Expected: " << expected1 << endl;
    cout << "Got: " << result1 << endl;

    cout << "\nTest 2: " << (result2 == expected2 ? "PASS" : "FAIL") << endl;
    cout << "Expected: " << expected2 << endl;
    cout << "Got: " << result2 << endl;

    // 分析原代码的问题
    cout << "\n原代码潜在问题分析：" << endl;
    cout << "1. 进位处理逻辑复杂，可能存在错误" << endl;
    cout << "2. 当两个数字相乘结果超过99时，只处理了十位进位，会丢失更高位的进位" << endl;
    cout << "3. 例如：当计算99*99时，乘积为9801，原代码的level2只取8(98/10%10)，会丢失百位的9" << endl;

    return 0;
}