// HW4floatOutput.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// 解析格式控制字符串
void parseFormat(const string& format, bool& leftAlign, int& width, int& precision) {
    // 默认值
    leftAlign = false;
    width = 0;
    precision = 10; // 默认精度为10位

    // 确保格式字符串以%开头，以f结尾
    if (format[0] != '%' || format.back() != 'f') {
        return; // 格式错误，但按照要求，输入是有效的
    }

    int pos = 1; // 跳过%符号

    // 检查是否有'-'标志
    if (format[pos] == '-') {
        leftAlign = true;
        pos++;
    }

    // 解析width
    string widthStr;
    while (pos < format.length() && isdigit(format[pos])) {
        widthStr += format[pos];
        pos++;
    }
    if (!widthStr.empty()) {
        width = stoi(widthStr);
    }

    // 解析precision
    if (pos < format.length() && format[pos] == '.') {
        pos++; // 跳过小数点
        string precisionStr;
        while (pos < format.length() && isdigit(format[pos])) {
            precisionStr += format[pos];
            pos++;
        }
        if (!precisionStr.empty()) {
            precision = stoi(precisionStr);
        }
    }
}

// 处理浮点数，按照指定精度截断小数部分
string processFloat(const string& input, int precision) {
    size_t dotPos = input.find('.');
    if (dotPos == string::npos) {
        // 如果是整数，添加小数点和precision个0
        return input + '.' + string(precision, '0');
    }
    else {
        // 截断小数部分到precision位
        string integerPart = input.substr(0, dotPos + 1); // 包含小数点
        string fractionalPart = input.substr(dotPos + 1);

        if (fractionalPart.length() > precision) {
            fractionalPart = fractionalPart.substr(0, precision);
        }
        else if (fractionalPart.length() < precision) {
            fractionalPart += string(precision - fractionalPart.length(), '0');
        }

        return integerPart + fractionalPart;
    }
}

// 格式化输出，处理对齐和填充
string formatOutput(const string& processedNumber, bool leftAlign, int width) {
    int actualWidth = processedNumber.length();
    if (width <= actualWidth) {
        return processedNumber;
    }

    int paddingWidth = width - actualWidth;
    string padding(paddingWidth, '*');

    if (leftAlign) {
        // 左对齐，*在右边
        return padding + processedNumber;
    }
    else {
        // 右对齐，*在左边
        return processedNumber + padding;
    }
}

int main() {
    // 从in.txt文件读取输入
    ifstream infile("in.txt");
    if (!infile) {
        cerr << "无法打开in.txt文件" << endl;
        return 1;
    }

    string floatNumber, format;
    getline(infile, floatNumber);
    getline(infile, format);

    infile.close();

    // 解析格式控制字符串
    bool leftAlign;
    int width, precision;
    parseFormat(format, leftAlign, width, precision);

    // 处理浮点数，截断到指定精度
    string processedNumber = processFloat(floatNumber, precision);

    // 格式化输出
    string result = formatOutput(processedNumber, leftAlign, width);

    // 输出结果
    cout << result << endl;

    return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
