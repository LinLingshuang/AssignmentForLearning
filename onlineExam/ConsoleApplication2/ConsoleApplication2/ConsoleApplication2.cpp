// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;


int main()
{
	ifstream in;
	in.open("filezip.in");
	int a;
	int resultnum = 2;

	string b;
	in >> a >> b;
	cin >> a >> b;
	
	in.close();
	
	vector<string>temp(a);
	
	for (int i = 0; i < a; i++) {
		int c = 0;
		for (int j = 0; j < a; j++) {
			if (a - j > i) {
				temp[i].push_back(b[j + i]);
			}
			else {
				temp[i].push_back(b[c]);
				c++;
			}
		}
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a - 1; j++) {
			if (temp[j][0] > temp[j + 1][0]) {
				string temp2 = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = temp2;

				if (j + 1 == resultnum) {
					resultnum = j + 2;
				}
				else if (j + 2 == resultnum) {
					resultnum = j + 1;
				}
			}
		}
	}
	
	string result;
	for (int i = 0; i < a; i++) {
		result.push_back(temp[i][a - 1]);
	}

	ofstream out;
	out.open("filezip.out");

	cout << result;
	cout << endl;
	cout << resultnum;

	out << result;
	out << endl;
	out << resultnum;


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
