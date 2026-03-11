/*6-24 基于char*设计一个字符串类MyString,并且聚友构造函数、析构函数、复制构造函数，
重载运算符+、=、+=、[]尽可能的完善它们使之能满足各种需要*/

#include<iostream>
using namespace std;

class MyString {
public:
	MyString() {};

	MyString(const char* str) :str(str) {};

	MyString(MyString &otherstr) {
		str = otherstr.str;
	};

	const char* getstr() {
		return str;
	}

	char* operator+(MyString& otherstr);
	const char* operator=(MyString& otherstr);
	const char* operator+=(MyString& otherstr);
	char operator[](int num);

	~MyString(){}

private:
	const char* str;
};
char* MyString::operator+(MyString& otherstr) {
	char* result = new char[1000]();
	int num1 = 0;
	int num2 = 0;
	while (str[num1] != '\0') {
		result[num1 + num2] = str[num1];
		num1++;
	}
	while (otherstr[num2] != '\0') {
		result[num1 + num2] = otherstr[num2];
		num2++;
	}
	result[num1 + num2] = '\0';
	return result;

}
const char* MyString::operator=(MyString& otherstr) {
	str = otherstr.str;
	return str;
}
const char* MyString::operator+=(MyString& otherstr) {
	char* result = new char[1000]();
	int num1 = 0;
	int num2 = 0;
	while (str[num1] != '\0') {
		result[num1 + num2] = str[num1];
		num1++;
	}
	while (otherstr[num2] != '\0') {
		result[num1 + num2] = otherstr[num2];
		num2++;
	}
	result[num1 + num2] = '\0';
	str = result;
	return str;
}
char MyString::operator[](int num) {
	const char* temp = str;
	temp += num;
	return *temp;
}



int main() {
	MyString input1 = "abcf";
	MyString input2 = "tthu";
	MyString input3 = "GHUAFj";
	MyString input4 = "56481";
	input1 = input2;
	cout << input1 + input2<<endl;
	cout << (input2 += input3)<<endl;
	cout << (input2 += input4)<<endl;
	cout << input2+input2<<endl;
	cout << input1.getstr();
}