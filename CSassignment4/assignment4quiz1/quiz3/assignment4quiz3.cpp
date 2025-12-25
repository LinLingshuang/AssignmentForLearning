/*从键盘输入两个字符串A和B（每个字符串内都无重复字符）。求两个字符串的差集，
即：将字符串A中与字符串B中相同的字符去掉（大小写无关，即同一字符的大小写认为是相同的字符）。
然后按照ASCII码从小到大的顺序输出差集。若差集为空，则输出字符串：NULL。

【输入形式】
先从键盘输入字符串A，然后输入字符串B，每个字符串末尾都有回车换行符，
但回车换行符不作为字符串的字符，并且每个字符串不超过50个字符。提示：输入整行数据可以使用gets()函数，使用方法自行搜索。
【输出形式】
按照ASCII码从小到大的顺序输出字符串A减去字符串B的差集。
【输入样例1】
Ni Hao,Lu!
hi wang!
【输出样例1】
,Lou
【输入样例2】
A
a
【输出样例2】
NULL
【样例说明】
输入的字符串A为"Ni Hao,Lu!"，字符串B为"hi wang!"。
字符串A中与字符串B相同的字符（大小写无关）有六个："N","i","H","a","!"以及空格符，将这六个字符从A中去掉，按照ASCII码从小到大的顺序输出为：,Lou。*/

#include<iostream>
#include<string>
using namespace std;

int main() {
	string A;
	string B;
	getline(cin, A);
	getline(cin, B);
	
	string result;
	
	for (char a : A) {
		bool notdelate = true;
		for (char b : B) {
			if (toupper(a) == toupper(b)) {
				notdelate = false;
			}
		}
		if (notdelate) {
			result += a;
		}
	}
	if (result.length() == 0) {
		cout << "NULL";
	}
	else {
		for (int i = 0; i < result.length(); i++) {
			for (int j = 0; j < result.length() - 1; j++) {
				if (result[j] > result[j + 1]) {
					char tmep = result[j];
					result[j] = result[j + 1];
					result[j + 1] = tmep;
				}
			}
		}
		cout << result;
	}
}