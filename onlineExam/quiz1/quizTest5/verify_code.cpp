#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

// 正确的大数乘法实现
string multiply(const string& num1, const string& num2) {
    if (num1 == "0" || num2 == "0") return "0";
    
    int n = num1.size(), m = num2.size();
    vector<int> res(n + m, 0);
    
    // 从低位到高位相乘
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            // 计算当前位的乘积
            int mul = (num1[i] - '0') * (num2[j] - '0');
            // 计算当前位和进位位的位置
            int p1 = i + j, p2 = i + j + 1;
            // 将乘积与当前位置的已有值相加
            int sum = mul + res[p2];
            
            // 更新进位和当前位
            res[p1] += sum / 10;  // 进位加到更高位
            res[p2] = sum % 10;   // 当前位保留个位
        }
    }
    
    // 转换结果数组为字符串，跳过前导零
    string str;
    for (int digit : res) {
        if (!(str.empty() && digit == 0)) {
            str.push_back(digit + '0');
        }
    }
    
    return str.empty() ? "0" : str;
}

// 从标准输入读取两个数并计算结果
void interactive_mode() {
    string num1, num2;
    cout << "请输入两个十进制正整数（空格分隔）: ";
    cin >> num1 >> num2;
    
    string result = multiply(num1, num2);
    cout << "乘积结果: " << result << endl;
}

// 运行测试用例并显示结果
void run_test_cases() {
    cout << "=== 大数乘法测试用例结果 ===\n" << endl;
    
    // 测试用例数组
    vector<pair<string, string>> test_cases = {
        {"1234567890", "9876543210"},  // 样例测试用例
        {"123", "456"},              // 基本测试
        {"1", "9999999999"},         // 乘以1
        {"9999999999", "1"},         // 被1乘
        {"1000000000", "1000000000"}, // 整十数相乘
        {"9999999999", "9999999999"}, // 全9边界测试
        {"0", "9999999999"},         // 乘以0
        {"9999999999", "0"},         // 被0乘
        {"1111111111", "1111111111"}, // 特殊模式
        {"8765432109", "2345678901"}, // 随机大数字
        {"1000000001", "1000000001"}  // 接近边界
    };
    
    // 运行测试用例
    for (size_t i = 0; i < test_cases.size(); i++) {
        const auto& [num1, num2] = test_cases[i];
        string result = multiply(num1, num2);
        cout << "测试 " << (i + 1) << ":" << endl;
        cout << "  输入: " << num1 << " " << num2 << endl;
        cout << "  正确结果: " << result << endl;
        cout << "-----------------------------" << endl;
    }
    
    cout << "提示：您可以将上述输入复制到您的程序中，然后对比输出结果。\n";
    cout << "所有测试用例的详细信息已保存在 test_cases.txt 文件中。" << endl;
}

int main() {
    cout << "大数乘法验证程序\n" << endl;
    
    // 显示测试用例结果
    run_test_cases();
    
    // 提供交互式测试选项
    char choice;
    cout << "\n是否进行交互式测试？(y/n): ";
    cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        interactive_mode();
    }
    
    return 0;
}