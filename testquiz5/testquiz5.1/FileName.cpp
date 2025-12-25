/*【问题描述】
从键盘中读入最多不超过50个学生的学生信息（包括空格隔开的姓名、学号、年龄信息，以学号从低到高排序）
【输入形式】
每次键盘读入最多不超过50个学生的学生信息：
第一行为学生人数；
后面每一行为空格隔开的学生学号、姓名、年龄，其中学号和年龄都是整数。
【输出形式】
分别以姓名顺序（从低到高）和年龄顺序（从低到高）将学生信息输出，每行输出一位学生的信息，其中学号占3位，姓名（英文）占6位，年龄占3位，均为右对齐。
年龄相同时按姓名从低到高排序。两种顺序的输出结果用  一行空行相隔。
【输入样例】

4
1 aaa 22
45 bbb 23
54 ddd 20
110 ccc 19
【输出样例】

1    aaa     22          
45     bbb     23      
110     ccc     19   
54     ddd     20                                      
110     ccc     19          
54     ddd     20             
1     aaa     22          
45     bbb     23
【样例说明】
从键盘输入四个学生记录，分别按姓名和年龄排序并输出。*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>num(n);
	vector<string>names(n);
	vector<int>age(n);
	vector<int>coutnum1(n);
	vector<int>coutnum2(n);
	vector<string>names1(n);
	vector<string>names2(n);
	vector<int>age1(n);
	vector<int>age2(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i] >> names[i] >> age[i];
		coutnum1[i] = num[i];
		coutnum2[i] = num[i];
		names1[i] = names[i];
		names2[i] = names[i];
		age1[i] = age[i];
		age2[i] = age[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {

			if (names1[j] > names1[j + 1]) {
				string temp1 = names1[j];
				names1[j] = names1[j + 1];
				names1[j + 1] = temp1;

				int temp2 = coutnum1[j];
				coutnum1[j] = coutnum1[j + 1];
				coutnum1[j + 1] = temp2;

				int temp3 = age1[j];
				age1[j] = age1[j + 1];
				age1[j + 1] = temp3;

			}



		}
	}
	for (int i = 0; i < n; i++) {
		cout << coutnum1[i] << " " << names1[i] << " " << age1[i] << endl;
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {

			if (age2[j] > age2[j + 1]) {
				string temp1 = names2[j];
				names2[j] = names2[j + 1];
				names2[j + 1] = temp1;

				int temp2 = coutnum2[j];
				coutnum2[j] = coutnum2[j + 1];
				coutnum2[j + 1] = temp2;

				int temp3 = age2[j];
				age2[j] = age2[j + 1];
				age2[j + 1] = temp3;

			}
			else if (age2[j] == age2[j + 1]) {
				if (names2[j] > names2[j + 1]) {
					string temp1 = names2[j];
					names2[j] = names2[j + 1];
					names2[j + 1] = temp1;

					int temp2 = coutnum2[j];
					coutnum2[j] = coutnum2[j + 1];
					coutnum2[j + 1] = temp2;

					int temp3 = age2[j];
					age2[j] = age2[j + 1];
					age2[j + 1] = temp3;

				}

			}


		}
	}
	for (int i = 0; i < n; i++) {
		cout << coutnum2[i] << " " << names2[i] << " " << age2[i] ;
		if (i != n - 1)cout << endl;
	}

}