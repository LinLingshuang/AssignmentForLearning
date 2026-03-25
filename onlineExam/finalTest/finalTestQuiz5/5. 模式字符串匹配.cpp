/*5. 模式字符串匹配1
【问题描述】
在当前目录下的文件string.in中查找给定的字符串，并将查找到的字符串和行号输出到当前目录下的文件string.out中。要求：
1）从键盘输入给定的字符串，该字符串中只包含大小写字母、数字字符、中括号字符'['和']'，以及字符'^'。字符串的长度不超过20。
2）字符'^'只能出现在中括号内，且只能作为中括号内的第一个字符出现。除了字符'^'，中括号中至少包含一个以上的字母或数字。
3）在给定字符串中，中括号最多出现一次，也可以不出现。若出现中括号，则中括号内的第一字符一定是字符'^'，表示该位置上的字符与中括号内的所有字符都不相同时，匹配成功。
4）查找字符串时大小写无关。
5）先输出查到的行号（行号从1开始），行号后跟冒号':'，然后是查找到的字符串，多个字符串之间用逗号','隔开。各行之间用一个回车换行符隔开。
【输入形式】
首先从标准输入（键盘）读入一个字符串
从string.in文件中查找该字符串。注意：文件末尾行后可能有回车换行符，也可能没有回车换行符。
【输出形式】
将查找到的结果输出到文件string.out中。
【样例输入1】
键盘输入的字符串为：
zh[^ae]ng
假设string.in的内容为：
Zhing ying ju zhu zai ZhongGuo. 
Ta zheng zai du gao zhong.
Bie ren dou jia ta xiao zhang.
【样例输出1】
string.out的内容为：
1:Zhing,Zhong
2:zhong
【样例1说明】
给定字符串中有中括号，表示第三个字符不能是a也不能是e，且大小写无关，因此string.in文件中第一行的Zhing和Zhong与给定字符串匹配，故输出1:Zhing,Zhong。其它类推。
【样例输入2】
键盘输入的字符串为：
a[^ab]a
假设string.in的内容为：
Do you like banana?
ABA is the abbreviation of American Bankers Association.
【样例输出2】
string.out的内容为：
1:ana,ana
【样例2说明】
给定字符串有中括号，表示第一个和第三个字符都为a，第二个字符不能为a或b，因此string.in文件中第一行的banana内有两个字符串ana与给定字符串匹配，
故输出1:ana,ana。第二行中ABA的第二个字符为B，由于大小写无关，与给定字符串中括号内的b相同，故不能匹配。
算法提示：
1、因为字符串匹配时要求大小写无关，所以可以写一函数判断两个字符是否大小写无关相同；
2、对于给定的待查找字符串，可用一个数组A保存中括号之外的字符，中括号出现的位置用一个特殊字符（例如'?'）替代；用另一个数组B保存中括号中除'^'之外的字符；
3、可写一函数判断某个字符是否出现在数组B中；

【评分标准】

共有5个测试点。 */

#include <iostream>
#include<vector>
#include<string>
#include<fstream>
#include<map>
#include<cctype>
using namespace std;

bool wordHavePair(string word,string needPair,string needIgnore) {
	int i = 0;
	for (char c : needPair) {
		if (c == '?') {
			for (char ignore : needIgnore) {
				if (toupper(word[i]) == toupper(ignore)) {
					return false;
				}
			}
			i++;
			continue;
		}
		if (toupper(word[i]) !=toupper(c)) {
			return false;
		}
		i++;
	}
	return true;
}



int main()
{
	string orignStr;
	cin >> orignStr;

	string needPair;
	string needIgnore;
	bool inMiddleBracket = false;

	for (char c : orignStr) {
		if (c == '[') {
			inMiddleBracket = true;
			needPair.push_back('?');
			continue;
		}
		else if (c == ']') {
			inMiddleBracket = false;
			continue;
		}
		if (!inMiddleBracket) {
			needPair.push_back(c);
		}
		else if (c != '^') {
			needIgnore.push_back(c);
		}

	}

	map<int, vector<string>>result;

	ifstream in;
	in.open("string.in");

	string line;
	int lineNum = 1;
	while (getline(in, line)) {
		string word;
		for (int i = 0; i <= line.length()-needPair.length(); i++) {
			for (int j = i; j < i + needPair.length(); j++) {
				if (line[j] != '.' && line[j] != ',' && line[j] != ';' && line[j] != ':' && 
					line[j] != '?' && line[j] != '!' && line[j] != '\"' && line[j] != '\''&&line[j] != ' ') {
					word.push_back(line[j]);
				}
				else {
					word.clear();
					break;
				}
			}
			if (word.length() == needPair.length()) {
				if (wordHavePair(word, needPair,needIgnore)) {
					result[lineNum].push_back(word);
					word.clear();
				}
				word.clear();
			}
			word.clear();
		}
		lineNum++;
	}
	in.close();

	ofstream out;
	out.open("string.out");

	for (auto iter1 : result) {
		cout << iter1.first << ':';
		out << iter1.first << ':';
		bool isFirst = true;
		for (auto iter2 : iter1.second) {
			if (!isFirst) {
				cout << ',';
				out << ',';
			}
			cout << iter2;
			out << iter2;
			isFirst = false;
		}
		cout << endl;
		out << endl;
	}

	out.close();

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
