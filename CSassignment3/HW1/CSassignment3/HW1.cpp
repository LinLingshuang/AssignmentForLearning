/*输入两个整数a和b，输出这两个整数的和。a和b都不超过100位。

算法描述

　　由于a和b都比较大，所以不能直接使用语言中的标准数据类型来存储。对于这种问题，一般使用数组来处理。
　　定义一个数组A，A[0]用于存储a的个位，A[1]用于存储a的十位，依此类推。同样可以用一个数组B来存储b。
　　计算c = a + b的时候，首先将A[0]与B[0]相加，如果有进位产生，则把进位（即和的十位数）存入r，
    把和的个位数存入C[0]，即C[0]等于(A[0]+B[0])%10。然后计算A[1]与B[1]相加，这时还应将低位进上来的值r也加起来，
    即C[1]应该是A[1]、B[1]和r三个数的和．如果又有进位产生，则仍可将新的进位存入到r中，和的个位存到C[1]中。
    依此类推，即可求出C的所有位。
　　最后将C输出即可。


【输入形式】
　输入包括两行，第一行为一个非负整数a，第二行为一个非负整数b。两个整数都不超过100位，两数的最高位都不是0。
【输出形式】
　输出一行，表示a + b的值。*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 定义A，B字符串
    string A;
    string B;
    // 输入A，B字符串
    getline(cin, A);
    getline(cin, B);
    // 定义A，B字符串的长度
    int lengthA = A.length();
    int lengthB = B.length();
    int max = lengthA;
    if (lengthB >= max)max = lengthB;

    // 定义A，B的各个位的数组
    vector<int>Anew(max);
    vector<int>Bnew(max);
    // 定义C，C可能多进一位
    vector<int>C(max + 1);
    // 定义进位
    vector<int>r(max);

    // 逆遍历A，将字符串转化为数值
    for (int i = max - 1; i > -1; i--) {
        if (i > max - lengthA - 1) {
            Anew[i] = A[lengthA - 1 + i + 1 - max] - '0';// 注意A，Anew的长度不同，
            // 表达式写这么长是为了清晰说明从A的末尾开始递减
        }
        else {
            Anew[i] = 0;
        }
    }
    // B同理
    for (int i = max - 1; i > -1; i--) {
        if (i > max - lengthB - 1) {
            Bnew[i] = B[lengthB - 1 + i + 1 - max] - '0';
        }
        else {
            Bnew[i] = 0;
        }
    }
    // 处理进位
    for (int i = max - 1; i > -1; i--) {
        if (i == max - 1) {  // 算出首个进位
            if (Anew[i] + Bnew[i] >= 10) {
                r[i] = 1;
            }
            else {
                r[i] = 0;
            }
        }
        else {  // 利用第一个进位得后续进位
            if (Anew[i] + Bnew[i] + r[i+1] >= 10) {
                r[i] = 1;
            }
            else {
                r[i] = 0;
            }
        }
    }
    // 求C
    for (int i = max - 1; i > -1; i--) {
        if (i == max - 1) {
            C[i+1] = (Anew[i] + Bnew[i]) % 10;
        }
        else {
            C[i+1] = (Anew[i] + Bnew[i] + r[i + 1]) % 10;
        }
    }
            C[0] =  r[0];
    if (C[0] == 0) {

         for (int i = 1; i < max + 1; i++) {
              cout << C[i];
         }
    }
    if (C[0] != 0) {

        for (int i = 0; i < max + 1; i++) {
            cout << C[i];
        }
    }
    return 0;
}
/*#include <iostream>
#include <cctype>  // 用于isdigit函数

int main() {
    char c = '7';
    
    // 先检查是否为数字字符
    if (isdigit(c)) {
        int num = c - '0';
        std::cout << "转换结果: " << num << std::endl;
    } else {
        std::cout << "不是数字字符" << std::endl;
    }
    
    return 0;
}*/