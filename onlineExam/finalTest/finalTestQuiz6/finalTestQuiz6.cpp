/*6. 成绩维护
【问题描述】
给定一已按学号有序（升序）的成绩表，成绩表中包括每个学生的学号（由大写英文字母X和9位数字组成，不含空格，不会出现学号相同的学生）、
姓名（由不含空格的英文字符组成，字符个数不超过20）及成绩（大于等于0且小于等于100的整数），在该成绩表中按照学号查找某学生成绩。
规定若学生学号存在，则姓名也肯定一致。如果学号存在，但成绩与给定的成绩不一致，则更新该学生成绩；
如果某学生学号不存在，则将该学生的信息加到成绩表中，更新后的成绩表仍有序；如果学号成绩都一致，则不作任何修改。
要求：用折半查找算法进行查找，并输出每次折半查找时比较的位置信息。
【输入形式】
先从标准输入读入成绩表中学生的人数（大于等于1，小于等于100），然后分行输入学生的学号、姓名和成绩，
并在最后一行输入待查找的学生的学号、姓名和成绩，学号、姓名和成绩之间都以一个空格分隔。 
【输出形式】
先在一行上输出折半查找时每次比较的位置信息（学生在成绩表中的位置从0开始计数），各位置信息之间以一个空格分隔，
最后一个位置信息后也有一个空格；然后在下一行输出维护操作信息（Found的第一个大写字母F表示找到了学号和成绩都一致的学生；
Update的第一个大写字母U表示找到了学号一致的学生，但成绩不同需要更新；
Insert的第一个大写字母I表示找不到学号一致的学生，需要添加该学生）和位置信息（F和U后的位置信息表示该学生在成绩表中的位置；
I后的位置信息表示插入后该学生在成绩表中的位置），操作字符信息和位置信息之间以一个空格分隔。
【样例输入1】
10
X201501001 liqiang 89
X201502125 wanglei 65
X201502156 zhanghangyang 99
X201505066 qianborui 78
X201506001 songqian 23
X201510023 qizhi 69
X201515002 wanghaiyang 90
X201516089 wanggong 83
X201518056 lichao 45
X201523003 liuxiu 100
X201518056 lichao 45
【样例输出1】
4 7 8 
F 8
【样例说明1】
按照升序输入了10个学生的学号、姓名和成绩，待查找学生的学号为X201518056，第一次折半查找比较的位置为4（位置0和9的中间位置），
X201518056比X201506001大，则继续在位置5和9之间查找；第二次折半查找比较的位置为7，比该位置学号大，则继续在位置8和位置9之间查找；
第三次比较位置为8，找到了学号为X201518056的学生，且成绩也相同，所以输出操作信息F和位置信息8。
【样例输入2】
10
X201501001 liqiang 89
X201502125 wanglei 65
X201502156 zhanghangyang 99
X201505066 qianborui 78
X201506001 songqian 23
X201510023 qizhi 69
X201515002 wanghaiyang 90
X201516089 wanggong 83
X201518056 lichao 45
X201523003 liuxiu 100
X201518056 lichao 65
【样例输出2】
4 7 8 
U 8
【样例说明2】
按照升序输入了10个学生的学号、姓名和成绩，待查找学生的学号为X201518056，经过三次折半查找比较找到了学号为X201518056的学生成绩，但成绩不一致，需要更新，所以输出U和8。
【样例输入3】
10
X201501001 liqiang 89
X201502125 wanglei 65
X201502156 zhanghangyang 99
X201505066 qianborui 78
X201506001 songqian 23
X201510023 qizhi 69
X201515002 wanghaiyang 90
X201516089 wanggong 83
X201518056 lichao 45
X201523003 liuxiu 100
X201506012 sunxu 78
【样例输出3】
4 7 5 
I 5
【样例说明3】
按照升序输入了10个学生的学号、姓名和成绩，待查找学生的学号为X201506012，经过三次折半查找比较后，该学生比位置5的学号小，
所以更新查找的起始和终止范围为5和4，起始范围大于终止范围，查找失败，需要在5位置插入该学生成绩，所以输出I和5。
【评分标准】
该题要求查找更新成绩表，提交的文件名为：find.c
*/
#include <iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

enum state{F,U,I};


void lookingForID(string newID, int newScore,map<int,string >ID,map<int,int>score,int studentNum) {
	int head = studentNum;
	int end = 0;
	while (head>end) {
		if ((head + end) % 2 == 0) {
			if (ID[(head + end) / 2 - 1] > newID) {
				cout << (head + end) / 2 - 1 << " ";
				head = (head + end) / 2;
			}
			else if (ID[(head + end) / 2 - 1] < newID) {
				cout << (head + end) / 2 - 1 << " ";
				end = (head + end) / 2;

			}
			else if (ID[(head + end) / 2 - 1] == newID) {
				cout << (head + end) / 2 - 1 << " ";
				if (score[(head + end) / 2 - 1] == newScore) {
					cout << endl;
					cout << "F" << " " << (head + end) / 2 - 1;
					return;
				}
				else {
					cout << endl;
					cout << "U" << " " << (head + end) / 2 - 1;
					return;
				}
			}
		}
		else {
			if (ID[(head + end+1) / 2 - 1] > newID) {
				cout << (head + end+1) / 2 - 1 << " ";
				head = (head + end) / 2;
			}
			else if (ID[(head + end+1) / 2 - 1] < newID) {
				cout << (head + end+1) / 2 - 1 << " ";
				end = (head + end+1) / 2;

			}
			else if (ID[(head + end+1) / 2 - 1] == newID) {
				cout << (head + end+1) / 2 - 1 << " ";
				if (score[(head + end+1) / 2 - 1] == newScore) {
					cout << endl;
					cout << "F" << " " << (head + end+1) / 2 - 1;
					return;
				}
				else {
					cout << endl;
					cout << "U" << " " << (head + end+1) / 2 - 1;
					return;
				}
			}
		}
	}
	cout << endl;
	cout << "I" << " " << (head + end) / 2 ;
	return ;
}


int main()
{
	int studentNum;
	cin >> studentNum;
	map<int,string>ID;
	map<string, int>name;
	map<int, int>score;
	for (int i = 0; i < studentNum; i++) {
		string tempID,tempName;
		int tempScore;
		cin >> tempID >> tempName >> tempScore;
		ID[i] = tempID;
		name[tempName] = i;
		score[i] = tempScore;
	}
	string newID, newName;
	int newScore;
	cin >> newID >> newName >> newScore;


	lookingForID(newID, newScore, ID, score, studentNum);


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
