/*34. 加密算法
【问题描述】

小明发明了一种新的字符串加密方法，该方法是统计每一个字符出现的频率，并按照频率从小到大进行排序。假设共有已经按照频率排好序的M个字符code，然后将字符code[i]和code[m-i]进行交换。如果输入的字母种类是奇数个，那么频率是中间的字母不加密。

【输入形式】

一行字符串，每一个字符出现的频率不一样。

【输出形式】

输出加密后的字符串

【样例输入】


ABCDBDCDBCCDD

【样例输出】


DCBACABACBBAA

【样例说明】

每一个字符出现的频率是A=1，B=3，C=4，D=5

那么就是将A和D交换，B和C交换，加密后的字符串是

DCBACABACBBAA

【评分标准】*/

//自己的方法一
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string switchstring(string a) {
	int length = a.length();

	int i = 0;
	int findmax = -1;
	string kind;
	for (char c : a) {
		int proccess = a.find(c);
		if (proccess > findmax) {
			findmax = proccess;
			kind += c;
		}
	}
	vector<int>flequt(kind.length(), 1);
	for (char c : a) {
		int proccess = a.find(c);
		int kindproccess = kind.find(c);
		if (proccess < i) {
			flequt[kindproccess] += 1;

		}

		i++;
	}
	for (int j = 0; j < kind.length(); j++) {
		for (int i = 0; i < kind.length() - 1; i++) {
			if (flequt[i] > flequt[i + 1]) {
				int proccess = flequt[i];
				flequt[i] = flequt[i + 1];
				flequt[i + 1] = proccess;
				char proccesschar = kind[i];
				kind[i] = kind[i + 1];
				kind[i + 1] = proccesschar;

			}

		}
	}

	for (int i = 0; i < a.length(); i++) {
		bool isswitch = false;
		if (kind.length() % 2 != 0) {
			for (int j = 0; j < kind.length(); j++) {
				if (a[i] == kind[j] && j != ((kind.length() + 1) / 2) && !isswitch) {
					a[i] = kind[kind.length() - j - 1];
					isswitch = true;
				}

			}
		}
		else {
			for (int j = 0; j < kind.length(); j++) {
				if (a[i] == kind[j] && !isswitch) {
					a[i] = kind[kind.length() - j - 1];
					isswitch = true;
				}
			}
		}
	}
	return a;
}
int main() {
	string input;
	cin >> input;
	cout << switchstring(input);
}// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
