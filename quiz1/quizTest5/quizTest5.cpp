/*大数乘法

【问题描述】计算两个最长十位的十进制正整数的乘积并输出。
【输入形式】输入两个最长十位的十进制正整数，两数之间以一个空格间隔。
【输出形式】两数乘积的十进制形式。
【样例输入】1234567890 9876543210
【样例输出】12193263111263526900
【样例说明】一共五组测试数据。
【评分标准】 每组测试数据运行正确即给20%的分数。*/
//我现在有个关于这个问题的代码，帮我检验这个代码是否可以完成题目要求，不用更改
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	string num1, num2;
	cin >> num1 >> num2;

	vector<int>num1new(num1.length());
	vector<int>num2new(num2.length());

	for (int i = 0; i < num1.length(); i++) {
		num1new[i] = num1[num1.length() - 1 - i]-'0';
	}
	for (int i = 0; i < num2.length(); i++) {
		num2new[i] = num2[num2.length() - 1 - i]-'0';
	}
	string strprocess(21,'0');
	for (int i = 0; i < num1.length(); i++) {
		int level1;
		int level2;
		int leap1=0;
		int leap2=0;
		for (int j = 0; j < num2.length(); j++) {
			level1 = (num1new[i] * num2new[j]) % 10;// 小位
			level2 = ((num1new[i] * num2new[j]) / 10) % 10;// 大位
			if (i + j >= 1) {
				leap1 = ((level1 + (strprocess[i + j] - '0')) / 10) % 10;
				strprocess[i + j] = ((level1 + (strprocess[i + j] - '0')) % 10)+'0';
				
				int littel = strprocess[i + j + 1] - '0';
				strprocess[i + j + 1] =((strprocess[i + j + 1]-'0' + level2 + leap1 + leap2) % 10) + '0';
				leap2 =((littel + level2 + leap1 + leap2) / 10) % 10;//把这个换为旧的strprocess
			}
			else {
				strprocess[i + j] = (level1 % 10)+'0';
				leap1 = (level1 / 10) % 10;
				
				strprocess[i + j + 1] = ((level2 + leap1 + leap2) % 10)+'0';
				leap2 = ((level2 + leap1 + leap2) / 10) % 10;
			}
		}
	}
	bool First = false;
	for (int m = 20; m >= 0; m--) {
		if(strprocess[m]!='0'&&!First){
			First = true;
		}
		if (First) {
			cout << strprocess[m];
		}
	}
}/*#include<iostream>

using namespace std;

string m_A, m_B;

string pow(string result, int n) //计算乘10的n次方
{
    for (int i = 0; i < n; i++)
    {
        result.push_back('0');
    }
    return result;
}

string add(string result, string adding)
{
    int len = 0;
    string& result0 = result.size() > adding.size() ? result : adding;
    string adding0 = result.size() <= adding.size() ? result : adding;
    for (int i = 0; i < adding0.size(); i++)
    {
        result0[result0.size() - 1 - i] = '0' + (result0[result0.size() - 1 - i] - '0') + (adding0[adding0.size() - 1 - i] - '0');
    }
    len = result0.size();
    for (int i = len - 1; i >= 1; i--)
    {
        if (result0[i] > '9')
        {
            result0[i] -= 10;
            result0[i - 1]++;
        }
    }
    if (result0[0] > '9')
    {
        result[0] -= 10;
        result0.insert(result0.begin(), '1');
    }
    return result0;
}

string multi(string result, int n) //计算乘n
{
    string yuan = result;
    for (int i = 0; i < n - 1; i++)
    {
        result = add(result, yuan);
    }
    return result;
}

int main()
{
    cin >> m_A >> m_B;
    string result;

    for (int i = 0; i < m_B.size(); i++)
    {
        result = add(result, multi(pow(m_A, m_B.size() - 1 - i), m_B[i] - '0'));
    }
    
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    cout << endl;
    return 0;
}*/