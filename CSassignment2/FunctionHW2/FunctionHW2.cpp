/*【问题描述】

给出一个不多于5位的正整数，要求：
1.求出它是几位数。
2.分别打印出每一位数字。
3.按照逆序打印出每一位数字。
【输入形式】

控制台输入该正整数。
【输出形式】

控制台分行输出输出结果。
【输入样例1】

1234
【输出样例1】

4
1234
4321
【样例1说明】

1234位数为4，分别为1，2，3，4，逆序为4321
【输入样例2】

200
【输出样例2】

3
200
002
【样例1说明】

200位数为3，分别为2，0，0，逆序为002*/
/*
#include <iostream>

using namespace std;

int main() {
	int x;
	cin >> x;
	int num1=(x/10000)%10, num2=(x/1000)%10, num3=(x/100)%10, num4=(x/10)%10, num5=x%10;
	int index=0;
	int result = 5;
	if (num1 == 0) {
		index += 1;
		if (num2 == 0) {
			index += 1;
			if (num3 == 0) {
				index += 1;
				if (num4 == 0) {
					index += 1;
					if (num5 == 0) {
						index += 1;
					}
				}
			}
		}
	}
	result -= index;
	cout << result<<endl;
	if (index == 0) {
		cout << num1 << num2 << num3 << num4 << num5 << endl;
		cout << num5 << num4 << num3 << num2 << num1 << endl;
	}
    if (index == 1) {
		cout << num2 << num3 << num4 << num5 << endl;
		cout << num5 << num4 << num3 << num2 << endl;
	}
			
	if (index == 2) {
		cout  << num3 << num4 << num5 << endl;
		cout << num5 << num4 << num3 << endl;
	}
				
	if (index == 3) {
		cout  << num4<< num5 << endl;
		cout << num5 <<num4<< endl;
	}
					
	if (index == 4) {
		cout  <<num5<< endl;
		cout <<num5<< endl;
	}

	return 0;
}*/
//优化的代码
#include<iostream>
#include<string>
using namespace std;

int main(){

    int x;
    cin >> x;

    // 将整数转换为字符串处理，这样更容易处理位数和逆序
    string str = to_string(x);
    int length = str.length();
    
    // 输出位数
    cout << length << endl;
    
    // 输出原始数字
    cout << str << endl;
    
    // 输出逆序数字
    for (int i = length - 1; i >= 0; i--) {
        cout << str[i];
    }
    cout << endl;
    
    return 0;
}