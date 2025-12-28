/*12-6修改例9-3的Array类模板，在执行[]运算符时，若输入的索引i在有效范围外，抛出out_of_range异常。*/
#include <iostream>
#include <string>
#include "Array.h"
using namespace std;

int main()
{
	Array<int>input(10);
	for (int i = 0; i < 10; i++) {
		input[i] = 1;
	}
	try {
		int num = input[11];
	}
	catch (string a) {
		cout << a;
	}

}
