/*6-21 编写一个函数，统计一条英文句子中字母的个数，在主程序中实现输入输出*/
#include<iostream>
using namespace std;

int SumSentenceAlphaNum(char*input) {
	int sum = 0;
	for (int j = 0; input[j]!='\0'; j++) {
		if (isalpha(input[j])) {
			sum++;
		}
	}
	return sum;
}


int main() {
	char* input = new char[1000];
	char proccess;
	int i = 0;
	do { cin >> proccess;
	input[i] = proccess;
	i++;
	} while (proccess != '.'&& proccess != '!'&& proccess != '?');
	
	input[i] = '\0';

	cout << SumSentenceAlphaNum(input);

	delete[] input;
	return 0;
}