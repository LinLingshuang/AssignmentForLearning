#include<iostream>
using namespace std;

class MyString
{
public:
	MyString() {
		c[0] = '\0';
	}
	void exchangeWith(MyString&);
	int compareTo(MyString&);
	void setString(char[]);
	char* getString() {
		return c;
	}
	static const int CAPACITY = 64;

private:
	char c[CAPACITY];
};
void MyString::exchangeWith(MyString &otherString)
{

	char temp[CAPACITY];
	for (int i = 0; i < CAPACITY; i++) {
		temp[i] = c[i];
	}
	for (int i = 0; i < CAPACITY; i++) {
		 c[i]= otherString.c[i];
	}
	for (int i = 0; i < CAPACITY; i++) {
		otherString.c[i]=temp[i];
	}
}

int MyString::compareTo(MyString &otherString)
{
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
	int length = sizeof s;

	for (int i = 0; i < length; i++) {

		c[i] = s[i];

	}



}


int main() {
	MyString test1;
	MyString test2;
	char a[] = "abcdef";
	char b[] = "abcd";
	test1.setString(a);
	test2.setString(b);

	cout << test1.getString() << endl << test2.getString()<<endl;

	cout<<test1.compareTo(test2)<<endl;


	test1.exchangeWith(test2);

	cout << test1.getString() << endl << test2.getString() << endl;



}