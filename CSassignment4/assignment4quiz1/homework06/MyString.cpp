#include "MyString.h"
#include <string.h>
// 要求：把本对象和otherString对象的c数组内容交换
// Requirement: Swap the content of the c arrays between this object and the otherString object.
void MyString::exchangeWith(MyString &otherString)
{
	// todo 请填写程序
	// Please implement the program.
	char temp[CAPACITY];
	for (int i = 0; i < CAPACITY; i++) {
		temp[i] = c[i];
	}
	for (int i = 0; i < CAPACITY; i++) {
		c[i] = otherString.c[i];
	}
	for (int i = 0; i < CAPACITY; i++) {
		otherString.c[i] = temp[i];
	}

}

//要求：把本对象和otherString对象的c数组逐字符比较
//1）比较规则同英文词典排序规则
//2）如果本对象字符串应排在otherString的前面，则返回一负数
//3）如果本对象字符串应排在otherString的后面，则返回一正数
//4）如果两个字符串完全相同，则返回0
//注意：字符串以'\0'结尾，"Jack"应排在"Jackson"前面
// Requirement: Compare the content of the c arrays between this object and the otherString object.
// 1) The comparison rules are the same as the English dictionary sorting rules.
// 2) If the string of this object should be placed before the otherString, return a negative number.
// 3) If the string of this object should be placed after the otherString, return a positive number.
// 4) If two strings are the same, return 0.
// Note: The string ends with '\0', "Jack" should be placed before
int MyString::compareTo(MyString &otherString)
{
	// todo 请填写程序
	// Please implement the program.
	int length1 = sizeof c;
	int length2 = sizeof otherString.c;

	if (length1 < length2) {
		for (int i = 0; i < length1; i++) {
			if (c[i] < otherString.c[i]) {
				return -1;
			}
			else if (c[i] > otherString.c[i]) {
				return 1;
			}
		}
		return -1;
	}
	else if (length1 > length2) {
		for (int i = 0; i < length2; i++) {
			if (c[i] < otherString.c[i]) {
				return -1;
			}
			else if (c[i] > otherString.c[i]) {
				return 1;
			}
		}
		return 1;
	}
	else {
		for (int i = 0; i < length1; i++) {
			if (c[i] < otherString.c[i]) {
				return -1;
			}
			else if (c[i] > otherString.c[i]) {
				return 1;
			}
		}
		return 0;
	}



}

// 要求：把s中的字符逐个复制到本对象的c数组
// 注意：字符串以'\0'结尾，复制到'\0'即可停止
// Requirement: Copy each character from s to the c array of this object.
// Note: Strings are null-terminated. Stop copying when '\0' is encountered.
void MyString::setString(char s[])
{
	// todo 请填写程序
	// Please implement the program.
	int length = strlen(s);

	for (int i = 0; i < length; i++) {

		c[i] = s[i];
		
	}

	c[length] = '\0';

}
