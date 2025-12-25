/*1. hw-7: 指针&&引用（补全程序）
【问题描述】
功能描述：现有一个字符串str和三个替换字符forUpper、forLower、forNum。
编写replaceFirstChars()函数，接受这四者作为参数，扫描传入的字符串，
将其第一个大写字母与forUpper交换，第一个小写字母与forLower交换，第一个数字与forNum交换。
相关程序如下（附件：*/
/*【输入形式】

程序内 main() 函数。（ps. 这部分请不要随意改动）
【输出形式】

参考样例输出
【样例输入】

无
【样例输出】

image.png

(ps. 仅供参考，不要使用文字识别“逃课”😾！)*/
#include <iostream>
using namespace std;

void replaceFirstChars(char* arr, char* forUpper1 ,char* forLower1,char* forNum1 /*接下来三个参数用指针传递*/) {
	// todo 请填写程序
	// please fill in the program
	bool upperreplace = false, lopwerreplace = false, numreplace = false;
	
	while (*arr != '\0') {
		if (!upperreplace && isupper(*arr)) {
			char temp = *arr;
			*arr = *forUpper1;
			*forUpper1 = temp;
			upperreplace = true;
		}
		else if (!lopwerreplace && islower(*arr)) {
			char temp = *arr;
			*arr = *forLower1;
			*forLower1 = temp;
			lopwerreplace = true;
		}
		else if (!numreplace && isdigit(*arr)) {
			char temp = *arr;
			*arr = *forNum1;
			*forNum1 = temp;
			numreplace = true;
		}
		arr++;
	}


}

void replaceFirstChars(char arr[], char &forUpper1 , char &forLower1 , char &forNum1/*接下来三个参数用引用传递*/) {
	// todo 请填写程序
	// please fill in the program
	bool upperreplace=false, lopwerreplace=false, numreplace=false;

	for (int i = 0; i < sizeof(arr)*4 ; i++) {
		if (!upperreplace && isupper(arr[i])) {
			char temp = arr[i];
			arr[i] = forUpper1;
			forUpper1 = temp;
			upperreplace = true;
		}
		else if (!lopwerreplace && islower(arr[i])) {
			char temp = arr[i];
			arr[i] = forLower1;
			forLower1 = temp;
			lopwerreplace = true;
		}
		else if (!numreplace && isdigit(arr[i])) {
			char temp = arr[i];
			arr[i] = forNum1;
			forNum1 = temp;
			numreplace = true;
		}
	}


}

int main() {
	char str1[] = "*** The 1st sentence for replacement ***";
	char str2[] = "*** 2nd Sentence ***";

	char forUpper1 = '+', forLower1 = '-', forNum1 = '#';
	cout << "Sentence before replacement: " << str1 << endl;
	// todo 请在此处调用 replaceFirstChars() 函数的指针版本
	// Please call the pointer version of the replaceFirstChars() function here

	replaceFirstChars(str1, &forUpper1, &forLower1, &forNum1);

	cout << "Sentence after replacement:  " << str1 << endl
		<< "First Uppercase: " << forUpper1 << endl
		<< "First Lowercase: " << forLower1 << endl
		<< "First Number: " << forNum1 << endl
		<< endl;

	char forUpper2 = '+', forLower2 = '-', forNum2 = '#';
	cout << "Sentence before replacement: " << str2 << endl;
	// todo 请在此处调用 replaceFirstChars() 函数的引用版本
	// Please call the reference version of the replaceFirstChars() function here

	replaceFirstChars(str2, forUpper2, forLower2, forNum2);

	cout << "Sentence after replacement:  " << str2 << endl
		<< "First Uppercase: " << forUpper2 << endl
		<< "First Lowercase: " << forLower2 << endl
		<< "First Number: " << forNum2 << endl;
	return 0;
}