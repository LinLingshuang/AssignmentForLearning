/*12-4 设计一个异常抽象类Exception，在此基础上派生出一个OutMemory类响应内存不足，
一个RangeError类响应输入的数不在指定范围内，实现并检测这两个类*/
#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Exception {
public:

	virtual void check(string* a) = 0;

private:

};

class OurMemory:public Exception {
public:
	OurMemory(const string message):memoryMessage(message){}

	void check(string* a) {
		int i = 0;
		do {
			if (i == 4) {
				cout << endl;
				throw OurMemory("输入了超过3个数字！内存泄露！");
				return;
			}
			cin >> a[i];
			i++;
			
		} while (a[i - 1] != "end");
		cout << endl;
		return;
	}

	string getMessage() { return memoryMessage; }

private:

	string memoryMessage;

};

class RangeError :public Exception {
public:
	RangeError(const string &message):rangeMessage(message){}

	void check(string* a) {
	
		for (int i = 0; i < 3; i++) {
			if (a[i][0] == '-') {
				throw RangeError("输入了小于0的数！");
				return;
			}
			else if (a[i].length() >= 4) {
				throw RangeError("输入了大于100的数！且大于等于1000！");
				return;
			}
			else if (a[i].length() == 3 && a[i] != "100") {
				throw RangeError("输入了大于100的数！且小于1000！");
				return;
			}

		}

		return;
	}

	string getMessage() { return rangeMessage; }

private:

	string rangeMessage;

};



int main()
{
	cout << "输入三个个实数a1、a2、a3，0<=ai<=100，如果输入超过三个数内存会泄露,输入字符串end表示输入结束" << endl;
	cout << "请输入：";
	try {
		string* input=new string[4];

		OurMemory checkingMemory("No error");

		RangeError checkingRange("No error");

		checkingMemory.check(input);

		checkingRange.check(input);

		cout << "一切正常！" << endl;

		for (int i = 0; i < 3; i++) {
			cout << "输入的第" << i + 1 << "个数字是" << input[i] << endl;
		}

		delete[] input;

	}
	catch (OurMemory &om) {
		cout << "收到内存异常：" << om.getMessage() << endl;
	}
	catch (RangeError& re) {
		cout << "收到范围异常：" << re.getMessage() << endl;
	}
	
}